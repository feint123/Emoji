/********************************************************************************
** Form generated from reading UI file 'articalarea.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICALAREA_H
#define UI_ARTICALAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticalArea
{
public:

    void setupUi(QWidget *ArticalArea)
    {
        if (ArticalArea->objectName().isEmpty())
            ArticalArea->setObjectName(QStringLiteral("ArticalArea"));
        ArticalArea->resize(684, 580);

        retranslateUi(ArticalArea);

        QMetaObject::connectSlotsByName(ArticalArea);
    } // setupUi

    void retranslateUi(QWidget *ArticalArea)
    {
        ArticalArea->setWindowTitle(QApplication::translate("ArticalArea", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class ArticalArea: public Ui_ArticalArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICALAREA_H
