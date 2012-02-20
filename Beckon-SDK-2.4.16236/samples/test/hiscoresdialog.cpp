#include "hiscoresdialog.h"
#include "mainwindow.h"

HiscoresDialog::HiscoresDialog(MainWindow *mainWindow) : QDialog(mainWindow), mainWindow(mainWindow) {
    QVBoxLayout *layout = new QVBoxLayout();
    this->setLayout(layout);

    layout->addStretch();
    {
        QHBoxLayout *h_layout = new QHBoxLayout();
        layout->addLayout(h_layout);

        QPushButton *backButton = new QPushButton(tr("Back"));
        h_layout->addWidget(backButton);
        connect(backButton, SIGNAL(clicked()), this, SLOT(close()));

        QPushButton *clearButton = new QPushButton(tr("Clear"));
        h_layout->addWidget(clearButton);
        connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));
    }
}

void HiscoresDialog::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), Qt::black);
    painter.setBrush(QBrush(Qt::white));
    const int name_x = 32, level_x = 300, score_x = 360;
    const int ydiff = 24;
    int ypos = 0;
    painter.setPen(QPen(Qt::white));
    painter.drawText(name_x, ypos+ydiff, "NAME");
    //painter.drawText(name_x, ypos, level_x - name_x, ydiff, NULL, "NAME");
    painter.drawText(level_x, ypos+ydiff, "LEVEL");
    painter.drawText(score_x, ypos+ydiff, "SCORE");
    ypos += ydiff;
    int c=0;
    qDebug("%d hiscores\n", mainWindow->getHiscores().size());
    foreach(Hiscore hiscore, mainWindow->getHiscores()) {
        painter.drawText(0, ypos, name_x - 4, ydiff, Qt::AlignRight, QString::number(c+1));
        //painter.drawText(name_x, ypos, hiscore.getName());
        //painter.drawText(name_x, ypos-ydiff+2, level_x - name_x - 4, ydiff, NULL, hiscore.getName()); // truncate long names
        painter.drawText(name_x, ypos, level_x - name_x - 4, ydiff, NULL, hiscore.getName()); // truncate long names
        painter.drawText(level_x, ypos, score_x - level_x - 4, ydiff, Qt::AlignRight, QString::number(hiscore.getLevel()));
        painter.drawText(score_x, ypos, 502 - score_x - 4, ydiff, Qt::AlignRight, QString::number(hiscore.getScore()));
        ypos += ydiff;
        c++;
    }
}

void HiscoresDialog::clear() {
    qDebug("HiscoresDialog::clear\n");
    if( QMessageBox::question(this, "Clear Hiscores", "Are you sure you wish to clear the hiscores?", QMessageBox::Ok, QMessageBox::Cancel) == QMessageBox::Ok ) {
        mainWindow->clearHiscores();
        this->update();
    }
}
