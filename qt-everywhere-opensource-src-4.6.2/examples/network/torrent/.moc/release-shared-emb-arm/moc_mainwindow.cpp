/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Feb 13 23:16:26 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      27,   11,   11,   11, 0x08,
      47,   11,   42,   11, 0x08,
      60,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      91,   11,   11,   11, 0x08,
     107,   11,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,
     148,  142,   11,   11, 0x08,
     189,  183,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     248,  240,   11,   11, 0x08,
     283,  268,   11,   11, 0x08,
     307,  268,   11,   11, 0x08,
     335,  329,   11,   11, 0x08,
     355,  329,   11,   11, 0x08,
     377,   11,   11,   11, 0x08,
     385,   11,   11,   11, 0x08,
     414,  405,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0loadSettings()\0saveSettings()\0"
    "bool\0addTorrent()\0removeTorrent()\0"
    "pauseTorrent()\0moveTorrentUp()\0"
    "moveTorrentDown()\0torrentStopped()\0"
    "error\0torrentError(TorrentClient::Error)\0"
    "state\0updateState(TorrentClient::State)\0"
    "updatePeerInfo()\0percent\0updateProgress(int)\0"
    "bytesPerSecond\0updateDownloadRate(int)\0"
    "updateUploadRate(int)\0bytes\0"
    "setUploadLimit(int)\0setDownloadLimit(int)\0"
    "about()\0setActionsEnabled()\0fileName\0"
    "acceptFileDrop(QString)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadSettings(); break;
        case 1: saveSettings(); break;
        case 2: { bool _r = addTorrent();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: removeTorrent(); break;
        case 4: pauseTorrent(); break;
        case 5: moveTorrentUp(); break;
        case 6: moveTorrentDown(); break;
        case 7: torrentStopped(); break;
        case 8: torrentError((*reinterpret_cast< TorrentClient::Error(*)>(_a[1]))); break;
        case 9: updateState((*reinterpret_cast< TorrentClient::State(*)>(_a[1]))); break;
        case 10: updatePeerInfo(); break;
        case 11: updateProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: updateDownloadRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: updateUploadRate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: setUploadLimit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: setDownloadLimit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: about(); break;
        case 17: setActionsEnabled(); break;
        case 18: acceptFileDrop((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
