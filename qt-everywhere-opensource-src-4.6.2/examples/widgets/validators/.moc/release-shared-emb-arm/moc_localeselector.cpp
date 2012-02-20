/****************************************************************************
** Meta object code from reading C++ file 'localeselector.h'
**
** Created: Mon Feb 13 23:26:11 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../localeselector.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localeselector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LocaleSelector[] = {

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
      23,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   47,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LocaleSelector[] = {
    "LocaleSelector\0\0locale\0localeSelected(QLocale)\0"
    "index\0emitLocaleSelected(int)\0"
};

const QMetaObject LocaleSelector::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_LocaleSelector,
      qt_meta_data_LocaleSelector, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LocaleSelector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LocaleSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LocaleSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LocaleSelector))
        return static_cast<void*>(const_cast< LocaleSelector*>(this));
    return QComboBox::qt_metacast(_clname);
}

int LocaleSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: localeSelected((*reinterpret_cast< const QLocale(*)>(_a[1]))); break;
        case 1: emitLocaleSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void LocaleSelector::localeSelected(const QLocale & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
