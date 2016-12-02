/****************************************************************************
** Meta object code from reading C++ file 'emojilabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Emoji_Qt/view/emojilabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emojilabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EmojiLabel_t {
    QByteArrayData data[10];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmojiLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmojiLabel_t qt_meta_stringdata_EmojiLabel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EmojiLabel"
QT_MOC_LITERAL(1, 11, 9), // "editEmoji"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "setFontSize"
QT_MOC_LITERAL(4, 34, 4), // "size"
QT_MOC_LITERAL(5, 39, 7), // "setFont"
QT_MOC_LITERAL(6, 47, 12), // "setEmojiText"
QT_MOC_LITERAL(7, 60, 9), // "placeText"
QT_MOC_LITERAL(8, 70, 7), // "placeId"
QT_MOC_LITERAL(9, 78, 3) // "ver"

    },
    "EmojiLabel\0editEmoji\0\0setFontSize\0"
    "size\0setFont\0setEmojiText\0placeText\0"
    "placeId\0ver"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmojiLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       6,    1,   46,    2, 0x0a /* Public */,
       7,    2,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QFont,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    8,    9,

       0        // eod
};

void EmojiLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EmojiLabel *_t = static_cast<EmojiLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->editEmoji(); break;
        case 1: _t->setFontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setFont((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 3: _t->setEmojiText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->placeText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EmojiLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EmojiLabel::editEmoji)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject EmojiLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_EmojiLabel.data,
      qt_meta_data_EmojiLabel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EmojiLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmojiLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EmojiLabel.stringdata0))
        return static_cast<void*>(const_cast< EmojiLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int EmojiLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void EmojiLabel::editEmoji()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
