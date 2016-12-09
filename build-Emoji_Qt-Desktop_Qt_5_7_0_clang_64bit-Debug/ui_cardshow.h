/********************************************************************************
** Form generated from reading UI file 'cardshow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDSHOW_H
#define UI_CARDSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardShow
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *CardShow)
    {
        if (CardShow->objectName().isEmpty())
            CardShow->setObjectName(QStringLiteral("CardShow"));
        CardShow->resize(400, 300);
        horizontalLayout = new QHBoxLayout(CardShow);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(CardShow);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);


        retranslateUi(CardShow);

        QMetaObject::connectSlotsByName(CardShow);
    } // setupUi

    void retranslateUi(QWidget *CardShow)
    {
        CardShow->setWindowTitle(QApplication::translate("CardShow", "Form", 0));
        label->setText(QApplication::translate("CardShow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class CardShow: public Ui_CardShow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDSHOW_H
