/****************************************************************************
** Meta object code from reading C++ file 'submarine.h'
**
** Created: Mon Feb 13 23:32:54 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../submarine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'submarine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SubMarine[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      32,   10,   10,   10, 0x05,
      61,   10,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_SubMarine[] = {
    "SubMarine\0\0subMarineDestroyed()\0"
    "subMarineExecutionFinished()\0"
    "subMarineStateChanged()\0"
};

const QMetaObject SubMarine::staticMetaObject = {
    { &PixmapItem::staticMetaObject, qt_meta_stringdata_SubMarine,
      qt_meta_data_SubMarine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SubMarine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SubMarine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SubMarine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SubMarine))
        return static_cast<void*>(const_cast< SubMarine*>(this));
    return PixmapItem::qt_metacast(_clname);
}

int SubMarine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PixmapItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: subMarineDestroyed(); break;
        case 1: subMarineExecutionFinished(); break;
        case 2: subMarineStateChanged(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SubMarine::subMarineDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void SubMarine::subMarineExecutionFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SubMarine::subMarineStateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
