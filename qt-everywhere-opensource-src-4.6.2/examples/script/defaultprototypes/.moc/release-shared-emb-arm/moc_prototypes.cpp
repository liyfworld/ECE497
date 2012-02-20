/****************************************************************************
** Meta object code from reading C++ file 'prototypes.h'
**
** Created: Mon Feb 13 23:29:03 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../prototypes.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prototypes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ListWidgetItemPrototype[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       1,   19, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      33,   24,   25,   24, 0x0a,

 // properties: name, type, flags
      44,   25, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_ListWidgetItemPrototype[] = {
    "ListWidgetItemPrototype\0\0QString\0"
    "toString()\0text\0"
};

const QMetaObject ListWidgetItemPrototype::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ListWidgetItemPrototype,
      qt_meta_data_ListWidgetItemPrototype, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ListWidgetItemPrototype::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ListWidgetItemPrototype::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ListWidgetItemPrototype::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ListWidgetItemPrototype))
        return static_cast<void*>(const_cast< ListWidgetItemPrototype*>(this));
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(const_cast< ListWidgetItemPrototype*>(this));
    return QObject::qt_metacast(_clname);
}

int ListWidgetItemPrototype::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = toString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = text(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setText(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
static const uint qt_meta_data_ListWidgetPrototype[] = {

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
      26,   21,   20,   20, 0x0a,
      49,   43,   20,   20, 0x0a,
      81,   71,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ListWidgetPrototype[] = {
    "ListWidgetPrototype\0\0text\0addItem(QString)\0"
    "texts\0addItems(QStringList)\0colorName\0"
    "setBackgroundColor(QString)\0"
};

const QMetaObject ListWidgetPrototype::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ListWidgetPrototype,
      qt_meta_data_ListWidgetPrototype, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ListWidgetPrototype::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ListWidgetPrototype::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ListWidgetPrototype::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ListWidgetPrototype))
        return static_cast<void*>(const_cast< ListWidgetPrototype*>(this));
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(const_cast< ListWidgetPrototype*>(this));
    return QObject::qt_metacast(_clname);
}

int ListWidgetPrototype::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addItem((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: addItems((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: setBackgroundColor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
