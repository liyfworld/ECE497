/****************************************************************************
** Meta object code from reading C++ file 'spreadsheet.h'
**
** Created: Mon Feb 13 23:32:01 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../spreadsheet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spreadsheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SpreadSheet[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   13,   12,   12, 0x0a,
      50,   13,   12,   12, 0x0a,
      81,   13,   12,   12, 0x0a,
     115,   12,   12,   12, 0x0a,
     131,   12,   12,   12, 0x0a,
     145,   12,   12,   12, 0x0a,
     158,   12,   12,   12, 0x0a,
     166,   12,   12,   12, 0x0a,
     178,   12,   12,   12, 0x0a,
     186,   12,   12,   12, 0x0a,
     198,   12,   12,   12, 0x0a,
     215,   12,   12,   12, 0x0a,
     227,   12,   12,   12, 0x0a,
     244,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SpreadSheet[] = {
    "SpreadSheet\0\0item\0updateStatus(QTableWidgetItem*)\0"
    "updateColor(QTableWidgetItem*)\0"
    "updateLineEdit(QTableWidgetItem*)\0"
    "returnPressed()\0selectColor()\0"
    "selectFont()\0clear()\0showAbout()\0"
    "print()\0actionSum()\0actionSubtract()\0"
    "actionAdd()\0actionMultiply()\0"
    "actionDivide()\0"
};

const QMetaObject SpreadSheet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SpreadSheet,
      qt_meta_data_SpreadSheet, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SpreadSheet::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SpreadSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SpreadSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SpreadSheet))
        return static_cast<void*>(const_cast< SpreadSheet*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SpreadSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateStatus((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 1: updateColor((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: updateLineEdit((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 3: returnPressed(); break;
        case 4: selectColor(); break;
        case 5: selectFont(); break;
        case 6: clear(); break;
        case 7: showAbout(); break;
        case 8: print(); break;
        case 9: actionSum(); break;
        case 10: actionSubtract(); break;
        case 11: actionAdd(); break;
        case 12: actionMultiply(); break;
        case 13: actionDivide(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
