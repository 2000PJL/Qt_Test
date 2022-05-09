/****************************************************************************
** Meta object code from reading C++ file 'keyboardwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ex06/keyboardwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyboardwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KeyBoardWidget_t {
    QByteArrayData data[15];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeyBoardWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeyBoardWidget_t qt_meta_stringdata_KeyBoardWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "KeyBoardWidget"
QT_MOC_LITERAL(1, 15, 26), // "on_changeWidgetBtn_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 20), // "on_douhaoBtn_clicked"
QT_MOC_LITERAL(4, 64, 17), // "on_dotBtn_clicked"
QT_MOC_LITERAL(5, 82, 18), // "on_baspBtn_clicked"
QT_MOC_LITERAL(6, 101, 18), // "on_hideBtn_clicked"
QT_MOC_LITERAL(7, 120, 23), // "on_zimuShiftBtn_clicked"
QT_MOC_LITERAL(8, 144, 24), // "on_zimuDeleteBtn_clicked"
QT_MOC_LITERAL(9, 169, 22), // "on_numShiftBtn_clicked"
QT_MOC_LITERAL(10, 192, 23), // "on_numDeleteBtn_clicked"
QT_MOC_LITERAL(11, 216, 16), // "slt_focusChanged"
QT_MOC_LITERAL(12, 233, 11), // "slt_timeout"
QT_MOC_LITERAL(13, 245, 21), // "slt_widgetShowTimeout"
QT_MOC_LITERAL(14, 267, 21) // "slt_widgetHideTimeout"

    },
    "KeyBoardWidget\0on_changeWidgetBtn_clicked\0"
    "\0on_douhaoBtn_clicked\0on_dotBtn_clicked\0"
    "on_baspBtn_clicked\0on_hideBtn_clicked\0"
    "on_zimuShiftBtn_clicked\0"
    "on_zimuDeleteBtn_clicked\0"
    "on_numShiftBtn_clicked\0on_numDeleteBtn_clicked\0"
    "slt_focusChanged\0slt_timeout\0"
    "slt_widgetShowTimeout\0slt_widgetHideTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyBoardWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KeyBoardWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KeyBoardWidget *_t = static_cast<KeyBoardWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_changeWidgetBtn_clicked(); break;
        case 1: _t->on_douhaoBtn_clicked(); break;
        case 2: _t->on_dotBtn_clicked(); break;
        case 3: _t->on_baspBtn_clicked(); break;
        case 4: _t->on_hideBtn_clicked(); break;
        case 5: _t->on_zimuShiftBtn_clicked(); break;
        case 6: _t->on_zimuDeleteBtn_clicked(); break;
        case 7: _t->on_numShiftBtn_clicked(); break;
        case 8: _t->on_numDeleteBtn_clicked(); break;
        case 9: _t->slt_focusChanged(); break;
        case 10: _t->slt_timeout(); break;
        case 11: _t->slt_widgetShowTimeout(); break;
        case 12: _t->slt_widgetHideTimeout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject KeyBoardWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_KeyBoardWidget.data,
      qt_meta_data_KeyBoardWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KeyBoardWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyBoardWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KeyBoardWidget.stringdata0))
        return static_cast<void*>(const_cast< KeyBoardWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int KeyBoardWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
