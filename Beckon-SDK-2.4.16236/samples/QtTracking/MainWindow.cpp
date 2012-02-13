#include <iostream>
#include <qevent.h>
#include "MainWindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
     setFocusPolicy(Qt::StrongFocus);
}


void MainWindow::keyPressEvent ( QKeyEvent * event )
{
    switch (event->key())
    {
        case Qt::Key_Escape:
            emit shutdown();
            break;
    }

    QWidget::keyPressEvent(event);
}
