/********************************************************************************
** Form generated from reading UI file 'toolpaint.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLPAINT_H
#define UI_TOOLPAINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolPaint
{
public:

    void setupUi(QWidget *ToolPaint)
    {
        if (ToolPaint->objectName().isEmpty())
            ToolPaint->setObjectName(QStringLiteral("ToolPaint"));
        ToolPaint->resize(296, 390);

        retranslateUi(ToolPaint);

        QMetaObject::connectSlotsByName(ToolPaint);
    } // setupUi

    void retranslateUi(QWidget *ToolPaint)
    {
        ToolPaint->setWindowTitle(QApplication::translate("ToolPaint", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ToolPaint: public Ui_ToolPaint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLPAINT_H
