/****************************************************************************
** Meta object code from reading C++ file 'sslclient.h'
**
** Created: Mon Feb 13 23:16:50 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sslclient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sslclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SslClient[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      32,   10,   10,   10, 0x08,
      54,   48,   10,   10, 0x08,
     103,   10,   10,   10, 0x08,
     121,   10,   10,   10, 0x08,
     139,   10,   10,   10, 0x08,
     157,  150,   10,   10, 0x08,
     185,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SslClient[] = {
    "SslClient\0\0updateEnabledState()\0"
    "secureConnect()\0state\0"
    "socketStateChanged(QAbstractSocket::SocketState)\0"
    "socketEncrypted()\0socketReadyRead()\0"
    "sendData()\0errors\0sslErrors(QList<QSslError>)\0"
    "displayCertificateInfo()\0"
};

const QMetaObject SslClient::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SslClient,
      qt_meta_data_SslClient, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SslClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SslClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SslClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SslClient))
        return static_cast<void*>(const_cast< SslClient*>(this));
    return QWidget::qt_metacast(_clname);
}

int SslClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateEnabledState(); break;
        case 1: secureConnect(); break;
        case 2: socketStateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 3: socketEncrypted(); break;
        case 4: socketReadyRead(); break;
        case 5: sendData(); break;
        case 6: sslErrors((*reinterpret_cast< const QList<QSslError>(*)>(_a[1]))); break;
        case 7: displayCertificateInfo(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE