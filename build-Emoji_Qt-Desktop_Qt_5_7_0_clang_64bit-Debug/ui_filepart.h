/********************************************************************************
** Form generated from reading UI file 'filepart.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPART_H
#define UI_FILEPART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FilePart
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *FilePart)
    {
        if (FilePart->objectName().isEmpty())
            FilePart->setObjectName(QStringLiteral("FilePart"));
        FilePart->resize(400, 300);
        pushButton = new QPushButton(FilePart);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 90, 75, 23));

        retranslateUi(FilePart);

        QMetaObject::connectSlotsByName(FilePart);
    } // setupUi

    void retranslateUi(QDialog *FilePart)
    {
        FilePart->setWindowTitle(QApplication::translate("FilePart", "Dialog", 0));
        pushButton->setText(QApplication::translate("FilePart", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class FilePart: public Ui_FilePart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPART_H
