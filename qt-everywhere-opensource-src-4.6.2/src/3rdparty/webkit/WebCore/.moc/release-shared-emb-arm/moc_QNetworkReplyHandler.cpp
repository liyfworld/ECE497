/****************************************************************************
** Meta object code from reading C++ file 'QNetworkReplyHandler.h'
**
** Created: Mon Feb 13 22:33:12 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../platform/network/qt/QNetworkReplyHandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QNetworkReplyHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebCore__QNetworkReplyHandler[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      31,   30,   30,   30, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   30,   30,   30, 0x08,
      61,   30,   30,   30, 0x08,
      84,   30,   30,   30, 0x08,
      98,   30,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WebCore__QNetworkReplyHandler[] = {
    "WebCore::QNetworkReplyHandler\0\0"
    "processQueuedItems()\0finish()\0"
    "sendResponseIfNeeded()\0forwardData()\0"
    "sendQueuedItems()\0"
};

const QMetaObject WebCore::QNetworkReplyHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebCore__QNetworkReplyHandler,
      qt_meta_data_WebCore__QNetworkReplyHandler, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebCore::QNetworkReplyHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebCore::QNetworkReplyHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebCore::QNetworkReplyHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebCore__QNetworkReplyHandler))
        return static_cast<void*>(const_cast< QNetworkReplyHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int WebCore::QNetworkReplyHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: processQueuedItems(); break;
        case 1: finish(); break;
        case 2: sendResponseIfNeeded(); break;
        case 3: forwardData(); break;
        case 4: sendQueuedItems(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void WebCore::QNetworkReplyHandler::processQueuedItems()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_WebCore__FormDataIODevice[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_WebCore__FormDataIODevice[] = {
    "WebCore::FormDataIODevice\0"
};

const QMetaObject WebCore::FormDataIODevice::staticMetaObject = {
    { &QIODevice::staticMetaObject, qt_meta_stringdata_WebCore__FormDataIODevice,
      qt_meta_data_WebCore__FormDataIODevice, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebCore::FormDataIODevice::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebCore::FormDataIODevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebCore::FormDataIODevice::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebCore__FormDataIODevice))
        return static_cast<void*>(const_cast< FormDataIODevice*>(this));
    return QIODevice::qt_metacast(_clname);
}

int WebCore::FormDataIODevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
