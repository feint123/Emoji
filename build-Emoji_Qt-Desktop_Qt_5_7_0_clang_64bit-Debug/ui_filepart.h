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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_FilePart
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;

    void setupUi(QDialog *FilePart)
    {
        if (FilePart->objectName().isEmpty())
            FilePart->setObjectName(QStringLiteral("FilePart"));
        FilePart->resize(400, 300);
        FilePart->setStyleSheet(QStringLiteral(""));
        horizontalLayout = new QHBoxLayout(FilePart);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 1, 1, 0);
        frame = new QFrame(FilePart);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("border:none;\n"
"border-top:1px solid #ccc;\n"
"border-right:1px solid #ccc;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);


        retranslateUi(FilePart);

        QMetaObject::connectSlotsByName(FilePart);
    } // setupUi

    void retranslateUi(QDialog *FilePart)
    {
        FilePart->setWindowTitle(QApplication::translate("FilePart", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class FilePart: public Ui_FilePart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPART_H
