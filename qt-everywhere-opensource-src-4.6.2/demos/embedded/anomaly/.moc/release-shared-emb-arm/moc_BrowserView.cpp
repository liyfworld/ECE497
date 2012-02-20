/****************************************************************************
** Meta object code from reading C++ file 'BrowserView.h'
**
** Created: Mon Feb 13 23:34:20 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/BrowserView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BrowserView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BrowserView[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   33,   12,   12, 0x0a,
      52,   12,   12,   12, 0x0a,
      61,   12,   12,   12, 0x0a,
      71,   12,   12,   12, 0x08,
      84,   12,   12,   12, 0x08,
     100,   92,   12,   12, 0x08,
     117,   12,   12,   12, 0x08,
     130,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BrowserView[] = {
    "BrowserView\0\0menuButtonClicked()\0url\0"
    "navigate(QUrl)\0zoomIn()\0zoomOut()\0"
    "initialize()\0start()\0percent\0"
    "setProgress(int)\0finish(bool)\0"
    "updateTitleBar()\0"
};

const QMetaObject BrowserView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BrowserView,
      qt_meta_data_BrowserView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BrowserView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BrowserView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BrowserView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BrowserView))
        return static_cast<void*>(const_cast< BrowserView*>(this));
    return QWidget::qt_metacast(_clname);
}

int BrowserView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: menuButtonClicked(); break;
        case 1: navigate((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 2: zoomIn(); break;
        case 3: zoomOut(); break;
        case 4: initialize(); break;
        case 5: start(); break;
        case 6: setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: finish((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: updateTitleBar(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void BrowserView::menuButtonClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
