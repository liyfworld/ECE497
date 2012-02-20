/****************************************************************************
** Meta object code from reading C++ file 'tetrixboard.h'
**
** Created: Mon Feb 13 23:25:55 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tetrixboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tetrixboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TetrixBoard[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,
      43,   37,   12,   12, 0x05,
      70,   61,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      95,   12,   12,   12, 0x0a,
     103,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TetrixBoard[] = {
    "TetrixBoard\0\0score\0scoreChanged(int)\0"
    "level\0levelChanged(int)\0numLines\0"
    "linesRemovedChanged(int)\0start()\0"
    "pause()\0"
};

const QMetaObject TetrixBoard::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_TetrixBoard,
      qt_meta_data_TetrixBoard, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TetrixBoard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TetrixBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TetrixBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TetrixBoard))
        return static_cast<void*>(const_cast< TetrixBoard*>(this));
    return QFrame::qt_metacast(_clname);
}

int TetrixBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scoreChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: levelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: linesRemovedChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: start(); break;
        case 4: pause(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TetrixBoard::scoreChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TetrixBoard::levelChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TetrixBoard::linesRemovedChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
