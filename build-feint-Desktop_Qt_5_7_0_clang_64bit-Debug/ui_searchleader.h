/********************************************************************************
** Form generated from reading UI file 'searchleader.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHLEADER_H
#define UI_SEARCHLEADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchLeader
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *SearchLeader)
    {
        if (SearchLeader->objectName().isEmpty())
            SearchLeader->setObjectName(QStringLiteral("SearchLeader"));
        SearchLeader->setWindowModality(Qt::WindowModal);
        SearchLeader->resize(670, 42);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchLeader->sizePolicy().hasHeightForWidth());
        SearchLeader->setSizePolicy(sizePolicy);
        SearchLeader->setMinimumSize(QSize(0, 42));
        SearchLeader->setMaximumSize(QSize(16777215, 42));
        SearchLeader->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"}\n"
"border-bottom:1px solid #ccc;"));
        horizontalLayout = new QHBoxLayout(SearchLeader);
        horizontalLayout->setSpacing(16);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(16, 6, 16, 2);
        pushButton = new QPushButton(SearchLeader);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit = new QLineEdit(SearchLeader);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(250, 28));
        lineEdit->setFocusPolicy(Qt::ClickFocus);
        lineEdit->setStyleSheet(QStringLiteral("border-radius:5px;"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(SearchLeader);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFocusPolicy(Qt::ClickFocus);

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(SearchLeader);

        QMetaObject::connectSlotsByName(SearchLeader);
    } // setupUi

    void retranslateUi(QWidget *SearchLeader)
    {
        SearchLeader->setWindowTitle(QApplication::translate("SearchLeader", "Form", 0));
        pushButton->setText(QApplication::translate("SearchLeader", "\350\217\234\345\215\225", 0));
        pushButton_2->setText(QApplication::translate("SearchLeader", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchLeader: public Ui_SearchLeader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHLEADER_H
