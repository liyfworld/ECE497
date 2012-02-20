/****************************************************************************
** Meta object code from reading C++ file 'stickman.h'
**
** Created: Mon Feb 13 23:07:12 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../stickman.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stickman.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StickMan[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       3,   24, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      22,    9,    9,    9, 0x0a,

 // properties: name, type, flags
      52,   45, 0x43095103,
      61,   45, 0x43095103,
      76,   71, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_StickMan[] = {
    "StickMan\0\0stabilize()\0childPositionChanged()\0"
    "QColor\0penColor\0fillColor\0bool\0isDead\0"
};

const QMetaObject StickMan::staticMetaObject = {
    { &QGraphicsObject::staticMetaObject, qt_meta_stringdata_StickMan,
      qt_meta_data_StickMan, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StickMan::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StickMan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StickMan::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StickMan))
        return static_cast<void*>(const_cast< StickMan*>(this));
    return QGraphicsObject::qt_metacast(_clname);
}

int StickMan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stabilize(); break;
        case 1: childPositionChanged(); break;
        default: ;
        }
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = penColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = fillColor(); break;
        case 2: *reinterpret_cast< bool*>(_v) = isDead(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setPenColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: setFillColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: setIsDead(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
