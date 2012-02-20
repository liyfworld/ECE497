/********************************************************************************
** Form generated from reading UI file 'formextractor.ui'
**
** Created: Mon Feb 13 23:29:19 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMEXTRACTOR_H
#define UI_FORMEXTRACTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *webFormGroupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWebView *webView;
    QSpacerItem *horizontalSpacer;
    QGroupBox *dataGroupBox;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *firstNameLabel;
    QLineEdit *firstNameEdit;
    QLabel *lastNameLabel;
    QLineEdit *lastNameEdit;
    QLabel *genderLabel;
    QLineEdit *genderEdit;
    QLabel *updatesLabel;
    QLineEdit *updatesEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(680, 218);
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        webFormGroupBox = new QGroupBox(Form);
        webFormGroupBox->setObjectName(QString::fromUtf8("webFormGroupBox"));
        verticalLayout_2 = new QVBoxLayout(webFormGroupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        webView = new QWebView(webFormGroupBox);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setMinimumSize(QSize(200, 150));
        webView->setMaximumSize(QSize(400, 16777215));
        webView->setUrl(QUrl("about:blank"));

        verticalLayout->addWidget(webView);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(webFormGroupBox);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dataGroupBox = new QGroupBox(Form);
        dataGroupBox->setObjectName(QString::fromUtf8("dataGroupBox"));
        verticalLayout_3 = new QVBoxLayout(dataGroupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        firstNameLabel = new QLabel(dataGroupBox);
        firstNameLabel->setObjectName(QString::fromUtf8("firstNameLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, firstNameLabel);

        firstNameEdit = new QLineEdit(dataGroupBox);
        firstNameEdit->setObjectName(QString::fromUtf8("firstNameEdit"));
        firstNameEdit->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, firstNameEdit);

        lastNameLabel = new QLabel(dataGroupBox);
        lastNameLabel->setObjectName(QString::fromUtf8("lastNameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lastNameLabel);

        lastNameEdit = new QLineEdit(dataGroupBox);
        lastNameEdit->setObjectName(QString::fromUtf8("lastNameEdit"));
        lastNameEdit->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lastNameEdit);

        genderLabel = new QLabel(dataGroupBox);
        genderLabel->setObjectName(QString::fromUtf8("genderLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, genderLabel);

        genderEdit = new QLineEdit(dataGroupBox);
        genderEdit->setObjectName(QString::fromUtf8("genderEdit"));
        genderEdit->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, genderEdit);

        updatesLabel = new QLabel(dataGroupBox);
        updatesLabel->setObjectName(QString::fromUtf8("updatesLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, updatesLabel);

        updatesEdit = new QLineEdit(dataGroupBox);
        updatesEdit->setObjectName(QString::fromUtf8("updatesEdit"));
        updatesEdit->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, updatesEdit);


        verticalLayout_3->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 24, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(dataGroupBox);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        webFormGroupBox->setTitle(QApplication::translate("Form", "Web Form", 0, QApplication::UnicodeUTF8));
        dataGroupBox->setTitle(QApplication::translate("Form", "Extracted Data", 0, QApplication::UnicodeUTF8));
        firstNameLabel->setText(QApplication::translate("Form", "First Name", 0, QApplication::UnicodeUTF8));
        lastNameLabel->setText(QApplication::translate("Form", "Last Name", 0, QApplication::UnicodeUTF8));
        genderLabel->setText(QApplication::translate("Form", "Gender", 0, QApplication::UnicodeUTF8));
        updatesLabel->setText(QApplication::translate("Form", "Receive Updates", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMEXTRACTOR_H
