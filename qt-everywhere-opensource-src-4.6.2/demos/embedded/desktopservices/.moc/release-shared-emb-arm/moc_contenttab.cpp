/****************************************************************************
** Meta object code from reading C++ file 'contenttab.h'
**
** Created: Mon Feb 13 23:33:25 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../contenttab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'contenttab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ContentTab[] = {

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
      17,   12,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ContentTab[] = {
    "ContentTab\0\0item\0openItem(QListWidgetItem*)\0"
};

const QMetaObject ContentTab::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ContentTab,
      qt_meta_data_ContentTab, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ContentTab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ContentTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ContentTab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ContentTab))
        return static_cast<void*>(const_cast< ContentTab*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ContentTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openItem((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
