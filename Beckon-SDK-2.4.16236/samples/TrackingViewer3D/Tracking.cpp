/******************************************************************************/
/*                              Includes                                      */
/******************************************************************************/

#include <iostream>
#include <string>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "Tracking.h"

using namespace std;
using namespace Omek;

/******************************************************************************/
/*                               Globals                                      */
/******************************************************************************/
/// Maximal number of players to be tracked
const unsigned int MAX_NUM_OF_PLAYERS 	= 1;
const unsigned int MAX_FRAMES_TO_RECORD = 500;

/******************************************************************************/
/*                               Class implementation                         */
/******************************************************************************/

Tracking::Tracking() :
	m_pSensor(NULL),
	m_pSkeleton(NULL),
	m_isRecording(false)
{}

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
}

bool Tracking::updateFrame()
{

	ISensor* sensor = m_pSensor->getSensor();

	// Run the main loop as long as there are frames to process
	if (sensor->isAlive())
	{
		// Handle the current frame only if we have successfully processed a new image
		bool bHasNewImage = false;
		// Processes the new input frame (if available) and executes the tracking algorithm
		if(m_pSensor->processNextImage(true, bHasNewImage) == OMK_SUCCESS && bHasNewImage)
			// Copy the output raw skeleton into the given skeleton data structure.
			m_pSensor->getSkeleton(m_pSkeleton);

		return true;
	}
	else
	{
		cout << "processed " << sensor->getFramenum() << "." << endl;
		return false;
	}
}

bool Tracking::initialize(char* sequenceFileName)
{
	// Create the sensor
	if (sequenceFileName == NULL)
		// Create live camera sensor
		m_pSensor = IMotionSensor::createCameraSensor();
	else
		// Create a sequence file sensor (file containing sequence of recorded depth data frames)
		m_pSensor = IMotionSensor::createSequenceSensor(sequenceFileName);

	if(m_pSensor == NULL)
	{
		cerr << "Error creating sensor." << endl;
		return false;
	}

	// Enable skeleton tracking
	if(m_pSensor->setTrackingOptions(TRACK_ALL) != OMK_SUCCESS)
	{
		cerr << "Error initializing the tracking algorithm." << endl;
		return false;
	}

	// Setting the maximal number of players (currently the SDK for BB supports only 1)
	if(m_pSensor->setMaxCandidates(MAX_NUM_OF_PLAYERS) != OMK_SUCCESS)
	{
		cerr << " Error setting maximal number of candidates." << endl;
		return false;
	}

	if(m_pSensor->setMaxPlayers(MAX_NUM_OF_PLAYERS) != OMK_SUCCESS)
	{
		cerr << "Error setting maximal number of players." << endl;
		return false;
	}

	// Allocate empty Skeleton, to receive output data from the
	// tracking algorithm.
	m_pSkeleton = m_pSensor->createSkeleton();

	if(m_pSkeleton == NULL)
	{
		cerr << "createSkeleton() failed." << endl;
		return false;
	}
	
	// Disable the RGB input (not supported on the BeagleBoard).
    ISensor* sensor = m_pSensor->getSensor();
    sensor->setCameraParameter("enableRGB", 0);
    
	return true;
}


ISkeleton* Tracking::getSkeleton()
{
	return m_pSkeleton;
}

void Tracking::toggleRecording()
{
	if(!m_pSensor)
	{
		cerr << "Censor is not initialized!" << endl;
		return;
	}

	if(!m_isRecording)
	{
		// get current time stamp to create unique folder name
		time_t rawtime;
		tm * timeinfo;
		time ( &rawtime );
		timeinfo = localtime ( &rawtime );
		
		// Create new directory for the future recorded sequences.
		// (We create a new directory for every sequence, because SDK
		// requires a directory (which contains an actual sequence file) path
		// when running tracking from a sequence input.)
		char dirName[50];
		sprintf(dirName, "seq-%d.%d.%d-%d.%d.%d",   
			timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 
			timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
		int res = mkdir(dirName ,0777);
		if(res == -1)
		{
			cerr << "Failed to create directory " << dirName << endl;
			return;
		}
				
		// Add to the directory the seq file name.
		string seqPath(dirName);
		seqPath += "/seq.oni";

		// start recording
		OMKStatus status = m_pSensor->recordSequence(seqPath.c_str(), MAX_FRAMES_TO_RECORD);
		if(status != OMK_SUCCESS)
		{
			cerr << "Failed to record sequence: " << status << endl;
			return;
		}
			
		cout << "Start recording: " << dirName << endl;
		m_isRecording = true;
	}
	else
	{
		// stop recrding
		m_pSensor->stopRecording();
		cout << "Stop recording" << endl;
		m_isRecording = false;
	}

}



/******************************************************************************/
/*                                EOF                                         */
/******************************************************************************/
