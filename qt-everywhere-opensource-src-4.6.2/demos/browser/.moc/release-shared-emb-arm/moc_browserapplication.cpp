/****************************************************************************
** Meta object code from reading C++ file 'browserapplication.h'
**
** Created: Mon Feb 13 23:35:14 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../browserapplication.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'browserapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BrowserApplication[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      39,   19,   20,   19, 0x0a,
      55,   19,   19,   19, 0x0a,
      76,   19,   19,   19, 0x08,
      93,   89,   19,   19, 0x08,
     107,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BrowserApplication[] = {
    "BrowserApplication\0\0BrowserMainWindow*\0"
    "newMainWindow()\0restoreLastSession()\0"
    "postLaunch()\0url\0openUrl(QUrl)\0"
    "newLocalSocketConnection()\0"
};

const QMetaObject BrowserApplication::staticMetaObject = {
    { &QApplication::staticMetaObject, qt_meta_stringdata_BrowserApplication,
      qt_meta_data_BrowserApplication, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BrowserApplication::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BrowserApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BrowserApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BrowserApplication))
        return static_cast<void*>(const_cast< BrowserApplication*>(this));
    return QApplication::qt_metacast(_clname);
}

int BrowserApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { BrowserMainWindow* _r = newMainWindow();
            if (_a[0]) *reinterpret_cast< BrowserMainWindow**>(_a[0]) = _r; }  break;
        case 1: restoreLastSession(); break;
        case 2: postLaunch(); break;
        case 3: openUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 4: newLocalSocketConnection(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
