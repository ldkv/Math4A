/****************************************************************************
** Meta object code from reading C++ file 'GLWidget2D.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/GLWidget2D.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GLWidget2D.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GLWidget2D_t {
    QByteArrayData data[8];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GLWidget2D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GLWidget2D_t qt_meta_stringdata_GLWidget2D = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GLWidget2D"
QT_MOC_LITERAL(1, 11, 10), // "MouseMoved"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "CourbeUpdated"
QT_MOC_LITERAL(4, 37, 13), // "ReleaseButton"
QT_MOC_LITERAL(5, 51, 11), // "timeOutSlot"
QT_MOC_LITERAL(6, 63, 14), // "SetClosedCurve"
QT_MOC_LITERAL(7, 78, 5) // "state"

    },
    "GLWidget2D\0MouseMoved\0\0CourbeUpdated\0"
    "ReleaseButton\0timeOutSlot\0SetClosedCurve\0"
    "state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GLWidget2D[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void GLWidget2D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GLWidget2D *_t = static_cast<GLWidget2D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MouseMoved(); break;
        case 1: _t->CourbeUpdated(); break;
        case 2: _t->ReleaseButton(); break;
        case 3: _t->timeOutSlot(); break;
        case 4: _t->SetClosedCurve((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GLWidget2D::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLWidget2D::MouseMoved)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GLWidget2D::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLWidget2D::CourbeUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GLWidget2D::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GLWidget2D::ReleaseButton)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject GLWidget2D::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget2D.data,
      qt_meta_data_GLWidget2D,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GLWidget2D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GLWidget2D::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget2D.stringdata0))
        return static_cast<void*>(const_cast< GLWidget2D*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int GLWidget2D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
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
void GLWidget2D::MouseMoved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void GLWidget2D::CourbeUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void GLWidget2D::ReleaseButton()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
