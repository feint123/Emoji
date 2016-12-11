/********************************************************************************
** Form generated from reading UI file 'maincontent.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONTENT_H
#define UI_MAINCONTENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainContent
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *MainContent)
    {
        if (MainContent->objectName().isEmpty())
            MainContent->setObjectName(QStringLiteral("MainContent"));
        MainContent->resize(429, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainContent->sizePolicy().hasHeightForWidth());
        MainContent->setSizePolicy(sizePolicy);
        MainContent->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(MainContent);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(MainContent);

        QMetaObject::connectSlotsByName(MainContent);
    } // setupUi

    void retranslateUi(QWidget *MainContent)
    {
        MainContent->setWindowTitle(QApplication::translate("MainContent", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class MainContent: public Ui_MainContent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONTENT_H
