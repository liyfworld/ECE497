/****************************************************************************
** Meta object code from reading C++ file 'ftpwindow.h'
**
** Created: Mon Feb 13 23:15:33 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ftpwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftpwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FtpWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      33,   10,   10,   10, 0x08,
      48,   10,   10,   10, 0x08,
      81,   65,   10,   10, 0x08,
     118,  110,   10,   10, 0x08,
     150,  138,   10,   10, 0x08,
     184,   10,   10,   10, 0x08,
     218,  197,   10,   10, 0x08,
     260,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FtpWindow[] = {
    "FtpWindow\0\0connectOrDisconnect()\0"
    "downloadFile()\0cancelDownload()\0"
    "commandId,error\0ftpCommandFinished(int,bool)\0"
    "urlInfo\0addToList(QUrlInfo)\0item,column\0"
    "processItem(QTreeWidgetItem*,int)\0"
    "cdToParent()\0readBytes,totalBytes\0"
    "updateDataTransferProgress(qint64,qint64)\0"
    "enableDownloadButton()\0"
};

const QMetaObject FtpWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FtpWindow,
      qt_meta_data_FtpWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FtpWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FtpWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FtpWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FtpWindow))
        return static_cast<void*>(const_cast< FtpWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int FtpWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connectOrDisconnect(); break;
        case 1: downloadFile(); break;
        case 2: cancelDownload(); break;
        case 3: ftpCommandFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: addToList((*reinterpret_cast< const QUrlInfo(*)>(_a[1]))); break;
        case 5: processItem((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: cdToParent(); break;
        case 7: updateDataTransferProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 8: enableDownloadButton(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
