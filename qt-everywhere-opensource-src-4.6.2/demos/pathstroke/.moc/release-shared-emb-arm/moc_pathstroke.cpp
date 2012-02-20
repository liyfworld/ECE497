/****************************************************************************
** Meta object code from reading C++ file 'pathstroke.h'
**
** Created: Mon Feb 13 23:30:44 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../pathstroke.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pathstroke.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PathStrokeRenderer[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       2,   99, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   30,   19,   19, 0x0a,
      66,   56,   19,   19, 0x0a,
      85,   19,   19,   19, 0x0a,
      98,   19,   19,   19, 0x0a,
     113,   19,   19,   19, 0x0a,
     127,   19,   19,   19, 0x0a,
     142,   19,   19,   19, 0x0a,
     157,   19,   19,   19, 0x0a,
     172,   19,   19,   19, 0x0a,
     187,   19,   19,   19, 0x0a,
     201,   19,   19,   19, 0x0a,
     216,   19,   19,   19, 0x0a,
     230,   19,   19,   19, 0x0a,
     243,   19,   19,   19, 0x0a,
     260,   19,   19,   19, 0x0a,
     280,   19,   19,   19, 0x0a,

 // properties: name, type, flags
      56,  300, 0x01095103,
      30,  305, (QMetaType::QReal << 24) | 0x00095003,

       0        // eod
};

static const char qt_meta_stringdata_PathStrokeRenderer[] = {
    "PathStrokeRenderer\0\0clicked()\0penWidth\0"
    "setPenWidth(int)\0animation\0"
    "setAnimation(bool)\0setFlatCap()\0"
    "setSquareCap()\0setRoundCap()\0"
    "setBevelJoin()\0setMiterJoin()\0"
    "setRoundJoin()\0setCurveMode()\0"
    "setLineMode()\0setSolidLine()\0setDashLine()\0"
    "setDotLine()\0setDashDotLine()\0"
    "setDashDotDotLine()\0setCustomDashLine()\0"
    "bool\0qreal\0"
};

const QMetaObject PathStrokeRenderer::staticMetaObject = {
    { &ArthurFrame::staticMetaObject, qt_meta_stringdata_PathStrokeRenderer,
      qt_meta_data_PathStrokeRenderer, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PathStrokeRenderer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PathStrokeRenderer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PathStrokeRenderer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PathStrokeRenderer))
        return static_cast<void*>(const_cast< PathStrokeRenderer*>(this));
    return ArthurFrame::qt_metacast(_clname);
}

int PathStrokeRenderer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ArthurFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked(); break;
        case 1: setPenWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: setAnimation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: setFlatCap(); break;
        case 4: setSquareCap(); break;
        case 5: setRoundCap(); break;
        case 6: setBevelJoin(); break;
        case 7: setMiterJoin(); break;
        case 8: setRoundJoin(); break;
        case 9: setCurveMode(); break;
        case 10: setLineMode(); break;
        case 11: setSolidLine(); break;
        case 12: setDashLine(); break;
        case 13: setDotLine(); break;
        case 14: setDashDotLine(); break;
        case 15: setDashDotDotLine(); break;
        case 16: setCustomDashLine(); break;
        default: ;
        }
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = animation(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = realPenWidth(); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setAnimation(*reinterpret_cast< bool*>(_v)); break;
        case 1: setRealPenWidth(*reinterpret_cast< qreal*>(_v)); break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void PathStrokeRenderer::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_PathStrokeControls[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      32,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   19,   19,   19, 0x08,
      63,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PathStrokeControls[] = {
    "PathStrokeControls\0\0okPressed()\0"
    "quitPressed()\0emitQuitSignal()\0"
    "emitOkSignal()\0"
};

const QMetaObject PathStrokeControls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PathStrokeControls,
      qt_meta_data_PathStrokeControls, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PathStrokeControls::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PathStrokeControls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PathStrokeControls::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PathStrokeControls))
        return static_cast<void*>(const_cast< PathStrokeControls*>(this));
    return QWidget::qt_metacast(_clname);
}

int PathStrokeControls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: okPressed(); break;
        case 1: quitPressed(); break;
        case 2: emitQuitSignal(); break;
        case 3: emitOkSignal(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PathStrokeControls::okPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PathStrokeControls::quitPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
static const uint qt_meta_data_PathStrokeWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      33,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PathStrokeWidget[] = {
    "PathStrokeWidget\0\0showControls()\0"
    "hideControls()\0"
};

const QMetaObject PathStrokeWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PathStrokeWidget,
      qt_meta_data_PathStrokeWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PathStrokeWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PathStrokeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PathStrokeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PathStrokeWidget))
        return static_cast<void*>(const_cast< PathStrokeWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PathStrokeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showControls(); break;
        case 1: hideControls(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
