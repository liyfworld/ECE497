/****************************************************************************
** Meta object code from reading C++ file 'addressbook.h'
**
** Created: Mon Feb 13 23:23:49 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../addressbook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addressbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddressBook[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      26,   12,   12,   12, 0x0a,
      40,   12,   12,   12, 0x0a,
      56,   12,   12,   12, 0x0a,
      65,   12,   12,   12, 0x0a,
      81,   12,   12,   12, 0x0a,
      95,   12,   12,   12, 0x0a,
     102,   12,   12,   12, 0x0a,
     113,   12,   12,   12, 0x0a,
     126,   12,   12,   12, 0x0a,
     141,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_AddressBook[] = {
    "AddressBook\0\0addContact()\0editContact()\0"
    "submitContact()\0cancel()\0removeContact()\0"
    "findContact()\0next()\0previous()\0"
    "saveToFile()\0loadFromFile()\0exportAsVCard()\0"
};

const QMetaObject AddressBook::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddressBook,
      qt_meta_data_AddressBook, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddressBook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddressBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddressBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddressBook))
        return static_cast<void*>(const_cast< AddressBook*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddressBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addContact(); break;
        case 1: editContact(); break;
        case 2: submitContact(); break;
        case 3: cancel(); break;
        case 4: removeContact(); break;
        case 5: findContact(); break;
        case 6: next(); break;
        case 7: previous(); break;
        case 8: saveToFile(); break;
        case 9: loadFromFile(); break;
        case 10: exportAsVCard(); break;
        default: ;
        }
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
