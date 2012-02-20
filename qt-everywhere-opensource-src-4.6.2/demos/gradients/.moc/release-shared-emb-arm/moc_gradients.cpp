/****************************************************************************
** Meta object code from reading C++ file 'gradients.h'
**
** Created: Mon Feb 13 23:30:35 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../gradients.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gradients.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ShadeWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_ShadeWidget[] = {
    "ShadeWidget\0\0colorsChanged()\0"
};

const QMetaObject ShadeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ShadeWidget,
      qt_meta_data_ShadeWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ShadeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ShadeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ShadeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShadeWidget))
        return static_cast<void*>(const_cast< ShadeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ShadeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: colorsChanged(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ShadeWidget::colorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_GradientEditor[] = {

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
      22,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GradientEditor[] = {
    "GradientEditor\0\0stops\0"
    "gradientStopsChanged(QGradientStops)\0"
    "pointsUpdated()\0"
};

const QMetaObject GradientEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GradientEditor,
      qt_meta_data_GradientEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GradientEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GradientEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GradientEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GradientEditor))
        return static_cast<void*>(const_cast< GradientEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int GradientEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: gradientStopsChanged((*reinterpret_cast< const QGradientStops(*)>(_a[1]))); break;
        case 1: pointsUpdated(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GradientEditor::gradientStopsChanged(const QGradientStops & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_GradientRenderer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   18,   17,   17, 0x0a,
      57,   17,   17,   17, 0x0a,
      72,   17,   17,   17, 0x0a,
      90,   17,   17,   17, 0x0a,
     109,   17,   17,   17, 0x0a,
     129,   17,   17,   17, 0x0a,
     149,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GradientRenderer[] = {
    "GradientRenderer\0\0stops\0"
    "setGradientStops(QGradientStops)\0"
    "setPadSpread()\0setRepeatSpread()\0"
    "setReflectSpread()\0setLinearGradient()\0"
    "setRadialGradient()\0setConicalGradient()\0"
};

const QMetaObject GradientRenderer::staticMetaObject = {
    { &ArthurFrame::staticMetaObject, qt_meta_stringdata_GradientRenderer,
      qt_meta_data_GradientRenderer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GradientRenderer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GradientRenderer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GradientRenderer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GradientRenderer))
        return static_cast<void*>(const_cast< GradientRenderer*>(this));
    return ArthurFrame::qt_metacast(_clname);
}

int GradientRenderer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ArthurFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setGradientStops((*reinterpret_cast< const QGradientStops(*)>(_a[1]))); break;
        case 1: setPadSpread(); break;
        case 2: setRepeatSpread(); break;
        case 3: setReflectSpread(); break;
        case 4: setLinearGradient(); break;
        case 5: setRadialGradient(); break;
        case 6: setConicalGradient(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
static const uint qt_meta_data_GradientWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      30,   15,   15,   15, 0x0a,
      44,   15,   15,   15, 0x0a,
      58,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GradientWidget[] = {
    "GradientWidget\0\0setDefault1()\0"
    "setDefault2()\0setDefault3()\0setDefault4()\0"
};

const QMetaObject GradientWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GradientWidget,
      qt_meta_data_GradientWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GradientWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GradientWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GradientWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GradientWidget))
        return static_cast<void*>(const_cast< GradientWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GradientWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setDefault1(); break;
        case 1: setDefault2(); break;
        case 2: setDefault3(); break;
        case 3: setDefault4(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
