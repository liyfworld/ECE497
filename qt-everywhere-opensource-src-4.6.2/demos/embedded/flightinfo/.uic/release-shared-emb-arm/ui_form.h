/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created: Mon Feb 13 23:33:47 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *titleBox;
    QHBoxLayout *horizontalLayout;
    QLabel *flightName;
    QLabel *flightStatus;
    QFrame *searchBar;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *flightEdit;
    QToolButton *searchButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QFrame *infoBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *detailedInfo;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(220, 171);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleBox = new QFrame(Form);
        titleBox->setObjectName(QString::fromUtf8("titleBox"));
        titleBox->setFrameShape(QFrame::NoFrame);
        titleBox->setFrameShadow(QFrame::Raised);
        titleBox->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(titleBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        flightName = new QLabel(titleBox);
        flightName->setObjectName(QString::fromUtf8("flightName"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(flightName->sizePolicy().hasHeightForWidth());
        flightName->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(flightName);

        flightStatus = new QLabel(titleBox);
        flightStatus->setObjectName(QString::fromUtf8("flightStatus"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(flightStatus->sizePolicy().hasHeightForWidth());
        flightStatus->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        flightStatus->setFont(font);
        flightStatus->setLineWidth(0);
        flightStatus->setAlignment(Qt::AlignCenter);
        flightStatus->setMargin(4);

        horizontalLayout->addWidget(flightStatus);


        verticalLayout->addWidget(titleBox);

        searchBar = new QFrame(Form);
        searchBar->setObjectName(QString::fromUtf8("searchBar"));
        searchBar->setFrameShape(QFrame::NoFrame);
        searchBar->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(searchBar);
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        flightEdit = new QLineEdit(searchBar);
        flightEdit->setObjectName(QString::fromUtf8("flightEdit"));

        horizontalLayout_2->addWidget(flightEdit);

        searchButton = new QToolButton(searchBar);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(searchButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(searchBar);

        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        infoBox = new QFrame(Form);
        infoBox->setObjectName(QString::fromUtf8("infoBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(infoBox->sizePolicy().hasHeightForWidth());
        infoBox->setSizePolicy(sizePolicy2);
        infoBox->setFrameShape(QFrame::NoFrame);
        infoBox->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(infoBox);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(5, 5, 5, 5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        detailedInfo = new QLabel(infoBox);
        detailedInfo->setObjectName(QString::fromUtf8("detailedInfo"));
        sizePolicy2.setHeightForWidth(detailedInfo->sizePolicy().hasHeightForWidth());
        detailedInfo->setSizePolicy(sizePolicy2);
        detailedInfo->setTextFormat(Qt::RichText);
        detailedInfo->setWordWrap(true);
        detailedInfo->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_3->addWidget(detailedInfo);


        verticalLayout->addWidget(infoBox);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        titleBox->setStyleSheet(QApplication::translate("Form", "QFrame {\n"
"background-color: #45629a;\n"
"}\n"
"\n"
"QLabel {\n"
"color: white;\n"
"}", 0, QApplication::UnicodeUTF8));
        flightName->setText(QApplication::translate("Form", "Powered by FlightView", 0, QApplication::UnicodeUTF8));
        flightStatus->setStyleSheet(QApplication::translate("Form", "background-color: white;\n"
"color:  #45629a;", 0, QApplication::UnicodeUTF8));
        flightStatus->setText(QApplication::translate("Form", "Ready", 0, QApplication::UnicodeUTF8));
        flightEdit->setStyleSheet(QApplication::translate("Form", "color: black;\n"
"border: 1px solid black;\n"
"background: white;\n"
"selection-background-color: lightgray;", 0, QApplication::UnicodeUTF8));
        searchButton->setStyleSheet(QApplication::translate("Form", "color: rgb(255, 255, 255);\n"
"background-color: rgb(85, 85, 255);\n"
"padding: 2px;\n"
"border: 2px solid  rgb(0, 0, 127);", 0, QApplication::UnicodeUTF8));
        searchButton->setText(QApplication::translate("Form", "Search", 0, QApplication::UnicodeUTF8));
        infoBox->setStyleSheet(QApplication::translate("Form", "QFrame { border: 2px solid white;\n"
"border-radius: 10px;\n"
"margin: 5px;\n"
"background-color: rgba(69, 98, 154, 192); }", 0, QApplication::UnicodeUTF8));
        detailedInfo->setStyleSheet(QApplication::translate("Form", "color: white;\n"
"border: none;\n"
"background-color: none;", 0, QApplication::UnicodeUTF8));
        detailedInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
