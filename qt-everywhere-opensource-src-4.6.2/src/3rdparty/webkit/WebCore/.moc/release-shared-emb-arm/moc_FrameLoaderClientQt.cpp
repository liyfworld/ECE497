/****************************************************************************
** Meta object code from reading C++ file 'FrameLoaderClientQt.h'
**
** Created: Mon Feb 13 22:34:20 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WebKit/qt/WebCoreSupport/FrameLoaderClientQt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrameLoaderClientQt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebCore__FrameLoaderClientQt[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      30,   29,   29,   29, 0x05,
      46,   44,   29,   29, 0x05,
      64,   29,   29,   29, 0x05,
      89,   83,   29,   29, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_WebCore__FrameLoaderClientQt[] = {
    "WebCore::FrameLoaderClientQt\0\0"
    "loadStarted()\0d\0loadProgress(int)\0"
    "loadFinished(bool)\0title\0titleChanged(QString)\0"
};

const QMetaObject WebCore::FrameLoaderClientQt::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WebCore__FrameLoaderClientQt,
      qt_meta_data_WebCore__FrameLoaderClientQt, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebCore::FrameLoaderClientQt::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebCore::FrameLoaderClientQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebCore::FrameLoaderClientQt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebCore__FrameLoaderClientQt))
        return static_cast<void*>(const_cast< FrameLoaderClientQt*>(this));
    if (!strcmp(_clname, "FrameLoaderClient"))
        return static_cast< FrameLoaderClient*>(const_cast< FrameLoaderClientQt*>(this));
    return QObject::qt_metacast(_clname);
}

int WebCore::FrameLoaderClientQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadStarted(); break;
        case 1: loadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: titleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void WebCore::FrameLoaderClientQt::loadStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void WebCore::FrameLoaderClientQt::loadProgress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WebCore::FrameLoaderClientQt::loadFinished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WebCore::FrameLoaderClientQt::titleChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
