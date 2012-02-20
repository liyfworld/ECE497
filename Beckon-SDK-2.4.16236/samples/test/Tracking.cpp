#include <iostream>
#include <sstream>

#include "Tracking.h"
#include <QString>
#include <QStringList>
#include <QDateTime>
#include <QDir>

using namespace std;
using namespace Omek;

// Maximal number of players to be tracked
// (note the SDK BeagleBoard version supports only 1
// tracked player)
const unsigned int MAX_NUM_OF_PLAYERS = 1;

// Specifies the maximum number of frames can
// be recorded for one sequence.
const unsigned int MAX_FRAMES_TO_RECORD = 500;



Tracking::Tracking(QObject *parent) :
    QObject(parent),
    m_maskBuffer(NULL),
    m_depthBuffer(NULL),
    m_pSensor(NULL),
    m_pSkeleton(NULL),
    m_imageWidth(0),
    m_imageHeight(0)
{
}

Tracking::~Tracking()
{
	if(m_pSkeleton != NULL)
	{
		if(m_pSensor->releaseSkeleton(m_pSkeleton) != OMK_SUCCESS)
		{
			cerr << "Failed releasing skeleton." << endl;
		}
		m_pSkeleton = NULL;
	}

	if (m_pSensor != NULL)
	{
		IMotionSensor::releaseMotionSensor(m_pSensor);
		m_pSensor = NULL;
	}

	if(m_maskBuffer)
	{
        delete[] m_maskBuffer;
		m_maskBuffer = NULL;
	}

	if(m_depthBuffer)
	{
        delete[] m_depthBuffer;
		m_depthBuffer = NULL;
	}
}

void Tracking::updateFrame()
{

    ISensor* sensor = m_pSensor->getSensor();

    // run the main loop as long as there are frames to process
    if (sensor->isAlive())
    {
        bool bHasNewImage;

		// Processes the new input frame (if available) and executes the tracking algorithm
        if(m_pSensor->processNextImage(true, bHasNewImage) == OMK_ERROR_ASSERTION_FAILURE)
            emit shutdown();

        int width_step;

        // Copy the input depth image (if available) into the given buffer.
		// (Note - the depth data represented by signed short per pixel)
		int depthImageBufferSize = m_imageWidth*m_imageHeight*sizeof(uint16_t);
        if(m_pSensor->copyRawImage((char*)m_depthBuffer , 
									depthImageBufferSize, 
									width_step, false) == OMK_SUCCESS)
        {
            emit updateDepthImage(m_depthBuffer);
        }
		
		// the label of the player (only one exists)
        int label = 0; 
		// the dimensions of the player's bounding rectangle
        int width = 0, height = 0;
		// the player blob's 3D center of mass in world space (cm)
        float center3D[3]; 
		// the player blob's 2D center of mass in local image space (pixels)
        float center2D[2]; 

        // do we have a players mask
		int playerMaskBufferSize = m_imageWidth*m_imageHeight;
		// Copy the player mask into the given buffer.
		// (Note - the mask data is represented by char per pixel (255-player present/0-background))
        if(m_pSensor->copyPlayerMask(	(char*)m_maskBuffer, 
										playerMaskBufferSize, 
										label, width, height, 
										center3D, center2D) == OMK_SUCCESS)
        {
            // Copy the output raw skeleton into the given skeleton data structure.
            if(m_pSensor->getRawSkeleton(m_pSkeleton) == OMK_SUCCESS)
            {
                if(m_pSkeleton != NULL)
                {
					// Run over all the joints in Skeleton and get their
					// positions in image space. 
                    for(unsigned int i=0; i < SHADOW_JOINTS_NUM; i++)
                    {
                        JointID id = (JointID)i;
						// Check whether the joint is available (tracked)
						// in the current frame.
                        if(m_pSkeleton->containsJoint(id))
                        {
                            float pos[3];
							// Get the tracked joint position in the image space
							// (ignore the z-coordinate) to draw them on the
							// mask image (right application window) as cross marks.
                            m_pSkeleton->getJointPosition(id, pos, false);
                            unsigned int x,y;
                            x = (unsigned int)pos[0];
                            y = (unsigned int)pos[1];
							// offset from the image border to be taken when drawing markers,
							// because of their size
							const unsigned int imageBorderOffset = 2;
                            if(	(x >= imageBorderOffset) 			   && 
								(y >= imageBorderOffset) 			   && 
								(x < (m_imageWidth-imageBorderOffset)) && 
								(y < (m_imageHeight-imageBorderOffset))  ) 
							{
								// JointID_rightHip and JointID_leftHip joints are not valid 
								// in the raw skeleton.
                                if((id!=JointID_rightHip) && (id!=JointID_leftHip))
									// Send the joint image coordinates to the TrackingWindow.
                                    emit addPoint(x, y, id);
                                
                            }
                        }//<=if(m_pSkeleton->containsJoint(id))
                    }//<=for(.. i < SHADOW_JOINTS_NUM ..)
                }//<=if(m_pSkeleton != NULL)
            }//<=if(m_pSensor->getRawSkeleton..)
            m_isTracking = true;
            emit updateMaskImage(m_maskBuffer);
        }//<=if(m_pSensor->copyPlayerMask..)
        else
        {
            if(m_isTracking)
            {
                memset(m_maskBuffer, 0, m_imageWidth*m_imageHeight);
                emit updateMaskImage(m_maskBuffer);
                m_isTracking = false;
            }
        }
    }//<=if(sensor->isAlive())
    else
    {
        cout << "processed " << sensor->getFramenum() << "." << endl;
        emit shutdown();
    }
}

