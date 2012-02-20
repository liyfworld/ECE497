/****************************************************************************
** Meta object code from reading C++ file 'environment.h'
**
** Created: Mon Feb 13 23:28:57 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../environment.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'environment.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Environment[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   39, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   49,   45,   12, 0x0a,
     104,   96,   12,   12, 0x0a,
     123,   49,   45,   12, 0x0a,
     152,   96,   12,   12, 0x0a,

 // properties: name, type, flags
     183,  170, 0x00095009,

       0        // eod
};

static const char qt_meta_stringdata_Environment[] = {
    "Environment\0\0error\0scriptError(QScriptValue)\0"
    "int\0expression,delay\0setInterval(QScriptValue,int)\0"
    "timerId\0clearInterval(int)\0"
    "setTimeout(QScriptValue,int)\0"
    "clearTimeout(int)\0QScriptValue\0document\0"
};

const QMetaObject Environment::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Environment,
      qt_meta_data_Environment, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Environment::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Environment::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Environment::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Environment))
        return static_cast<void*>(const_cast< Environment*>(this));
    return QObject::qt_metacast(_clname);
}

int Environment::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scriptError((*reinterpret_cast< const QScriptValue(*)>(_a[1]))); break;
        case 1: { int _r = setInterval((*reinterpret_cast< const QScriptValue(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: clearInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: { int _r = setTimeout((*reinterpret_cast< const QScriptValue(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: clearTimeout((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QScriptValue*>(_v) = document(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
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

// SIGNAL 0
void Environment::scriptError(const QScriptValue & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_Document[] = {

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
      26,   23,   10,    9, 0x0a,
      55,   50,   10,    9, 0x0a,
     110,   85,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Document[] = {
    "Document\0\0QScriptValue\0id\0"
    "getElementById(QString)\0name\0"
    "getElementsByTagName(QString)\0"
    "type,listener,useCapture\0"
    "addEventListener(QString,QScriptValue,bool)\0"
};

const QMetaObject Document::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Document,
      qt_meta_data_Document, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Document::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Document::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Document::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Document))
        return static_cast<void*>(const_cast< Document*>(this));
    return QObject::qt_metacast(_clname);
}

int Document::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QScriptValue _r = getElementById((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = _r; }  break;
        case 1: { QScriptValue _r = getElementsByTagName((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QScriptValue*>(_a[0]) = _r; }  break;
        case 2: addEventListener((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QScriptValue(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
static const uint qt_meta_data_CanvasGradientPrototype[] = {

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
      38,   25,   24,   24, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CanvasGradientPrototype[] = {
    "CanvasGradientPrototype\0\0offset,color\0"
    "addColorStop(qreal,QString)\0"
};

const QMetaObject CanvasGradientPrototype::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CanvasGradientPrototype,
      qt_meta_data_CanvasGradientPrototype, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CanvasGradientPrototype::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CanvasGradientPrototype::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CanvasGradientPrototype::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CanvasGradientPrototype))
        return static_cast<void*>(const_cast< CanvasGradientPrototype*>(this));
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(const_cast< CanvasGradientPrototype*>(this));
    return QObject::qt_metacast(_clname);
}

int CanvasGradientPrototype::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addColorStop((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
