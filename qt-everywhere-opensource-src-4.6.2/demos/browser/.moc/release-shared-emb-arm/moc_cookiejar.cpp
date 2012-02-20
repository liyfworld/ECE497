/****************************************************************************
** Meta object code from reading C++ file 'cookiejar.h'
**
** Created: Mon Feb 13 23:35:18 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cookiejar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cookiejar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CookieJar[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       5,   34, // properties
       2,   49, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   10,   10,   10, 0x0a,
      36,   10,   10,   10, 0x0a,
      51,   10,   10,   10, 0x08,

 // properties: name, type, flags
      71,   58, 0x0009510b,
      95,   84, 0x0009510b,
     118,  106, 0x0b095103,
     133,  106, 0x0b095103,
     148,  106, 0x0b095103,

 // enums: name, flags, count, data
      58, 0x0,    3,   57,
      84, 0x0,    3,   63,

 // enum data: key, value
     171, uint(CookieJar::AcceptAlways),
     184, uint(CookieJar::AcceptNever),
     196, uint(CookieJar::AcceptOnlyFromSitesNavigatedTo),
     227, uint(CookieJar::KeepUntilExpire),
     243, uint(CookieJar::KeepUntilExit),
     257, uint(CookieJar::KeepUntilTimeLimit),

       0        // eod
};

static const char qt_meta_stringdata_CookieJar[] = {
    "CookieJar\0\0cookiesChanged()\0clear()\0"
    "loadSettings()\0save()\0AcceptPolicy\0"
    "acceptPolicy\0KeepPolicy\0keepPolicy\0"
    "QStringList\0blockedCookies\0allowedCookies\0"
    "allowForSessionCookies\0AcceptAlways\0"
    "AcceptNever\0AcceptOnlyFromSitesNavigatedTo\0"
    "KeepUntilExpire\0KeepUntilExit\0"
    "KeepUntilTimeLimit\0"
};

const QMetaObject CookieJar::staticMetaObject = {
    { &QNetworkCookieJar::staticMetaObject, qt_meta_stringdata_CookieJar,
      qt_meta_data_CookieJar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CookieJar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CookieJar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CookieJar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CookieJar))
        return static_cast<void*>(const_cast< CookieJar*>(this));
    return QNetworkCookieJar::qt_metacast(_clname);
}

int CookieJar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkCookieJar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: cookiesChanged(); break;
        case 1: clear(); break;
        case 2: loadSettings(); break;
        case 3: save(); break;
        default: ;
        }
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< AcceptPolicy*>(_v) = acceptPolicy(); break;
        case 1: *reinterpret_cast< KeepPolicy*>(_v) = keepPolicy(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = blockedCookies(); break;
        case 3: *reinterpret_cast< QStringList*>(_v) = allowedCookies(); break;
        case 4: *reinterpret_cast< QStringList*>(_v) = allowForSessionCookies(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setAcceptPolicy(*reinterpret_cast< AcceptPolicy*>(_v)); break;
        case 1: setKeepPolicy(*reinterpret_cast< KeepPolicy*>(_v)); break;
        case 2: setBlockedCookies(*reinterpret_cast< QStringList*>(_v)); break;
        case 3: setAllowedCookies(*reinterpret_cast< QStringList*>(_v)); break;
        case 4: setAllowForSessionCookies(*reinterpret_cast< QStringList*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void CookieJar::cookiesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_CookieModel[] = {

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
      13,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CookieModel[] = {
    "CookieModel\0\0cookiesChanged()\0"
};

const QMetaObject CookieModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_CookieModel,
      qt_meta_data_CookieModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CookieModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CookieModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CookieModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CookieModel))
        return static_cast<void*>(const_cast< CookieModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int CookieModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: cookiesChanged(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
static const uint qt_meta_data_CookiesDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CookiesDialog[] = {
    "CookiesDialog\0"
};

const QMetaObject CookiesDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CookiesDialog,
      qt_meta_data_CookiesDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CookiesDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CookiesDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CookiesDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CookiesDialog))
        return static_cast<void*>(const_cast< CookiesDialog*>(this));
    if (!strcmp(_clname, "Ui_CookiesDialog"))
        return static_cast< Ui_CookiesDialog*>(const_cast< CookiesDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CookiesDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CookieExceptionsModel[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_CookieExceptionsModel[] = {
    "CookieExceptionsModel\0"
};

const QMetaObject CookieExceptionsModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_CookieExceptionsModel,
      qt_meta_data_CookieExceptionsModel, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CookieExceptionsModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CookieExceptionsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CookieExceptionsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CookieExceptionsModel))
        return static_cast<void*>(const_cast< CookieExceptionsModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int CookieExceptionsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_CookiesExceptionsDialog[] = {

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
      25,   24,   24,   24, 0x08,
      33,   24,   24,   24, 0x08,
      41,   24,   24,   24, 0x08,
      64,   59,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CookiesExceptionsDialog[] = {
    "CookiesExceptionsDialog\0\0block()\0"
    "allow()\0allowForSession()\0text\0"
    "textChanged(QString)\0"
};

const QMetaObject CookiesExceptionsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CookiesExceptionsDialog,
      qt_meta_data_CookiesExceptionsDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CookiesExceptionsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CookiesExceptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CookiesExceptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CookiesExceptionsDialog))
        return static_cast<void*>(const_cast< CookiesExceptionsDialog*>(this));
    if (!strcmp(_clname, "Ui_CookiesExceptionsDialog"))
        return static_cast< Ui_CookiesExceptionsDialog*>(const_cast< CookiesExceptionsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int CookiesExceptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: block(); break;
        case 1: allow(); break;
        case 2: allowForSession(); break;
        case 3: textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
