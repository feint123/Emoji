/****************************************************************************
** Meta object code from reading C++ file 'imagepart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Emoji_Qt/view/imagepart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagepart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImagePart_t {
    QByteArrayData data[12];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImagePart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImagePart_t qt_meta_stringdata_ImagePart = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ImagePart"
QT_MOC_LITERAL(1, 10, 14), // "changeTextSize"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "size"
QT_MOC_LITERAL(4, 31, 14), // "changeTextFont"
QT_MOC_LITERAL(5, 46, 4), // "font"
QT_MOC_LITERAL(6, 51, 6), // "zoomIn"
QT_MOC_LITERAL(7, 58, 7), // "zoomOut"
QT_MOC_LITERAL(8, 66, 11), // "changeColor"
QT_MOC_LITERAL(9, 78, 9), // "colorPart"
QT_MOC_LITERAL(10, 88, 19), // "ToolPart::ColorPart"
QT_MOC_LITERAL(11, 108, 4) // "part"

    },
    "ImagePart\0changeTextSize\0\0size\0"
    "changeTextFont\0font\0zoomIn\0zoomOut\0"
    "changeColor\0colorPart\0ToolPart::ColorPart\0"
    "part"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImagePart[] = {

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
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    2,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QFont,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10,    9,   11,

       0        // eod
};

void ImagePart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImagePart *_t = static_cast<ImagePart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeTextSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeTextFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 2: _t->zoomIn(); break;
        case 3: _t->zoomOut(); break;
        case 4: _t->changeColor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< ToolPart::ColorPart(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject ImagePart::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ImagePart.data,
      qt_meta_data_ImagePart,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImagePart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImagePart::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImagePart.stringdata0))
        return static_cast<void*>(const_cast< ImagePart*>(this));
    return QDialog::qt_metacast(_clname);
}

int ImagePart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
