/****************************************************************************
** Meta object code from reading C++ file 'hoverpoints.h'
**
** Created: Mon Feb 13 23:30:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../hoverpoints.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hoverpoints.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HoverPoints[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   45,   12,   12, 0x0a,
      79,   70,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HoverPoints[] = {
    "HoverPoints\0\0points\0pointsChanged(QPolygonF)\0"
    "enabled\0setEnabled(bool)\0disabled\0"
    "setDisabled(bool)\0"
};

const QMetaObject HoverPoints::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HoverPoints,
      qt_meta_data_HoverPoints, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HoverPoints::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HoverPoints::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HoverPoints::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HoverPoints))
        return static_cast<void*>(const_cast< HoverPoints*>(this));
    return QObject::qt_metacast(_clname);
}

int HoverPoints::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: pointsChanged((*reinterpret_cast< const QPolygonF(*)>(_a[1]))); break;
        case 1: setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: setDisabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HoverPoints::pointsChanged(const QPolygonF & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE