/****************************************************************************
** Meta object code from reading C++ file 'torpedo.h'
**
** Created: Mon Feb 13 23:32:55 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../torpedo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'torpedo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Torpedo[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      27,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Torpedo[] = {
    "Torpedo\0\0torpedoExploded()\0"
    "torpedoExecutionFinished()\0"
    "onAnimationLaunchValueChanged(QVariant)\0"
};

const QMetaObject Torpedo::staticMetaObject = {
    { &PixmapItem::staticMetaObject, qt_meta_stringdata_Torpedo,
      qt_meta_data_Torpedo, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Torpedo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Torpedo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Torpedo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Torpedo))
        return static_cast<void*>(const_cast< Torpedo*>(this));
    return PixmapItem::qt_metacast(_clname);
}

int Torpedo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PixmapItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: torpedoExploded(); break;
        case 1: torpedoExecutionFinished(); break;
        case 2: onAnimationLaunchValueChanged((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Torpedo::torpedoExploded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Torpedo::torpedoExecutionFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
