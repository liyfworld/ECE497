/****************************************************************************
** Meta object code from reading C++ file 'qwebpage.h'
**
** Created: Mon Feb 13 22:34:46 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../WebKit/qt/Api/qwebpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwebpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QWebPage[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       8,  149, // properties
       3,  173, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      33,   24,    9,    9, 0x05,
      54,   51,    9,    9, 0x05,
      96,   73,    9,    9, 0x05,
     138,  133,    9,    9, 0x05,
     164,    9,    9,    9, 0x05,
     189,  183,    9,    9, 0x05,
     219,  214,    9,    9, 0x05,
     260,  250,    9,    9, 0x05,
     305,  284,    9,    9, 0x05,
     336,    9,    9,    9, 0x05,
     359,  183,    9,    9, 0x05,
     390,  386,    9,    9, 0x05,
     416,  408,    9,    9, 0x05,
     455,  408,    9,    9, 0x05,
     496,  408,    9,    9, 0x05,
     541,  535,    9,    9, 0x05,
     584,  576,    9,    9, 0x05,
     619,    9,    9,    9, 0x05,
     639,    9,    9,    9, 0x05,
     676,  657,    9,    9, 0x05,
     729,  718,    9,    9, 0x05,
     782,  183,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     826,    9,  821,    9, 0x0a,
     854,    9,    9,    9, 0x08,
     892,  884,    9,    9, 0x08,
     920,    9,    9,    9, 0x08,

 // properties: name, type, flags
     945,  821, 0x01095001,
     962,  954, 0x0a095001,
     981,  975, 0x15095103,
     994,  975, 0x15095103,
    1016,  821, 0x01095103,
    1063, 1042, 0x0009510b,
    1093, 1084, 0x44095103,
    1101,  821, 0x01095103,

 // enums: name, flags, count, data
    1117, 0x0,    6,  185,
    1132, 0x0,   69,  197,
    1042, 0x0,    3,  335,

 // enum data: key, value
    1142, uint(QWebPage::NavigationTypeLinkClicked),
    1168, uint(QWebPage::NavigationTypeFormSubmitted),
    1196, uint(QWebPage::NavigationTypeBackOrForward),
    1224, uint(QWebPage::NavigationTypeReload),
    1245, uint(QWebPage::NavigationTypeFormResubmitted),
    1275, uint(QWebPage::NavigationTypeOther),
    1295, uint(QWebPage::NoWebAction),
    1307, uint(QWebPage::OpenLink),
    1316, uint(QWebPage::OpenLinkInNewWindow),
    1336, uint(QWebPage::OpenFrameInNewWindow),
    1357, uint(QWebPage::DownloadLinkToDisk),
    1376, uint(QWebPage::CopyLinkToClipboard),
    1396, uint(QWebPage::OpenImageInNewWindow),
    1417, uint(QWebPage::DownloadImageToDisk),
    1437, uint(QWebPage::CopyImageToClipboard),
    1458, uint(QWebPage::Back),
    1463, uint(QWebPage::Forward),
    1471, uint(QWebPage::Stop),
    1476, uint(QWebPage::Reload),
    1483, uint(QWebPage::Cut),
    1487, uint(QWebPage::Copy),
    1492, uint(QWebPage::Paste),
    1498, uint(QWebPage::Undo),
    1503, uint(QWebPage::Redo),
    1508, uint(QWebPage::MoveToNextChar),
    1523, uint(QWebPage::MoveToPreviousChar),
    1542, uint(QWebPage::MoveToNextWord),
    1557, uint(QWebPage::MoveToPreviousWord),
    1576, uint(QWebPage::MoveToNextLine),
    1591, uint(QWebPage::MoveToPreviousLine),
    1610, uint(QWebPage::MoveToStartOfLine),
    1628, uint(QWebPage::MoveToEndOfLine),
    1644, uint(QWebPage::MoveToStartOfBlock),
    1663, uint(QWebPage::MoveToEndOfBlock),
    1680, uint(QWebPage::MoveToStartOfDocument),
    1702, uint(QWebPage::MoveToEndOfDocument),
    1722, uint(QWebPage::SelectNextChar),
    1737, uint(QWebPage::SelectPreviousChar),
    1756, uint(QWebPage::SelectNextWord),
    1771, uint(QWebPage::SelectPreviousWord),
    1790, uint(QWebPage::SelectNextLine),
    1805, uint(QWebPage::SelectPreviousLine),
    1824, uint(QWebPage::SelectStartOfLine),
    1842, uint(QWebPage::SelectEndOfLine),
    1858, uint(QWebPage::SelectStartOfBlock),
    1877, uint(QWebPage::SelectEndOfBlock),
    1894, uint(QWebPage::SelectStartOfDocument),
    1916, uint(QWebPage::SelectEndOfDocument),
    1936, uint(QWebPage::DeleteStartOfWord),
    1954, uint(QWebPage::DeleteEndOfWord),
    1970, uint(QWebPage::SetTextDirectionDefault),
    1994, uint(QWebPage::SetTextDirectionLeftToRight),
    2022, uint(QWebPage::SetTextDirectionRightToLeft),
    2050, uint(QWebPage::ToggleBold),
    2061, uint(QWebPage::ToggleItalic),
    2074, uint(QWebPage::ToggleUnderline),
    2090, uint(QWebPage::InspectElement),
    2105, uint(QWebPage::InsertParagraphSeparator),
    2130, uint(QWebPage::InsertLineSeparator),
    2150, uint(QWebPage::SelectAll),
    2160, uint(QWebPage::ReloadAndBypassCache),
    2181, uint(QWebPage::PasteAndMatchStyle),
    2200, uint(QWebPage::RemoveFormat),
    2213, uint(QWebPage::ToggleStrikethrough),
    2233, uint(QWebPage::ToggleSubscript),
    2249, uint(QWebPage::ToggleSuperscript),
    2267, uint(QWebPage::InsertUnorderedList),
    2287, uint(QWebPage::InsertOrderedList),
    2305, uint(QWebPage::Indent),
    2312, uint(QWebPage::Outdent),
    2320, uint(QWebPage::AlignCenter),
    2332, uint(QWebPage::AlignJustified),
    2347, uint(QWebPage::AlignLeft),
    2357, uint(QWebPage::AlignRight),
    2368, uint(QWebPage::WebActionCount),
    2383, uint(QWebPage::DontDelegateLinks),
    2401, uint(QWebPage::DelegateExternalLinks),
    2423, uint(QWebPage::DelegateAllLinks),

       0        // eod
};

static const char qt_meta_stringdata_QWebPage[] = {
    "QWebPage\0\0loadStarted()\0progress\0"
    "loadProgress(int)\0ok\0loadFinished(bool)\0"
    "link,title,textContent\0"
    "linkHovered(QString,QString,QString)\0"
    "text\0statusBarMessage(QString)\0"
    "selectionChanged()\0frame\0"
    "frameCreated(QWebFrame*)\0geom\0"
    "geometryChangeRequested(QRect)\0dirtyRect\0"
    "repaintRequested(QRect)\0dx,dy,scrollViewRect\0"
    "scrollRequested(int,int,QRect)\0"
    "windowCloseRequested()\0"
    "printRequested(QWebFrame*)\0url\0"
    "linkClicked(QUrl)\0visible\0"
    "toolBarVisibilityChangeRequested(bool)\0"
    "statusBarVisibilityChangeRequested(bool)\0"
    "menuBarVisibilityChangeRequested(bool)\0"
    "reply\0unsupportedContent(QNetworkReply*)\0"
    "request\0downloadRequested(QNetworkRequest)\0"
    "microFocusChanged()\0contentsChanged()\0"
    "frame,databaseName\0"
    "databaseQuotaExceeded(QWebFrame*,QString)\0"
    "frame,item\0"
    "saveFrameStateRequested(QWebFrame*,QWebHistoryItem*)\0"
    "restoreFrameStateRequested(QWebFrame*)\0"
    "bool\0shouldInterruptJavaScript()\0"
    "_q_onLoadProgressChanged(int)\0checked\0"
    "_q_webActionTriggered(bool)\0"
    "_q_cleanupLeakMessages()\0modified\0"
    "QString\0selectedText\0QSize\0viewportSize\0"
    "preferredContentsSize\0forwardUnsupportedContent\0"
    "LinkDelegationPolicy\0linkDelegationPolicy\0"
    "QPalette\0palette\0contentEditable\0"
    "NavigationType\0WebAction\0"
    "NavigationTypeLinkClicked\0"
    "NavigationTypeFormSubmitted\0"
    "NavigationTypeBackOrForward\0"
    "NavigationTypeReload\0NavigationTypeFormResubmitted\0"
    "NavigationTypeOther\0NoWebAction\0"
    "OpenLink\0OpenLinkInNewWindow\0"
    "OpenFrameInNewWindow\0DownloadLinkToDisk\0"
    "CopyLinkToClipboard\0OpenImageInNewWindow\0"
    "DownloadImageToDisk\0CopyImageToClipboard\0"
    "Back\0Forward\0Stop\0Reload\0Cut\0Copy\0"
    "Paste\0Undo\0Redo\0MoveToNextChar\0"
    "MoveToPreviousChar\0MoveToNextWord\0"
    "MoveToPreviousWord\0MoveToNextLine\0"
    "MoveToPreviousLine\0MoveToStartOfLine\0"
    "MoveToEndOfLine\0MoveToStartOfBlock\0"
    "MoveToEndOfBlock\0MoveToStartOfDocument\0"
    "MoveToEndOfDocument\0SelectNextChar\0"
    "SelectPreviousChar\0SelectNextWord\0"
    "SelectPreviousWord\0SelectNextLine\0"
    "SelectPreviousLine\0SelectStartOfLine\0"
    "SelectEndOfLine\0SelectStartOfBlock\0"
    "SelectEndOfBlock\0SelectStartOfDocument\0"
    "SelectEndOfDocument\0DeleteStartOfWord\0"
    "DeleteEndOfWord\0SetTextDirectionDefault\0"
    "SetTextDirectionLeftToRight\0"
    "SetTextDirectionRightToLeft\0ToggleBold\0"
    "ToggleItalic\0ToggleUnderline\0"
    "InspectElement\0InsertParagraphSeparator\0"
    "InsertLineSeparator\0SelectAll\0"
    "ReloadAndBypassCache\0PasteAndMatchStyle\0"
    "RemoveFormat\0ToggleStrikethrough\0"
    "ToggleSubscript\0ToggleSuperscript\0"
    "InsertUnorderedList\0InsertOrderedList\0"
    "Indent\0Outdent\0AlignCenter\0AlignJustified\0"
    "AlignLeft\0AlignRight\0WebActionCount\0"
    "DontDelegateLinks\0DelegateExternalLinks\0"
    "DelegateAllLinks\0"
};

const QMetaObject QWebPage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QWebPage,
      qt_meta_data_QWebPage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QWebPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QWebPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QWebPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QWebPage))
        return static_cast<void*>(const_cast< QWebPage*>(this));
    return QObject::qt_metacast(_clname);
}

int QWebPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadStarted(); break;
        case 1: loadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: linkHovered((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 4: statusBarMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: selectionChanged(); break;
        case 6: frameCreated((*reinterpret_cast< QWebFrame*(*)>(_a[1]))); break;
        case 7: geometryChangeRequested((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 8: repaintRequested((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 9: scrollRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRect(*)>(_a[3]))); break;
        case 10: windowCloseRequested(); break;
        case 11: printRequested((*reinterpret_cast< QWebFrame*(*)>(_a[1]))); break;
        case 12: linkClicked((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 13: toolBarVisibilityChangeRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: statusBarVisibilityChangeRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: menuBarVisibilityChangeRequested((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: unsupportedContent((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 17: downloadRequested((*reinterpret_cast< const QNetworkRequest(*)>(_a[1]))); break;
        case 18: microFocusChanged(); break;
        case 19: contentsChanged(); break;
        case 20: databaseQuotaExceeded((*reinterpret_cast< QWebFrame*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 21: saveFrameStateRequested((*reinterpret_cast< QWebFrame*(*)>(_a[1])),(*reinterpret_cast< QWebHistoryItem*(*)>(_a[2]))); break;
        case 22: restoreFrameStateRequested((*reinterpret_cast< QWebFrame*(*)>(_a[1]))); break;
        case 23: { bool _r = shouldInterruptJavaScript();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: d->_q_onLoadProgressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: d->_q_webActionTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: d->_q_cleanupLeakMessages(); break;
        default: ;
        }
        _id -= 27;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isModified(); break;
        case 1: *reinterpret_cast< QString*>(_v) = selectedText(); break;
        case 2: *reinterpret_cast< QSize*>(_v) = viewportSize(); break;
        case 3: *reinterpret_cast< QSize*>(_v) = preferredContentsSize(); break;
        case 4: *reinterpret_cast< bool*>(_v) = forwardUnsupportedContent(); break;
        case 5: *reinterpret_cast< LinkDelegationPolicy*>(_v) = linkDelegationPolicy(); break;
        case 6: *reinterpret_cast< QPalette*>(_v) = palette(); break;
        case 7: *reinterpret_cast< bool*>(_v) = isContentEditable(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 2: setViewportSize(*reinterpret_cast< QSize*>(_v)); break;
        case 3: setPreferredContentsSize(*reinterpret_cast< QSize*>(_v)); break;
        case 4: setForwardUnsupportedContent(*reinterpret_cast< bool*>(_v)); break;
        case 5: setLinkDelegationPolicy(*reinterpret_cast< LinkDelegationPolicy*>(_v)); break;
        case 6: setPalette(*reinterpret_cast< QPalette*>(_v)); break;
        case 7: setContentEditable(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QWebPage::loadStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QWebPage::loadProgress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QWebPage::loadFinished(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QWebPage::linkHovered(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QWebPage::statusBarMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QWebPage::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QWebPage::frameCreated(QWebFrame * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void QWebPage::geometryChangeRequested(const QRect & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QWebPage::repaintRequested(const QRect & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void QWebPage::scrollRequested(int _t1, int _t2, const QRect & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QWebPage::windowCloseRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 10, 0);
}

// SIGNAL 11
void QWebPage::printRequested(QWebFrame * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QWebPage::linkClicked(const QUrl & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QWebPage::toolBarVisibilityChangeRequested(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void QWebPage::statusBarVisibilityChangeRequested(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void QWebPage::menuBarVisibilityChangeRequested(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void QWebPage::unsupportedContent(QNetworkReply * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void QWebPage::downloadRequested(const QNetworkRequest & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void QWebPage::microFocusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, 0);
}

// SIGNAL 19
void QWebPage::contentsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, 0);
}

// SIGNAL 20
void QWebPage::databaseQuotaExceeded(QWebFrame * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void QWebPage::saveFrameStateRequested(QWebFrame * _t1, QWebHistoryItem * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void QWebPage::restoreFrameStateRequested(QWebFrame * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}
QT_END_MOC_NAMESPACE
