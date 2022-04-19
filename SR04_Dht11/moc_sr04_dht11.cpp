/****************************************************************************
** Meta object code from reading C++ file 'sr04_dht11.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sr04_dht11.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sr04_dht11.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SR04_Dht11_t {
    QByteArrayData data[8];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SR04_Dht11_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SR04_Dht11_t qt_meta_stringdata_SR04_Dht11 = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SR04_Dht11"
QT_MOC_LITERAL(1, 11, 26), // "on_GetDataBuButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 11), // "slt_timeout"
QT_MOC_LITERAL(4, 51, 14), // "tableView_Init"
QT_MOC_LITERAL(5, 66, 18), // "getCurrentDateTime"
QT_MOC_LITERAL(6, 85, 5), // "char*"
QT_MOC_LITERAL(7, 91, 13) // "database_Init"

    },
    "SR04_Dht11\0on_GetDataBuButton_clicked\0"
    "\0slt_timeout\0tableView_Init\0"
    "getCurrentDateTime\0char*\0database_Init"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SR04_Dht11[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       7,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 6,
    QMetaType::Void,

       0        // eod
};

void SR04_Dht11::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SR04_Dht11 *_t = static_cast<SR04_Dht11 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_GetDataBuButton_clicked(); break;
        case 1: _t->slt_timeout(); break;
        case 2: _t->tableView_Init(); break;
        case 3: { char* _r = _t->getCurrentDateTime();
            if (_a[0]) *reinterpret_cast< char**>(_a[0]) = _r; }  break;
        case 4: _t->database_Init(); break;
        default: ;
        }
    }
}

const QMetaObject SR04_Dht11::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SR04_Dht11.data,
      qt_meta_data_SR04_Dht11,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SR04_Dht11::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SR04_Dht11::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SR04_Dht11.stringdata0))
        return static_cast<void*>(const_cast< SR04_Dht11*>(this));
    return QWidget::qt_metacast(_clname);
}

int SR04_Dht11::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
