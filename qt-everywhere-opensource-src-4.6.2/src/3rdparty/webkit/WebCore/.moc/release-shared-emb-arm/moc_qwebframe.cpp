/****************************************************************************
** Meta object code from reading C++ file 'qwebframe.h'
**
** Created: Mon Feb 13 22:56:24 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WebKit/qt/Api/qwebframe.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwebframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QWebFrame[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
      10,   69, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      43,   10,   10,   10, 0x05,
      67,   61,   10,   10, 0x05,
      93,   89,   10,   10, 0x05,
     110,   10,   10,   10, 0x05,
     135,   10,   10,   10, 0x05,
     154,  149,   10,   10, 0x05,
     181,   10,   10,   10, 0x05,
     198,  195,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     239,  226,  217,   10, 0x0a,
     275,  267,   10,   10, 0x0a,

 // properties: name, type, flags
     298,  292, (QMetaType::QReal << 24) | 0x00094103,
     317,  292, (QMetaType::QReal << 24) | 0x00095103,
      61,  328, 0x0a095001,
      89,  336, 0x11095103,
     341,  336, 0x11095001,
     354,  336, 0x11095001,
     368,  362, 0x45095001,
     379,  373, 0x15095001,
     399,  392, 0x19095103,
     419,  414, 0x01095001,

       0        // eod
};

static const char qt_meta_stringdata_QWebFrame[] = {
    "QWebFrame\0\0javaScriptWindowObjectCleared()\0"
    "provisionalLoad()\0title\0titleChanged(QString)\0"
    "url\0urlChanged(QUrl)\0initialLayoutCompleted()\0"
    "iconChanged()\0size\0contentsSizeChanged(QSize)\0"
    "loadStarted()\0ok\0loadFinished(bool)\0"
    "QVariant\0scriptSource\0evaluateJavaScript(QString)\0"
    "printer\0print(QPrinter*)\0qreal\0"
    "textSizeMultiplier\0zoomFactor\0QString\0"
    "QUrl\0requestedUrl\0baseUrl\0QIcon\0icon\0"
    "QSize\0contentsSize\0QPoint\0scrollPosition\0"
    "bool\0focus\0"
};

const QMetaObject QWebFrame::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QWebFrame,
      qt_meta_data_QWebFrame, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QWebFrame::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QWebFrame::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QWebFrame::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWebFrame))
        return static_cast<void*>(const_cast< QWebFrame*>(this));
    return QObject::qt_metacast(_clname);
}

int QWebFrame::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: javaScriptWindowObjectCleared(); break;
        case 1: provisionalLoad(); break;
        case 2: titleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: urlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 4: initialLayoutCompleted(); break;
        case 5: iconChanged(); break;
        case 6: contentsSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 7: loadStarted(); break;
        case 8: loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: { QVariant _r = evaluateJavaScript((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 10: print((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< qreal*>(_v) = textSizeMultiplier(); break;
        case 1: *reinterpret_cast< qreal*>(_v) = zoomFactor(); break;
        case 2: *reinterpret_cast< QString*>(_v) = title(); break;
        case 3: *reinterpret_cast< QUrl*>(_v) = url(); break;
        case 4: *reinterpret_cast< QUrl*>(_v) = requestedUrl(); break;
        case 5: *reinterpret_cast< QUrl*>(_v) = baseUrl(); break;
        case 6: *reinterpret_cast< QIcon*>(_v) = icon(); break;
        case 7: *reinterpret_cast< QSize*>(_v) = contentsSize(); break;
        case 8: *reinterpret_cast< QPoint*>(_v) = scrollPosition(); break;
        case 9: *reinterpret_cast< bool*>(_v) = hasFocus(); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTextSizeMultiplier(*reinterpret_cast< qreal*>(_v)); break;
        case 1: setZoomFactor(*reinterpret_cast< qreal*>(_v)); break;
        case 3: setUrl(*reinterpret_cast< QUrl*>(_v)); break;
        case 8: setScrollPosition(*reinterpret_cast< QPoint*>(_v)); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QWebFrame::javaScriptWindowObjectCleared()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QWebFrame::provisionalLoad()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QWebFrame::titleChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QWebFrame::urlChanged(const QUrl & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QWebFrame::initialLayoutCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QWebFrame::iconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QWebFrame::contentsSizeChanged(const QSize & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QWebFrame::loadStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 7, 0);
}

// SIGNAL 8
void QWebFrame::loadFinished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
