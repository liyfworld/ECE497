/****************************************************************************
** Meta object code from reading C++ file 'webview.h'
**
** Created: Mon Feb 13 23:35:43 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../webview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebPage[] = {

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
      13,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   30,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WebPage[] = {
    "WebPage\0\0url\0loadingUrl(QUrl)\0reply\0"
    "handleUnsupportedContent(QNetworkReply*)\0"
};

const QMetaObject WebPage::staticMetaObject = {
    { &QWebPage::staticMetaObject, qt_meta_stringdata_WebPage,
      qt_meta_data_WebPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebPage))
        return static_cast<void*>(const_cast< WebPage*>(this));
    return QWebPage::qt_metacast(_clname);
}

int WebPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadingUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 1: handleUnsupportedContent((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void WebPage::loadingUrl(const QUrl & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
static const uint qt_meta_data_WebView[] = {

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
      18,    9,    8,    8, 0x08,
      35,    8,    8,    8, 0x08,
      57,   50,    8,    8, 0x08,
      91,   83,    8,    8, 0x08,
     126,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WebView[] = {
    "WebView\0\0progress\0setProgress(int)\0"
    "loadFinished()\0string\0setStatusBarText(QString)\0"
    "request\0downloadRequested(QNetworkRequest)\0"
    "openLinkInNewTab()\0"
};

const QMetaObject WebView::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_WebView,
      qt_meta_data_WebView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WebView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WebView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WebView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebView))
        return static_cast<void*>(const_cast< WebView*>(this));
    return QWebView::qt_metacast(_clname);
}

int WebView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: loadFinished(); break;
        case 2: setStatusBarText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: downloadRequested((*reinterpret_cast< const QNetworkRequest(*)>(_a[1]))); break;
        case 4: openLinkInNewTab(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
