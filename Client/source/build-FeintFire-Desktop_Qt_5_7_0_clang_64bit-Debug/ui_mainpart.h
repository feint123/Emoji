/********************************************************************************
** Form generated from reading UI file 'mainpart.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPART_H
#define UI_MAINPART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainPart
{
public:
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *MainPart)
    {
        if (MainPart->objectName().isEmpty())
            MainPart->setObjectName(QStringLiteral("MainPart"));
        MainPart->resize(570, 396);
        MainPart->setStyleSheet(QLatin1String("QTabWidget::tab-bar{\n"
"	alignment:center;\n"
"}\n"
"QTabBar::tab{\n"
"	border-bottom:3px solid #eee;\n"
"	min-height:32px;\n"
"	min-width:80px;\n"
"	background:#0076FF;\n"
"	color:white;\n"
"}\n"
"QTabBar::tab:selected{\n"
"	border-bottom:3px solid #b32829;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(MainPart);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(MainPart);

        QMetaObject::connectSlotsByName(MainPart);
    } // setupUi

    void retranslateUi(QWidget *MainPart)
    {
        MainPart->setWindowTitle(QApplication::translate("MainPart", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MainPart: public Ui_MainPart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPART_H
