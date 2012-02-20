/****************************************************************************
** Meta object code from reading C++ file 'addtorrentdialog.h'
**
** Created: Mon Feb 13 23:16:24 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../addtorrentdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addtorrentdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AddTorrentDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   18,   17,   17, 0x0a,
      50,   17,   17,   17, 0x08,
      66,   17,   17,   17, 0x08,
      86,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AddTorrentDialog[] = {
    "AddTorrentDialog\0\0torrentFile\0"
    "setTorrent(QString)\0selectTorrent()\0"
    "selectDestination()\0enableOkButton()\0"
};

const QMetaObject AddTorrentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddTorrentDialog,
      qt_meta_data_AddTorrentDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AddTorrentDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AddTorrentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AddTorrentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AddTorrentDialog))
        return static_cast<void*>(const_cast< AddTorrentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddTorrentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setTorrent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: selectTorrent(); break;
        case 2: selectDestination(); break;
        case 3: enableOkButton(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