void Tracking::recordOrStop(bool state)
{
    if(!m_pSensor)
    {
        cerr << "Censor is not initialized!" << endl;
        return;
    }

    if(state)
    {
        // get current time stamp to create unique folder name
        QString time =
            QDateTime::currentDateTime().toString("dd.MM.yy-hh.mm.ss");

        // Create new directory for the future recorded sequences.
        // (We create a new directory for every sequence, because SDK
        // requires a directory (which contains an actual sequence file) path
        // when running tracking from a sequence input.)
        QString dirName("seq-");
        dirName += time;
        QDir().mkdir(dirName);

        // Add to the directory the seq file name.
        string seqPath = dirName.toStdString();
        seqPath += "/seq.oni";

        // start recording
        m_pSensor->recordSequence(seqPath.c_str(), MAX_FRAMES_TO_RECORD);
    }
    else
        // stop recrding
        m_pSensor->stopRecording();

}


int Tracking::initialize(char* sequenceFileName)
{
    m_isTracking = true;

	// create the sensor
	if (sequenceFileName == NULL)
		// create live camera sensor
		m_pSensor = IMotionSensor::createCameraSensor();
	else
		// create a sequence file sensor (file containing sequence of recorded depth data frames)
		m_pSensor = IMotionSensor::createSequenceSensor(sequenceFileName);

	if(m_pSensor == NULL)
	{
		cerr << "Error creating sensor." << endl;
		return 1;
	}

	// enable skeleton tracking
    if(m_pSensor->setTrackingOptions(TRACK_ALL) != OMK_SUCCESS)
	{
		cerr << "Error initializing the tracking algorithm." << endl;
		return 1;
	}

	// setting the maximal number of players (currently supported maximum 1 on BeagleBoard)
	if(m_pSensor->setMaxCandidates(MAX_NUM_OF_PLAYERS) != OMK_SUCCESS)
	{
		cerr << " Error setting maximal number of candidates." << endl;
		return 1;
	}

	if(m_pSensor->setMaxPlayers(MAX_NUM_OF_PLAYERS) != OMK_SUCCESS)
	{
		cerr << "Error setting maximal number of players." << endl;
		return 1;
	}

	// Allocate empty Skeleton, to receive output data from the
	// tracking algorithm.
	m_pSkeleton = m_pSensor->createSkeleton();

	if(m_pSkeleton == NULL)
	{
		cerr << "NULL Skeleton !!!" << endl;
		return 1;
	}

	// Disable the RGB input (not supported on the BeagleBoard).
    ISensor* sensor = m_pSensor->getSensor();
    sensor->setCameraParameter("enableRGB", 0);
	
    m_imageWidth = sensor->getImageWidth(IMAGE_TYPE_DEPTH);
    m_imageHeight = sensor->getImageHeight(IMAGE_TYPE_DEPTH);

    m_maskBuffer = new unsigned char[m_imageWidth*m_imageHeight];
    m_depthBuffer = new unsigned char[m_imageWidth*m_imageHeight*sizeof(uint16_t)];

    memset(m_maskBuffer, 0, m_imageWidth*m_imageHeight);
    memset(m_depthBuffer, 0, m_imageWidth*m_imageHeight*sizeof(uint16_t));

	cout << "Tracking successfully initialized." << endl;
	return 0;
}

int Tracking::getImageWidth()
{
    return m_imageWidth;
}

int Tracking::getImageHeight()
{
    return m_imageHeight;
}
