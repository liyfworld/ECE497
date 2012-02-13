#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtGui>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

signals:

    /**
            Emitted when ESC button is pressed on the keyboard
    */
    void shutdown();

protected:

    /**
            Catches an ESC button press
            @param[in] event the event of the pressed button
    */
    void keyPressEvent ( QKeyEvent * event );


};

#endif // MAINWINDOW_H
