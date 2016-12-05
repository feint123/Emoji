/********************************************************************************
** Form generated from reading UI file 'normaltoolpane.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALTOOLPANE_H
#define UI_NORMALTOOLPANE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NormalToolPane
{
public:
    QHBoxLayout *horizontalLayout;
    QToolBox *toolBox;
    QWidget *color;
    QHBoxLayout *horizontalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QWidget *page;
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_2;
    QWidget *page_2;

    void setupUi(QWidget *NormalToolPane)
    {
        if (NormalToolPane->objectName().isEmpty())
            NormalToolPane->setObjectName(QStringLiteral("NormalToolPane"));
        NormalToolPane->resize(249, 556);
        NormalToolPane->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(NormalToolPane);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolBox = new QToolBox(NormalToolPane);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setMaximumSize(QSize(16777215, 16777215));
        toolBox->setToolTipDuration(1);
        toolBox->setStyleSheet(QLatin1String("QToolBox::tab{\n"
"	border:1px solid #333;\n"
"	color:#f9f9f9;\n"
"	background:#404244;\n"
"	min-height:32px;\n"
"	max-height:40px;\n"
"\n"
"}\n"
"QToolBoxButton{\n"
"	min-height:30px;\n"
"}\n"
"QToolBox::tab:selected{\n"
"	font-weight:bold\n"
"}"));
        toolBox->setFrameShadow(QFrame::Plain);
        toolBox->setMidLineWidth(1);
        color = new QWidget();
        color->setObjectName(QStringLiteral("color"));
        color->setGeometry(QRect(0, 0, 249, 466));
        horizontalLayout_2 = new QHBoxLayout(color);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(color);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFocusPolicy(Qt::ClickFocus);
        scrollArea->setStyleSheet(QLatin1String("QScrollArea{border:none;}\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 249, 466));
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral("QWidget{border:none;}"));
        horizontalLayout_3 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFocusPolicy(Qt::ClickFocus);
        frame->setStyleSheet(QLatin1String("QFrame{\n"
"	background:#262829;\n"
"	border:none;\n"
"}\n"
"QFrame:focus{\n"
"	border:2px solid #59a9fb;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(frame);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_2->addWidget(scrollArea);

        toolBox->addItem(color, QString::fromUtf8("\351\242\234\350\211\262"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 249, 466));
        horizontalLayout_4 = new QHBoxLayout(page);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(page);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setStyleSheet(QLatin1String("QScrollArea{border:none;}\n"
""));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 249, 466));
        scrollAreaWidgetContents_2->setStyleSheet(QStringLiteral(""));
        horizontalLayout_5 = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(scrollAreaWidgetContents_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setStyleSheet(QLatin1String("QFrame{\n"
"	background:#262829;\n"
"	border:none;\n"
"}\n"
"QFrame:focus{\n"
"	border:2px solid #59a9fb;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(frame_2);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_4->addWidget(scrollArea_2);

        toolBox->addItem(page, QString::fromUtf8("\345\255\227\344\275\223"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 249, 466));
        toolBox->addItem(page_2, QStringLiteral("Page 2"));

        horizontalLayout->addWidget(toolBox);


        retranslateUi(NormalToolPane);

        toolBox->setCurrentIndex(1);
        toolBox->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(NormalToolPane);
    } // setupUi

    void retranslateUi(QWidget *NormalToolPane)
    {
        NormalToolPane->setWindowTitle(QApplication::translate("NormalToolPane", "Form", 0));
        toolBox->setItemText(toolBox->indexOf(color), QApplication::translate("NormalToolPane", "\351\242\234\350\211\262", 0));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("NormalToolPane", "\345\255\227\344\275\223", 0));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("NormalToolPane", "Page 2", 0));
    } // retranslateUi

};

namespace Ui {
    class NormalToolPane: public Ui_NormalToolPane {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALTOOLPANE_H
