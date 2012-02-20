/****************************************************************************
** Meta object code from reading C++ file 'context2d.h'
**
** Created: Mon Feb 13 23:28:56 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../context2d.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'context2d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Context2D[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   14, // methods
      12,  169, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   10,   10,   10, 0x0a,
      40,   10,   10,   10, 0x0a,
      54,   50,   10,   10, 0x0a,
      79,   73,   10,   10, 0x0a,
      93,   50,   10,   10, 0x0a,
     138,  116,   10,   10, 0x0a,
     185,  116,   10,   10, 0x0a,
     262,  250,  235,   10, 0x0a,
     326,  308,  235,   10, 0x0a,
     392,  384,   10,   10, 0x0a,
     427,  384,   10,   10, 0x0a,
     461,  384,   10,   10, 0x0a,
     497,   10,   10,   10, 0x0a,
     509,   10,   10,   10, 0x0a,
     521,   50,   10,   10, 0x0a,
     541,   50,   10,   10, 0x0a,
     573,  561,   10,   10, 0x0a,
     639,  615,   10,   10, 0x0a,
     709,  690,   10,   10, 0x0a,
     746,  384,   10,   10, 0x0a,
     821,  776,   10,   10, 0x0a,
     861,   10,   10,   10, 0x0a,
     868,   10,   10,   10, 0x0a,
     877,   10,   10,   10, 0x0a,
     889,   50,  884,   10, 0x0a,
     928,  916,   10,   10, 0x0a,
     979,  961,   10,   10, 0x0a,
    1054, 1024,   10,   10, 0x0a,
    1145, 1133, 1123,   10, 0x0a,
    1183,  916,   10,   10, 0x0a,

 // properties: name, type, flags
    1225, 1219, (QMetaType::QReal << 24) | 0x00095103,
    1245, 1237, 0x0a095103,
    1279, 1270, 0xff095103,
    1291, 1270, 0xff095103,
    1301, 1219, (QMetaType::QReal << 24) | 0x00095103,
    1311, 1237, 0x0a095103,
    1319, 1237, 0x0a095103,
    1328, 1219, (QMetaType::QReal << 24) | 0x00095103,
    1339, 1219, (QMetaType::QReal << 24) | 0x00095103,
    1353, 1219, (QMetaType::QReal << 24) | 0x00095103,
    1367, 1219, (QMetaType::QReal << 24) | 0x00095103,
    1378, 1237, 0x0a095103,

       0        // eod
};

static const char qt_meta_stringdata_Context2D[] = {
    "Context2D\0\0image\0changed(QImage)\0"
    "save()\0restore()\0x,y\0scale(qreal,qreal)\0"
    "angle\0rotate(qreal)\0translate(qreal,qreal)\0"
    "m11,m12,m21,m22,dx,dy\0"
    "transform(qreal,qreal,qreal,qreal,qreal,qreal)\0"
    "setTransform(qreal,qreal,qreal,qreal,qreal,qreal)\0"
    "CanvasGradient\0x0,y0,x1,y1\0"
    "createLinearGradient(qreal,qreal,qreal,qreal)\0"
    "x0,y0,r0,x1,y1,r1\0"
    "createRadialGradient(qreal,qreal,qreal,qreal,qreal,qreal)\0"
    "x,y,w,h\0clearRect(qreal,qreal,qreal,qreal)\0"
    "fillRect(qreal,qreal,qreal,qreal)\0"
    "strokeRect(qreal,qreal,qreal,qreal)\0"
    "beginPath()\0closePath()\0moveTo(qreal,qreal)\0"
    "lineTo(qreal,qreal)\0cpx,cpy,x,y\0"
    "quadraticCurveTo(qreal,qreal,qreal,qreal)\0"
    "cp1x,cp1y,cp2x,cp2y,x,y\0"
    "bezierCurveTo(qreal,qreal,qreal,qreal,qreal,qreal)\0"
    "x1,y1,x2,y2,radius\0"
    "arcTo(qreal,qreal,qreal,qreal,qreal)\0"
    "rect(qreal,qreal,qreal,qreal)\0"
    "x,y,radius,startAngle,endAngle,anticlockwise\0"
    "arc(qreal,qreal,qreal,qreal,qreal,bool)\0"
    "fill()\0stroke()\0clip()\0bool\0"
    "isPointInPath(qreal,qreal)\0image,dx,dy\0"
    "drawImage(DomImage*,qreal,qreal)\0"
    "image,dx,dy,dw,dh\0"
    "drawImage(DomImage*,qreal,qreal,qreal,qreal)\0"
    "image,sx,sy,sw,sh,dx,dy,dw,dh\0"
    "drawImage(DomImage*,qreal,qreal,qreal,qreal,qreal,qreal,qreal,qreal)\0"
    "ImageData\0sx,sy,sw,sh\0"
    "getImageData(qreal,qreal,qreal,qreal)\0"
    "putImageData(ImageData,qreal,qreal)\0"
    "qreal\0globalAlpha\0QString\0"
    "globalCompositeOperation\0QVariant\0"
    "strokeStyle\0fillStyle\0lineWidth\0lineCap\0"
    "lineJoin\0miterLimit\0shadowOffsetX\0"
    "shadowOffsetY\0shadowBlur\0shadowColor\0"
};

const QMetaObject Context2D::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Context2D,
      qt_meta_data_Context2D, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Context2D::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Context2D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Context2D::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Context2D))
        return static_cast<void*>(const_cast< Context2D*>(this));
    return QObject::qt_metacast(_clname);
}

int Context2D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changed((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: save(); break;
        case 2: restore(); break;
        case 3: scale((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 4: rotate((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 5: translate((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 6: transform((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6]))); break;
        case 7: setTransform((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6]))); break;
        case 8: { CanvasGradient _r = createLinearGradient((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< CanvasGradient*>(_a[0]) = _r; }  break;
        case 9: { CanvasGradient _r = createRadialGradient((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< CanvasGradient*>(_a[0]) = _r; }  break;
        case 10: clearRect((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 11: fillRect((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 12: strokeRect((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 13: beginPath(); break;
        case 14: closePath(); break;
        case 15: moveTo((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 16: lineTo((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 17: quadraticCurveTo((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 18: bezierCurveTo((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6]))); break;
        case 19: arcTo((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 20: rect((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 21: arc((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 22: fill(); break;
        case 23: stroke(); break;
        case 24: clip(); break;
        case 25: { bool _r = isPointInPath((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 26: drawImage((*reinterpret_cast< DomImage*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 27: drawImage((*reinterpret_cast< DomImage*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5]))); break;
        case 28: drawImage((*reinterpret_cast< DomImage*(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])),(*reinterpret_cast< qreal(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])),(*reinterpret_cast< qreal(*)>(_a[7])),(*reinterpret_cast< qreal(*)>(_a[8])),(*reinterpret_cast< qreal(*)>(_a[9]))); break;
        case 29: { ImageData _r = getImageData((*reinterpret_cast< qreal(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< ImageData*>(_a[0]) = _r; }  break;
        case 30: putImageData((*reinterpret_cast< ImageData(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 31;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = globalAlpha(); break;
        case 1: *reinterpret_cast< QString*>(_v) = globalCompositeOperation(); break;
        case 2: *reinterpret_cast< QVariant*>(_v) = strokeStyle(); break;
        case 3: *reinterpret_cast< QVariant*>(_v) = fillStyle(); break;
        case 4: *reinterpret_cast< qreal*>(_v) = lineWidth(); break;
        case 5: *reinterpret_cast< QString*>(_v) = lineCap(); break;
        case 6: *reinterpret_cast< QString*>(_v) = lineJoin(); break;
        case 7: *reinterpret_cast< qreal*>(_v) = miterLimit(); break;
        case 8: *reinterpret_cast< qreal*>(_v) = shadowOffsetX(); break;
        case 9: *reinterpret_cast< qreal*>(_v) = shadowOffsetY(); break;
        case 10: *reinterpret_cast< qreal*>(_v) = shadowBlur(); break;
        case 11: *reinterpret_cast< QString*>(_v) = shadowColor(); break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setGlobalAlpha(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setGlobalCompositeOperation(*reinterpret_cast< QString*>(_v)); break;
        case 2: setStrokeStyle(*reinterpret_cast< QVariant*>(_v)); break;
        case 3: setFillStyle(*reinterpret_cast< QVariant*>(_v)); break;
        case 4: setLineWidth(*reinterpret_cast< qreal*>(_v)); break;
        case 5: setLineCap(*reinterpret_cast< QString*>(_v)); break;
        case 6: setLineJoin(*reinterpret_cast< QString*>(_v)); break;
        case 7: setMiterLimit(*reinterpret_cast< qreal*>(_v)); break;
        case 8: setShadowOffsetX(*reinterpret_cast< qreal*>(_v)); break;
        case 9: setShadowOffsetY(*reinterpret_cast< qreal*>(_v)); break;
        case 10: setShadowBlur(*reinterpret_cast< qreal*>(_v)); break;
        case 11: setShadowColor(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Context2D::changed(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
