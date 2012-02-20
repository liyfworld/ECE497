/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Feb 13 23:17:44 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      39,   11,   11,   11, 0x0a,
      65,   11,   11,   11, 0x0a,
      92,   11,   11,   11, 0x0a,
     126,   11,   11,   11, 0x0a,
     162,  154,   11,   11, 0x0a,
     209,  187,   11,   11, 0x0a,
     249,  244,   11,   11, 0x0a,
     288,  276,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_clearAction_triggered()\0"
    "on_markAction_triggered()\0"
    "on_printAction_triggered()\0"
    "on_printPreviewAction_triggered()\0"
    "on_unmarkAction_triggered()\0printer\0"
    "printDocument(QPrinter*)\0index,painter,printer\0"
    "printPage(int,QPainter*,QPrinter*)\0"
    "item\0showFont(QTreeWidgetItem*)\0"
    "item,column\0updateStyles(QTreeWidgetItem*,int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_clearAction_triggered(); break;
        case 1: on_markAction_triggered(); break;
        case 2: on_printAction_triggered(); break;
        case 3: on_printPreviewAction_triggered(); break;
        case 4: on_unmarkAction_triggered(); break;
        case 5: printDocument((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        case 6: printPage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QPainter*(*)>(_a[2])),(*reinterpret_cast< QPrinter*(*)>(_a[3]))); break;
        case 7: showFont((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 8: updateStyles((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
