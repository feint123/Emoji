/********************************************************************************
** Form generated from reading UI file 'cardwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDWIDGET_H
#define UI_CARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLab;
    QLabel *tipLab;
    QHBoxLayout *horizontalLayout;
    QLabel *hotLab;
    QLabel *dateLab;

    void setupUi(QWidget *CardWidget)
    {
        if (CardWidget->objectName().isEmpty())
            CardWidget->setObjectName(QStringLiteral("CardWidget"));
        CardWidget->resize(454, 150);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CardWidget->sizePolicy().hasHeightForWidth());
        CardWidget->setSizePolicy(sizePolicy);
        CardWidget->setMinimumSize(QSize(0, 150));
        CardWidget->setStyleSheet(QStringLiteral("QWidget{background:white;padding:8px;}"));
        verticalLayout = new QVBoxLayout(CardWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleLab = new QLabel(CardWidget);
        titleLab->setObjectName(QStringLiteral("titleLab"));

        verticalLayout->addWidget(titleLab);

        tipLab = new QLabel(CardWidget);
        tipLab->setObjectName(QStringLiteral("tipLab"));

        verticalLayout->addWidget(tipLab);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        hotLab = new QLabel(CardWidget);
        hotLab->setObjectName(QStringLiteral("hotLab"));

        horizontalLayout->addWidget(hotLab);

        dateLab = new QLabel(CardWidget);
        dateLab->setObjectName(QStringLiteral("dateLab"));

        horizontalLayout->addWidget(dateLab);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CardWidget);

        QMetaObject::connectSlotsByName(CardWidget);
    } // setupUi

    void retranslateUi(QWidget *CardWidget)
    {
        CardWidget->setWindowTitle(QApplication::translate("CardWidget", "Form", 0));
        titleLab->setText(QApplication::translate("CardWidget", "TextLabel", 0));
        tipLab->setText(QApplication::translate("CardWidget", "TextLabel", 0));
        hotLab->setText(QApplication::translate("CardWidget", "TextLabel", 0));
        dateLab->setText(QApplication::translate("CardWidget", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class CardWidget: public Ui_CardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDWIDGET_H
