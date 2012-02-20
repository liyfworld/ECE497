/****************************************************************************
** Meta object code from reading C++ file 'splashitem.h'
**
** Created: Mon Feb 13 23:09:27 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../splashitem.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'splashitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SplashItem[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SplashItem[] = {
    "SplashItem\0\0value\0setValue(qreal)\0"
};

const QMetaObject SplashItem::staticMetaObject = {
    { &QGraphicsWidget::staticMetaObject, qt_meta_stringdata_SplashItem,
      qt_meta_data_SplashItem, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SplashItem::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SplashItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SplashItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SplashItem))
        return static_cast<void*>(const_cast< SplashItem*>(this));
    return QGraphicsWidget::qt_metacast(_clname);
}

int SplashItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setValue((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
