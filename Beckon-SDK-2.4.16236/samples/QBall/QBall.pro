#-------------------------------------------------
#
# Project created by QtCreator 2010-08-01T22:12:07
#
#-------------------------------------------------

QT       += core gui

TARGET = QBall
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blockitem.cpp \
    hiscoresdialog.cpp

HEADERS  += mainwindow.h \
    blockitem.h \
    hiscoresdialog.h

#packageheader = "$${LITERAL_HASH}{\"QBall\"},(0xed4fcd0a),1,3,0"
packageheader = "$${LITERAL_HASH}{\"QBall\"},(0xA001052C),1,3,0"
DEPLOYMENT.installer_header = "$${LITERAL_HASH}{\"QBall Installer\"},(0xA000D7CE),1,3,0"

vendorinfo = \
"%{\"Mark Harman\"}" \
":\"Mark Harman\""

dependencyinfo = \
"; Default dependency to Qt libraries" \
"(0x2001E61C), 4, 6, 3, {\"Qt\"}" \
"; Default HW/platform dependencies" \
"[0x101F7961],0,0,0,{\"S60ProductID\"}" \
"[0x102032BE],0,0,0,{\"S60ProductID\"}" \
"[0x102752AE],0,0,0,{\"S60ProductID\"}" \
"[0x1028315F],0,0,0,{\"S60ProductID\"}" \

default_deployment.pkg_prerules = packageheader vendorinfo dependencyinfo

ICON = icon.svg

symbian {
    TARGET.UID3 = 0xed4fcd0a
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

RESOURCES +=

OTHER_FILES += \
    _docs/comp_qball.html
