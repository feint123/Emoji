/********************************************************************************
** Form generated from reading UI file 'cardcell.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDCELL_H
#define UI_CARDCELL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardCell
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *titleLab;
    QLabel *hotLab;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *tipLab;
    QHBoxLayout *horizontalLayout_4;
    QLabel *dateLab;
    QSpacerItem *horizontalSpacer;
    QPushButton *surportBtn;
    QLabel *surportLab;
    QPushButton *collectBtn;

    void setupUi(QWidget *CardCell)
    {
        if (CardCell->objectName().isEmpty())
            CardCell->setObjectName(QStringLiteral("CardCell"));
        CardCell->resize(599, 168);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CardCell->sizePolicy().hasHeightForWidth());
        CardCell->setSizePolicy(sizePolicy);
        CardCell->setStyleSheet(QStringLiteral("border:none;"));
        horizontalLayout = new QHBoxLayout(CardCell);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(CardCell);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(720, 0));
        frame->setMaximumSize(QSize(1000, 200));
        frame->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	color:#aaa;\n"
"	padding:8px;\n"
"}\n"
"#frame{background:#f9f9f9;}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(8);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        titleLab = new QLabel(frame);
        titleLab->setObjectName(QStringLiteral("titleLab"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(titleLab->sizePolicy().hasHeightForWidth());
        titleLab->setSizePolicy(sizePolicy2);
        titleLab->setStyleSheet(QStringLiteral("font-size:14pt;font-weight:bold;"));

        horizontalLayout_2->addWidget(titleLab);

        hotLab = new QLabel(frame);
        hotLab->setObjectName(QStringLiteral("hotLab"));
        sizePolicy2.setHeightForWidth(hotLab->sizePolicy().hasHeightForWidth());
        hotLab->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(hotLab);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tipLab = new QTextEdit(frame);
        tipLab->setObjectName(QStringLiteral("tipLab"));
        tipLab->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tipLab->sizePolicy().hasHeightForWidth());
        tipLab->setSizePolicy(sizePolicy3);
        tipLab->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tipLab->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tipLab->setLineWrapMode(QTextEdit::WidgetWidth);

        horizontalLayout_3->addWidget(tipLab);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        dateLab = new QLabel(frame);
        dateLab->setObjectName(QStringLiteral("dateLab"));
        sizePolicy2.setHeightForWidth(dateLab->sizePolicy().hasHeightForWidth());
        dateLab->setSizePolicy(sizePolicy2);
        dateLab->setStyleSheet(QStringLiteral("font-size:12pt;color:#bbb;"));

        horizontalLayout_4->addWidget(dateLab);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        surportBtn = new QPushButton(frame);
        surportBtn->setObjectName(QStringLiteral("surportBtn"));

        horizontalLayout_4->addWidget(surportBtn);

        surportLab = new QLabel(frame);
        surportLab->setObjectName(QStringLiteral("surportLab"));
        surportLab->setStyleSheet(QStringLiteral("color:#ccc;"));

        horizontalLayout_4->addWidget(surportLab);

        collectBtn = new QPushButton(frame);
        collectBtn->setObjectName(QStringLiteral("collectBtn"));

        horizontalLayout_4->addWidget(collectBtn);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(frame);


        retranslateUi(CardCell);

        QMetaObject::connectSlotsByName(CardCell);
    } // setupUi

    void retranslateUi(QWidget *CardCell)
    {
        CardCell->setWindowTitle(QApplication::translate("CardCell", "Form", 0));
        titleLab->setText(QApplication::translate("CardCell", "Title", 0));
        hotLab->setText(QApplication::translate("CardCell", "hot", 0));
        dateLab->setText(QApplication::translate("CardCell", "Time", 0));
        surportBtn->setText(QApplication::translate("CardCell", "\350\265\236", 0));
        surportLab->setText(QApplication::translate("CardCell", "100", 0));
        collectBtn->setText(QApplication::translate("CardCell", "\346\224\266\350\227\217", 0));
    } // retranslateUi

};

namespace Ui {
    class CardCell: public Ui_CardCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDCELL_H
