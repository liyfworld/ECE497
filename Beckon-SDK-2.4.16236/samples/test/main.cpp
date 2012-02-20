#include <QtGui/QApplication>
#include "mainwindow.h"
#include "Shadow/IMotionSensor.h"
#include "Tracking.h"


#if defined(Q_WS_QWS)
// for Qt Embedded (e.g., Ben NanoNote)
#include <QtGui/QWSServer>
#endif
using namespace Omek;

int main(int argc, char *argv[])
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
