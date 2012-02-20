/****************************************************************************
** Meta object code from reading C++ file 'modelmenu.h'
**
** Created: Mon Feb 13 23:35:29 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../modelmenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modelmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ModelMenu[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,
      45,   40,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   10,   10,   10, 0x08,
      83,   76,   10,   10, 0x08,
     103,   76,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ModelMenu[] = {
    "ModelMenu\0\0index\0activated(QModelIndex)\0"
    "text\0hovered(QString)\0aboutToShow()\0"
    "action\0triggered(QAction*)\0hovered(QAction*)\0"
};

const QMetaObject ModelMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_ModelMenu,
      qt_meta_data_ModelMenu, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ModelMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ModelMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ModelMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ModelMenu))
        return static_cast<void*>(const_cast< ModelMenu*>(this));
    return QMenu::qt_metacast(_clname);
}

int ModelMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: hovered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: aboutToShow(); break;
        case 3: triggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: hovered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ModelMenu::activated(const QModelIndex & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModelMenu::hovered(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
