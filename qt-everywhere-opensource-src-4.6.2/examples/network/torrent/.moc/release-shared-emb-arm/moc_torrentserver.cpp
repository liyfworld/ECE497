/****************************************************************************
** Meta object code from reading C++ file 'torrentserver.h'
**
** Created: Mon Feb 13 23:16:29 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../torrentserver.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'torrentserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TorrentServer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      39,   30,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TorrentServer[] = {
    "TorrentServer\0\0removeClient()\0infoHash\0"
    "processInfoHash(QByteArray)\0"
};

const QMetaObject TorrentServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_TorrentServer,
      qt_meta_data_TorrentServer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TorrentServer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TorrentServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TorrentServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TorrentServer))
        return static_cast<void*>(const_cast< TorrentServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int TorrentServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: removeClient(); break;
        case 1: processInfoHash((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
