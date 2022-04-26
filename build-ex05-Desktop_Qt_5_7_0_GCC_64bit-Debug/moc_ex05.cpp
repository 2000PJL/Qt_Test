/****************************************************************************
** Meta object code from reading C++ file 'ex05.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ex05/ex05.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ex05.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ex05_t {
    QByteArrayData data[27];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ex05_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ex05_t qt_meta_stringdata_ex05 = {
    {
QT_MOC_LITERAL(0, 0, 4), // "ex05"
QT_MOC_LITERAL(1, 5, 14), // "tableView_Init"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "slt_timeout1"
QT_MOC_LITERAL(4, 34, 18), // "getCurrentDateTime"
QT_MOC_LITERAL(5, 53, 5), // "char*"
QT_MOC_LITERAL(6, 59, 18), // "slt_serialportRead"
QT_MOC_LITERAL(7, 78, 5), // "sleep"
QT_MOC_LITERAL(8, 84, 4), // "msec"
QT_MOC_LITERAL(9, 89, 13), // "table_add_row"
QT_MOC_LITERAL(10, 103, 4), // "temp"
QT_MOC_LITERAL(11, 108, 3), // "hum"
QT_MOC_LITERAL(12, 112, 8), // "distance"
QT_MOC_LITERAL(13, 121, 7), // "adc_val"
QT_MOC_LITERAL(14, 129, 12), // "compressTemp"
QT_MOC_LITERAL(15, 142, 11), // "currentTemp"
QT_MOC_LITERAL(16, 154, 11), // "compressHum"
QT_MOC_LITERAL(17, 166, 10), // "currentHum"
QT_MOC_LITERAL(18, 177, 12), // "compressDist"
QT_MOC_LITERAL(19, 190, 11), // "currentDist"
QT_MOC_LITERAL(20, 202, 11), // "compressADC"
QT_MOC_LITERAL(21, 214, 10), // "currentADC"
QT_MOC_LITERAL(22, 225, 24), // "on_GetDataButton_clicked"
QT_MOC_LITERAL(23, 250, 28), // "on_connectWIFIButton_clicked"
QT_MOC_LITERAL(24, 279, 29), // "on_connectServeButton_clicked"
QT_MOC_LITERAL(25, 309, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(26, 331, 20) // "on_lmdButton_clicked"

    },
    "ex05\0tableView_Init\0\0slt_timeout1\0"
    "getCurrentDateTime\0char*\0slt_serialportRead\0"
    "sleep\0msec\0table_add_row\0temp\0hum\0"
    "distance\0adc_val\0compressTemp\0currentTemp\0"
    "compressHum\0currentHum\0compressDist\0"
    "currentDist\0compressADC\0currentADC\0"
    "on_GetDataButton_clicked\0"
    "on_connectWIFIButton_clicked\0"
    "on_connectServeButton_clicked\0"
    "on_pushButton_clicked\0on_lmdButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ex05[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       6,    0,   92,    2, 0x08 /* Private */,
       7,    1,   93,    2, 0x08 /* Private */,
       9,    4,   96,    2, 0x08 /* Private */,
      14,    1,  105,    2, 0x08 /* Private */,
      16,    1,  108,    2, 0x08 /* Private */,
      18,    1,  111,    2, 0x08 /* Private */,
      20,    1,  114,    2, 0x08 /* Private */,
      22,    0,  117,    2, 0x08 /* Private */,
      23,    0,  118,    2, 0x08 /* Private */,
      24,    0,  119,    2, 0x08 /* Private */,
      25,    0,  120,    2, 0x08 /* Private */,
      26,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Int, QMetaType::UInt,   10,   11,   12,   13,
    QMetaType::Float, QMetaType::Float,   15,
    QMetaType::Float, QMetaType::Float,   17,
    QMetaType::Double, QMetaType::Double,   19,
    QMetaType::UInt, QMetaType::UInt,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ex05::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ex05 *_t = static_cast<ex05 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tableView_Init(); break;
        case 1: _t->slt_timeout1(); break;
        case 2: { char* _r = _t->getCurrentDateTime();
            if (_a[0]) *reinterpret_cast< char**>(_a[0]) = _r; }  break;
        case 3: _t->slt_serialportRead(); break;
        case 4: _t->sleep((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->table_add_row((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< uint(*)>(_a[4]))); break;
        case 6: { float _r = _t->compressTemp((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 7: { float _r = _t->compressHum((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 8: { double _r = _t->compressDist((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 9: { uint _r = _t->compressADC((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = _r; }  break;
        case 10: _t->on_GetDataButton_clicked(); break;
        case 11: _t->on_connectWIFIButton_clicked(); break;
        case 12: _t->on_connectServeButton_clicked(); break;
        case 13: _t->on_pushButton_clicked(); break;
        case 14: _t->on_lmdButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ex05::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ex05.data,
      qt_meta_data_ex05,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ex05::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ex05::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ex05.stringdata0))
        return static_cast<void*>(const_cast< ex05*>(this));
    return QWidget::qt_metacast(_clname);
}

int ex05::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
