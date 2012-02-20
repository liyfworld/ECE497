#include <QtGui/QApplication>
#include "mainwindow.h"
#include <iostream>
#include <sstream>
#include <signal.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include "mainwindow.h"
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


#if defined(Q_WS_QWS)
// for Qt Embedded (e.g., Ben NanoNote)
#include <QtGui/QWSServer>
#endif


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

int main(int argc, char* argv[])
{
        char * gesturesList[TOTAL_NUMBER_OF_SUPPORTED_GESTURES] = {NULL};
        int numberOfGestures = 0;
        int ret = 0;



        // we want to read the input without waiting... (for the exit key)
        int n, tem;
        tem = fcntl(0, F_GETFL, 0);
        fcntl (0, F_SETFL, (tem | O_NDELAY));

        disable_waiting_for_enter();

        char* sequencePath = NULL;

        for(int i=1; i < argc; i++)
        {
                if(strcmp(argv[i], "-help") == 0)
                {
                        cout << "Usage: " << argv[0] << " [-seq sequence-path] [-gest gesture name] [-gest...\n";
                        goto end;
                }

                if(strcmp(argv[i], "-seq") == 0)
                {
                        sequencePath = argv[i+1];
                        cout << "reading a sequence from: " << sequencePath << endl;
                }

                if(strcmp(argv[i], "-gest") == 0)
                {
                        if(numberOfGestures >= TOTAL_NUMBER_OF_SUPPORTED_GESTURES)
                        {
                                cerr << "Error: currently we support only " << TOTAL_NUMBER_OF_SUPPORTED_GESTURES << " gestures." << endl;
                                ret = 1;
                                goto end;
                        }

                        gesturesList[numberOfGestures++] = argv[i+1];
                }
        }


        if(numberOfGestures == 0)
        {
                cerr << "Error, please provide at least one gesture." << endl;
                ret = 1;
                goto end;
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
        for(int i = 0 ; i < numberOfGestures; i++)
        {
                if(pSensor->enableGesture(gesturesList[i]) != OMK_SUCCESS)
                {
                        cerr << "Error, unrecognized gesture: " << gesturesList[i] << endl;
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

                            // check fired gestures
                            while (pSensor->hasMoreGestures())
                            {

                                    QApplication a(argc, argv);
                                         QCoreApplication::setOrganizationName("Mark Harman");
                                         QCoreApplication::setApplicationName("QBall");
                                         MainWindow w;
                                     #if defined(Q_WS_S60)
                                         //w.showMaximized();
                                         w.showFullScreen();
                                     #else
                                         //w.show();
                                         w.showFullScreen();
                                     #endif
                                     #if defined(Q_WS_QWS)
                                         QWSServer::setCursorVisible(false);
                                     #endif
                                         //w.init();
                                         //Gamestate *gamestate = new PlayingGamestate(&w);
                                         Gamestate *gamestate = new OptionsGamestate(&w);
                                         w.setGamestate(gamestate);
                                         //gamestate->start();

                                         QTimer timer;
                                         QObject::connect(&timer, SIGNAL(timeout()), &w, SLOT(updateScene()));
                                         timer.start(time_per_frame_c);
                                        return a.exec();

                            }
                    }

                    char c;
                    n = read(0, &c, 1);
                    if (n > 0)
                            if(c == 0x1B)
                                    g_run_gestures = 0;

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
