/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created: Mon Feb 13 23:17:47 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>
#include "displaywidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    DisplayWidget *displayWidget;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *shapeComboBox;
    QLabel *label_2;
    QToolButton *colorButton;
    QLabel *label_3;
    QComboBox *shapeComboBox_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_2;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(339, 353);
        gridLayout_2 = new QGridLayout(Window);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        displayWidget = new DisplayWidget(Window);
        displayWidget->setObjectName(QString::fromUtf8("displayWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(200);
        sizePolicy.setVerticalStretch(200);
        sizePolicy.setHeightForWidth(displayWidget->sizePolicy().hasHeightForWidth());
        displayWidget->setSizePolicy(sizePolicy);
        displayWidget->setMinimumSize(QSize(200, 200));
        displayWidget->setMaximumSize(QSize(200, 200));

        gridLayout_2->addWidget(displayWidget, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Window);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        shapeComboBox = new QComboBox(Window);
        shapeComboBox->setObjectName(QString::fromUtf8("shapeComboBox"));

        gridLayout->addWidget(shapeComboBox, 0, 1, 1, 1);

        label_2 = new QLabel(Window);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        colorButton = new QToolButton(Window);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));

        gridLayout->addWidget(colorButton, 1, 1, 1, 1);

        label_3 = new QLabel(Window);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        shapeComboBox_2 = new QComboBox(Window);
        shapeComboBox_2->setObjectName(QString::fromUtf8("shapeComboBox_2"));

        gridLayout->addWidget(shapeComboBox_2, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton_2 = new QToolButton(Window);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        horizontalLayout->addWidget(toolButton_2);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 3);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(shapeComboBox);
        label_2->setBuddy(colorButton);
        label_3->setBuddy(shapeComboBox_2);
#endif // QT_NO_SHORTCUT

        retranslateUi(Window);
        QObject::connect(shapeComboBox, SIGNAL(currentIndexChanged(int)), Window, SLOT(updateShape(int)));
        QObject::connect(colorButton, SIGNAL(clicked()), Window, SLOT(updateColor()));
        QObject::connect(shapeComboBox_2, SIGNAL(currentIndexChanged(int)), Window, SLOT(updateBackground(int)));
        QObject::connect(toolButton_2, SIGNAL(clicked()), Window, SLOT(saveSvg()));

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "SVG Generator", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Window", "&Shape:", 0, QApplication::UnicodeUTF8));
        shapeComboBox->clear();
        shapeComboBox->insertItems(0, QStringList()
         << QApplication::translate("Window", "House", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Window", "Car", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Window", "&Color:", 0, QApplication::UnicodeUTF8));
        colorButton->setText(QApplication::translate("Window", "Choose Color...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Window", "&Background:", 0, QApplication::UnicodeUTF8));
        shapeComboBox_2->clear();
        shapeComboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Window", "Sky", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Window", "Trees", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Window", "Road", 0, QApplication::UnicodeUTF8)
        );
        toolButton_2->setText(QApplication::translate("Window", "Save &As...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
