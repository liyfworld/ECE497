/****************************************************************************
** Meta object code from reading C++ file 'Tracking.h'
**
** Created: Mon Feb 20 02:54:43 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Tracking.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tracking.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tracking[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x05,
      49,   10,    9,    9, 0x05,
      88,   81,    9,    9, 0x05,
     116,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     127,    9,    9,    9, 0x0a,
     147,  141,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tracking[] = {
    "Tracking\0\0image\0updateDepthImage(unsigned char*)\0"
    "updateMaskImage(unsigned char*)\0x,y,id\0"
    "addPoint(uint,uint,JointID)\0shutdown()\0"
    "updateFrame()\0state\0recordOrStop(bool)\0"
};

const QMetaObject Tracking::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tracking,
      qt_meta_data_Tracking, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tracking::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tracking::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tracking::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tracking))
        return static_cast<void*>(const_cast< Tracking*>(this));
    return QObject::qt_metacast(_clname);
}

int Tracking::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateDepthImage((*reinterpret_cast< unsigned char*(*)>(_a[1]))); break;
        case 1: updateMaskImage((*reinterpret_cast< unsigned char*(*)>(_a[1]))); break;
        case 2: addPoint((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< JointID(*)>(_a[3]))); break;
        case 3: shutdown(); break;
        case 4: updateFrame(); break;
        case 5: recordOrStop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Tracking::updateDepthImage(unsigned char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tracking::updateMaskImage(unsigned char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Tracking::addPoint(unsigned int _t1, unsigned int _t2, JointID _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Tracking::shutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
