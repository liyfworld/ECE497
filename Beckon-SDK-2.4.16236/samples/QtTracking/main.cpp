#include <iostream>
#include <QtGui>
#include <QPlainTextEdit>
#include <QString>
#include <QStringList>
#include <exception>

#include "MainWindow.h"
#include "TrackingWindow.h"
#include "Tracking.h"


using namespace std;
using namespace Omek;

const int TIMER_INT = 1000/30; // timer interval

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    char* sequence = NULL;
    Tracking track; // tracking object
    QString status = ""; // status which is displayed in the status bar

    // Indicates whether the recording functionality is enabled.
    bool enableRecording = false;

    for(int i=1; i < argc; i++)
    {
        if(strcmp(argv[i], "-seq") == 0)
        {
            sequence = argv[i+1];
            QString tempSeq = QString(argv[i+1]);
            QStringList tempSeqList = tempSeq.split(QRegExp("/"));
            status.append(tempSeqList.last()); // sequence name
        }
        // enable the recording functionality
        else if(strcmp(argv[i], "-rec") == 0)
            enableRecording = true;

    }

    if(track.initialize(sequence))
    {
        cerr << "Failed to initialize tracking !" << endl;
        return 1;
    }

    TrackingWindow * labelMask = new TrackingWindow(track.getImageWidth(), track.getImageHeight());
    TrackingWindow * labelDepth = new TrackingWindow(track.getImageWidth(), track.getImageHeight());

    labelMask->setScaledContents(true);
    labelMask->setFixedSize(2*track.getImageWidth(), 2*track.getImageHeight());
    labelDepth->setScaledContents(true);
    labelDepth->setFixedSize(2*track.getImageWidth(), 2*track.getImageHeight());

    MainWindow *window = new MainWindow();
    window->setWindowOpacity(10);
    window->adjustSize(); // adjust to the sizes of child widgets

    QHBoxLayout *masterLayout = new QHBoxLayout(); // main layout
    masterLayout->addWidget(labelDepth);
    masterLayout->addWidget(labelMask);
    window->setLayout(masterLayout);

    QPushButton *recordButton = NULL;
    if(enableRecording)
    {
        // Create the recording button.
        recordButton = new QPushButton("REC");
        recordButton->setCheckable(true);
        masterLayout->addWidget(recordButton,0,0);
    }


    QMainWindow mWind;
    mWind.setWindowTitle(QApplication::translate("windowlayout", "Omek Interactive Tracking Demo"));
    mWind.setCentralWidget(window);
    mWind.statusBar()->showMessage(status);
    mWind.show();

    QTimer timer;

    if(enableRecording)
    {
        QObject::connect(recordButton,
                         SIGNAL(toggled(bool)),
                         &track,
                         SLOT(recordOrStop(bool)));
    }

    QObject::connect(window, SIGNAL(shutdown()),
                     &app, SLOT(quit()));

    QObject::connect(&timer,
                     SIGNAL(timeout()),
                     &track,
                     SLOT(updateFrame()));

    QObject::connect(&track, SIGNAL(shutdown()),
                     &app, SLOT(quit()));

    QObject::connect(&track,
                     SIGNAL(updateDepthImage(unsigned char*)),
                     labelDepth,
                     SLOT(updateDepthImage(unsigned char*)));

    QObject::connect(&track,
                     SIGNAL(updateMaskImage(unsigned char*)),
                     labelMask,
                     SLOT(updateMaskImage(unsigned char*)));

    QObject::connect(&track,
                     SIGNAL(addPoint(uint,uint,JointID)),
                     labelMask,
                     SLOT(addPoint(uint,uint,JointID)));

    timer.start(TIMER_INT);

    return app.exec();
}


