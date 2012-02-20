/****************************************************************************
** Meta object code from reading C++ file 'roundrectitem.h'
**
** Created: Mon Feb 13 23:09:25 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../roundrectitem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roundrectitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RoundRectItem[] = {

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
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   27,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RoundRectItem[] = {
    "RoundRectItem\0\0activated()\0value\0"
    "updateValue(qreal)\0"
};

const QMetaObject RoundRectItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RoundRectItem,
      qt_meta_data_RoundRectItem, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RoundRectItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RoundRectItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RoundRectItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RoundRectItem))
        return static_cast<void*>(const_cast< RoundRectItem*>(this));
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(const_cast< RoundRectItem*>(this));
    return QObject::qt_metacast(_clname);
}

int RoundRectItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: activated(); break;
        case 1: updateValue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void RoundRectItem::activated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
