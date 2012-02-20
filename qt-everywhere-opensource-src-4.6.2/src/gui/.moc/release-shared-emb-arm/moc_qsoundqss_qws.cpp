/****************************************************************************
** Meta object code from reading C++ file 'qsoundqss_qws.h'
**
** Created: Mon Feb 13 22:06:32 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../embedded/qsoundqss_qws.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsoundqss_qws.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QWSSoundServer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   36,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QWSSoundServer[] = {
    "QWSSoundServer\0\0soundCompleted(int)\0"
    ",\0translateSoundCompleted(int,int)\0"
};

const QMetaObject QWSSoundServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QWSSoundServer,
      qt_meta_data_QWSSoundServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QWSSoundServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QWSSoundServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QWSSoundServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWSSoundServer))
        return static_cast<void*>(const_cast< QWSSoundServer*>(this));
    return QObject::qt_metacast(_clname);
}

int QWSSoundServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: soundCompleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: translateSoundCompleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QWSSoundServer::soundCompleted(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_QWSSoundClient[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      39,   36,   15,   15, 0x05,
      60,   56,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,   15,   15,   15, 0x08,
     123,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QWSSoundClient[] = {
    "QWSSoundClient\0\0soundCompleted(int)\0"
    "id\0deviceReady(int)\0id,\0"
    "deviceError(int,QWSSoundClient::DeviceErrors)\0"
    "tryReadCommand()\0emitConnectionRefused()\0"
};

const QMetaObject QWSSoundClient::staticMetaObject = {
    { &QWSSocket::staticMetaObject, qt_meta_stringdata_QWSSoundClient,
      qt_meta_data_QWSSoundClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QWSSoundClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QWSSoundClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QWSSoundClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWSSoundClient))
        return static_cast<void*>(const_cast< QWSSoundClient*>(this));
    return QWSSocket::qt_metacast(_clname);
}

int QWSSoundClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWSSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: soundCompleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: deviceReady((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: deviceError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QWSSoundClient::DeviceErrors(*)>(_a[2]))); break;
        case 3: tryReadCommand(); break;
        case 4: emitConnectionRefused(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QWSSoundClient::soundCompleted(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QWSSoundClient::deviceReady(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QWSSoundClient::deviceError(int _t1, QWSSoundClient::DeviceErrors _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
static const uint qt_meta_data_QWSSoundServerSocket[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   22,   21,   21, 0x05,
      56,   51,   21,   21, 0x05,
      97,   90,   21,   21, 0x05,
     144,  142,   21,   21, 0x05,
     163,  142,   21,   21, 0x05,
     181,  142,   21,   21, 0x05,
     205,  201,   21,   21, 0x05,
     232,   22,   21,   21, 0x05,
     254,   21,   21,   21, 0x05,
     267,   21,   21,   21, 0x05,
     290,   21,   21,   21, 0x05,
     306,  142,   21,   21, 0x05,
     334,  142,   21,   21, 0x05,
     355,   22,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
     380,   21,   21,   21, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QWSSoundServerSocket[] = {
    "QWSSoundServerSocket\0\0,,\0"
    "playFile(int,int,QString)\0,,,,\0"
    "playFile(int,int,QString,int,int)\0"
    ",,,,,,\0playRawFile(int,int,QString,int,int,int,int)\0"
    ",\0pauseFile(int,int)\0stopFile(int,int)\0"
    "resumeFile(int,int)\0,,,\0"
    "setVolume(int,int,int,int)\0"
    "setMute(int,int,bool)\0stopAll(int)\0"
    "playPriorityOnly(bool)\0setSilent(bool)\0"
    "soundFileCompleted(int,int)\0"
    "deviceReady(int,int)\0deviceError(int,int,int)\0"
    "newConnection()\0"
};

const QMetaObject QWSSoundServerSocket::staticMetaObject = {
    { &QWSServerSocket::staticMetaObject, qt_meta_stringdata_QWSSoundServerSocket,
      qt_meta_data_QWSSoundServerSocket, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QWSSoundServerSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QWSSoundServerSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QWSSoundServerSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWSSoundServerSocket))
        return static_cast<void*>(const_cast< QWSSoundServerSocket*>(this));
    return QWSServerSocket::qt_metacast(_clname);
}

int QWSSoundServerSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWSServerSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: playFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: playFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 2: playRawFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 3: pauseFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: stopFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: resumeFile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: setVolume((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 7: setMute((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 8: stopAll((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: playPriorityOnly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: setSilent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: soundFileCompleted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: deviceReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: deviceError((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: newConnection(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void QWSSoundServerSocket::playFile(int _t1, int _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QWSSoundServerSocket::playFile(int _t1, int _t2, const QString & _t3, int _t4, int _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QWSSoundServerSocket::playRawFile(int _t1, int _t2, const QString & _t3, int _t4, int _t5, int _t6, int _t7)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QWSSoundServerSocket::pauseFile(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QWSSoundServerSocket::stopFile(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QWSSoundServerSocket::resumeFile(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QWSSoundServerSocket::setVolume(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QWSSoundServerSocket::setMute(int _t1, int _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QWSSoundServerSocket::stopAll(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QWSSoundServerSocket::playPriorityOnly(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QWSSoundServerSocket::setSilent(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QWSSoundServerSocket::soundFileCompleted(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QWSSoundServerSocket::deviceReady(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QWSSoundServerSocket::deviceError(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_END_MOC_NAMESPACE
