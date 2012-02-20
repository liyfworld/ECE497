/****************************************************************************
** Meta object code from reading C++ file 'trackerclient.h'
**
** Created: Mon Feb 13 23:16:30 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../trackerclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackerclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TrackerClient[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   15,   14,   14, 0x05,
      58,   51,   14,   14, 0x05,
      83,   75,   14,   14, 0x05,
     109,  100,   14,   14, 0x05,
     160,  145,   14,   14, 0x05,
     204,  187,   14,   14, 0x05,
     233,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     243,   14,   14,   14, 0x08,
     259,   15,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TrackerClient[] = {
    "TrackerClient\0\0error\0connectionError(QHttp::Error)\0"
    "reason\0failure(QString)\0message\0"
    "warning(QString)\0peerList\0"
    "peerListUpdated(QList<TorrentPeer>)\0"
    "newUploadCount\0uploadCountUpdated(qint64)\0"
    "newDownloadCount\0downloadCountUpdated(qint64)\0"
    "stopped()\0fetchPeerList()\0"
    "httpRequestDone(bool)\0"
};

const QMetaObject TrackerClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TrackerClient,
      qt_meta_data_TrackerClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TrackerClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TrackerClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TrackerClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrackerClient))
        return static_cast<void*>(const_cast< TrackerClient*>(this));
    return QObject::qt_metacast(_clname);
}

int TrackerClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connectionError((*reinterpret_cast< QHttp::Error(*)>(_a[1]))); break;
        case 1: failure((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: warning((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: peerListUpdated((*reinterpret_cast< const QList<TorrentPeer>(*)>(_a[1]))); break;
        case 4: uploadCountUpdated((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: downloadCountUpdated((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: stopped(); break;
        case 7: fetchPeerList(); break;
        case 8: httpRequestDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TrackerClient::connectionError(QHttp::Error _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrackerClient::failure(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TrackerClient::warning(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TrackerClient::peerListUpdated(const QList<TorrentPeer> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TrackerClient::uploadCountUpdated(qint64 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TrackerClient::downloadCountUpdated(qint64 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TrackerClient::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
