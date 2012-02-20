#include <iostream>
#include <sstream>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include "Tracking.h"
#include "Shadow/ISensor.h"
#include "Shadow/IMotionSensor.h"

using namespace std;
using namespace Omek;

// maximum number of gestures
static const int TOTAL_NUMBER_OF_SUPPORTED_GESTURES = 6;

/// Maximal number of players to be tracked
const int MAX_NUM_OF_PLAYERS = 1;
/// The instance of our sensor (SDK interface)

static int g_run_gestures = 1;

static struct termios oldt;

// default behavior for key input is to wait for an Enter key
// we don't want that.
void disable_waiting_for_enter(void)
{
    struct termios newt;

    /* Make terminal read 1 char at a time */
    tcgetattr(0, &oldt);  /* Save terminal settings */
    newt = oldt;  /* Init new settings */
    newt.c_lflag &= ~(ICANON | ECHO);  /* Change settings */
    tcsetattr(0, TCSANOW, &newt);  /* Apply settings */
    //atexit(restore_terminal_settings); /* Make sure settings will be restored when program ends  */
}

// restore to default behavior (wait for Enter)
void restore_terminal_settings(void)
{
    tcsetattr(0, TCSANOW, &oldt);  /* Apply saved settings */
}

int fuckmain(void)
{
	int numberOfGestures = 0;
	int ret = 0;

	// camera interface
	ISensor* sensor = NULL;

	// Omek API interface
	IMotionSensor *pSensor = NULL;

	// we want to read the input without waiting... (for the exit key)
	int n, tem;
	tem = fcntl(0, F_GETFL, 0);
	fcntl (0, F_SETFL, (tem | O_NDELAY));

	disable_waiting_for_enter();

	char* sequencePath = NULL;

        for(int i=1; i < 2; i++)
	{
                if(strcmp("-gest", "-help") == 0)
		{
                        cout << "Usage: " << " [-seq sequence-path] [-gest gesture name] [-gest...\n";
			goto end;
		}


                if(strcmp("-gest", "-gest") == 0)
		{
			if(numberOfGestures >= TOTAL_NUMBER_OF_SUPPORTED_GESTURES)
			{
				cerr << "Error: currently we support only " << TOTAL_NUMBER_OF_SUPPORTED_GESTURES << " gestures." << endl;
				ret = 1;
				goto end;
			}


		}
	}



	// create the sensor
	if (sequencePath)
	{
		// from a sequence
		pSensor = IMotionSensor::createSequenceSensor(sequencePath);
	}
	else
	{
		// from a cameras
		pSensor = IMotionSensor::createCameraSensor(true);
	}

	if(pSensor == NULL)
	{
		cerr << "Error, failed creating sensor." << endl;
		ret = 1;
		goto end;
	}



	// initialize the tracking algorithm
	if(pSensor->setTrackingOptions(TRACK_ALL) != OMK_SUCCESS)
	{
		cerr << "Error, failed to set tracking options." << endl;
		ret = 1;
		goto end;
	}

	sensor = pSensor->getSensor();

	if(sensor == NULL)
	{
		cerr << "Error, failed to get sensor." << endl;
		ret = 1;
		goto end;
	}

	// disable the RGB input (not supported on the BeagleBoard)
	pSensor->getSensor()->setCameraParameter("enableRGB", 0);

	// enable the selected gestures
        numberOfGestures=1;
	for(int i = 0 ; i < numberOfGestures; i++)
	{
                if(pSensor->enableGesture("_rightScrollRight") != OMK_SUCCESS)
		{
                        cerr << "Error, unrecognized gesture: " << "_rightScrollRight" << endl;
			ret = 1;
			goto end;
		}
	}

	// setting the maximal number of players
	if(pSensor->setMaxPlayers(MAX_NUM_OF_PLAYERS) != OMK_SUCCESS)
	{
		cerr << "Error, failed to set maximal number of players." << endl;
		ret = 1;
		goto end;
	}

	cout << "Please press ESC to stop." << endl;

	{
		uint32_t processedFrames = 0;

		// run the main loop as long as there are frames to process
		while (sensor->isAlive() && g_run_gestures)
		{
			// Handle the current frame only if we have successfully processed a new image
			bool bHasNewImage = false;
			if ((pSensor->processNextImage(true, bHasNewImage) == OMK_SUCCESS) && bHasNewImage)
			{
				processedFrames++;
				while (pSensor->hasMoreGestures())
				{
					const IFiredEvent* pFiredEvent = pFiredEvent = pSensor->popNextGesture();
					std::stringstream text;
					text << endl << "Gesture (" << (pFiredEvent->getName()!=NULL?pFiredEvent->getName():"") << ") fired in frame " << processedFrames;
					cout << text.str().c_str() << endl;
					pSensor->releaseGesture(pFiredEvent);
                                        g_run_gestures = 0;
				}
			}

//			char c;
//			n = read(0, &c, 1);
//			if (n > 0)
//				if(c == 0x1B)
//					g_run_gestures = 0;
		}

		cout << processedFrames << " frames." << endl;
	}
	end:

	// cleanup
	if (pSensor != NULL)
	{
		IMotionSensor::releaseMotionSensor(pSensor);
		pSensor = NULL;
	}

	fcntl(0, F_SETFL, tem);
	restore_terminal_settings();
	return ret;
}
