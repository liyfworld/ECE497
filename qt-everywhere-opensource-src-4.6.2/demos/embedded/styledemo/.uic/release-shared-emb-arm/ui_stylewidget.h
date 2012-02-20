/********************************************************************************
** Form generated from reading UI file 'stylewidget.ui'
**
** Created: Mon Feb 13 23:33:00 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLEWIDGET_H
#define UI_STYLEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StyleWidget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *transparentStyle;
    QPushButton *blueStyle;
    QPushButton *khakiStyle;
    QPushButton *noStyle;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QScrollBar *horizontalScrollBar;
    QScrollBar *horizontalScrollBar_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *spacerItem;
    QPushButton *close;

    void setupUi(QWidget *StyleWidget)
    {
        if (StyleWidget->objectName().isEmpty())
            StyleWidget->setObjectName(QString::fromUtf8("StyleWidget"));
        StyleWidget->resize(184, 245);
        gridLayout = new QGridLayout(StyleWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(StyleWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(4);
        gridLayout_2->setContentsMargins(4, 4, 4, 4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        transparentStyle = new QPushButton(groupBox);
        transparentStyle->setObjectName(QString::fromUtf8("transparentStyle"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(transparentStyle->sizePolicy().hasHeightForWidth());
        transparentStyle->setSizePolicy(sizePolicy);
        transparentStyle->setFocusPolicy(Qt::StrongFocus);
        transparentStyle->setCheckable(true);
        transparentStyle->setChecked(false);
        transparentStyle->setAutoExclusive(true);

        gridLayout_2->addWidget(transparentStyle, 0, 0, 1, 1);

        blueStyle = new QPushButton(groupBox);
        blueStyle->setObjectName(QString::fromUtf8("blueStyle"));
        sizePolicy.setHeightForWidth(blueStyle->sizePolicy().hasHeightForWidth());
        blueStyle->setSizePolicy(sizePolicy);
        blueStyle->setFocusPolicy(Qt::StrongFocus);
        blueStyle->setCheckable(true);
        blueStyle->setChecked(false);
        blueStyle->setAutoExclusive(true);

        gridLayout_2->addWidget(blueStyle, 2, 0, 1, 1);

        khakiStyle = new QPushButton(groupBox);
        khakiStyle->setObjectName(QString::fromUtf8("khakiStyle"));
        sizePolicy.setHeightForWidth(khakiStyle->sizePolicy().hasHeightForWidth());
        khakiStyle->setSizePolicy(sizePolicy);
        khakiStyle->setFocusPolicy(Qt::StrongFocus);
        khakiStyle->setCheckable(true);
        khakiStyle->setChecked(false);
        khakiStyle->setAutoExclusive(true);

        gridLayout_2->addWidget(khakiStyle, 0, 1, 1, 1);

        noStyle = new QPushButton(groupBox);
        noStyle->setObjectName(QString::fromUtf8("noStyle"));
        sizePolicy.setHeightForWidth(noStyle->sizePolicy().hasHeightForWidth());
        noStyle->setSizePolicy(sizePolicy);
        noStyle->setFocusPolicy(Qt::StrongFocus);
        noStyle->setCheckable(true);
        noStyle->setChecked(true);
        noStyle->setAutoExclusive(true);

        gridLayout_2->addWidget(noStyle, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setContentsMargins(4, 4, 4, 4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(StyleWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(StyleWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setFocusPolicy(Qt::WheelFocus);
        spinBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        spinBox->setKeyboardTracking(false);

        horizontalLayout->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        horizontalScrollBar = new QScrollBar(StyleWidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalScrollBar->sizePolicy().hasHeightForWidth());
        horizontalScrollBar->setSizePolicy(sizePolicy2);
        horizontalScrollBar->setMinimumSize(QSize(0, 24));
        horizontalScrollBar->setFocusPolicy(Qt::TabFocus);
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalScrollBar, 3, 0, 1, 1);

        horizontalScrollBar_2 = new QScrollBar(StyleWidget);
        horizontalScrollBar_2->setObjectName(QString::fromUtf8("horizontalScrollBar_2"));
        sizePolicy2.setHeightForWidth(horizontalScrollBar_2->sizePolicy().hasHeightForWidth());
        horizontalScrollBar_2->setSizePolicy(sizePolicy2);
        horizontalScrollBar_2->setMinimumSize(QSize(0, 24));
        horizontalScrollBar_2->setFocusPolicy(Qt::TabFocus);
        horizontalScrollBar_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalScrollBar_2, 3, 1, 1, 1);

        pushButton_2 = new QPushButton(StyleWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy2);
        pushButton_2->setFocusPolicy(Qt::StrongFocus);
        pushButton_2->setCheckable(true);
        pushButton_2->setChecked(true);
        pushButton_2->setFlat(false);

        gridLayout->addWidget(pushButton_2, 4, 0, 1, 1);

        pushButton = new QPushButton(StyleWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setFocusPolicy(Qt::StrongFocus);
        pushButton->setCheckable(true);
        pushButton->setChecked(true);
        pushButton->setFlat(false);

        gridLayout->addWidget(pushButton, 4, 1, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 2);

        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerItem, 6, 0, 1, 1);

        close = new QPushButton(StyleWidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setFocusPolicy(Qt::StrongFocus);

        gridLayout->addWidget(close, 6, 1, 1, 1);


        retranslateUi(StyleWidget);
        QObject::connect(horizontalScrollBar, SIGNAL(valueChanged(int)), horizontalScrollBar_2, SLOT(setValue(int)));
        QObject::connect(horizontalScrollBar_2, SIGNAL(valueChanged(int)), horizontalScrollBar, SLOT(setValue(int)));
        QObject::connect(pushButton, SIGNAL(clicked(bool)), horizontalScrollBar_2, SLOT(setEnabled(bool)));
        QObject::connect(pushButton_2, SIGNAL(clicked(bool)), horizontalScrollBar, SLOT(setVisible(bool)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalScrollBar_2, SLOT(setValue(int)));
        QObject::connect(horizontalScrollBar_2, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(StyleWidget);
    } // setupUi

    void retranslateUi(QWidget *StyleWidget)
    {
        StyleWidget->setWindowTitle(QApplication::translate("StyleWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("StyleWidget", "Styles", 0, QApplication::UnicodeUTF8));
        transparentStyle->setText(QApplication::translate("StyleWidget", "Transp.", 0, QApplication::UnicodeUTF8));
        blueStyle->setText(QApplication::translate("StyleWidget", "Blue", 0, QApplication::UnicodeUTF8));
        khakiStyle->setText(QApplication::translate("StyleWidget", "Khaki", 0, QApplication::UnicodeUTF8));
        noStyle->setText(QApplication::translate("StyleWidget", "None", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StyleWidget", "Value:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("StyleWidget", "Show", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("StyleWidget", "Enable", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("StyleWidget", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StyleWidget: public Ui_StyleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLEWIDGET_H
