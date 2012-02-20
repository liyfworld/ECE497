/****************************************************************************
** Meta object code from reading C++ file 'imagescaling.h'
**
** Created: Mon Feb 13 23:18:23 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imagescaling.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagescaling.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Images[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      19,   15,    7,    7, 0x0a,
      34,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Images[] = {
    "Images\0\0open()\0num\0showImage(int)\0"
    "finished()\0"
};

const QMetaObject Images::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Images,
      qt_meta_data_Images, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Images::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Images::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Images::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Images))
        return static_cast<void*>(const_cast< Images*>(this));
    return QWidget::qt_metacast(_clname);
}

int Images::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: open(); break;
        case 1: showImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: finished(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
