/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenFile;
    QAction *actionOpenDir;
    QAction *actionOut;
    QAction *actionSave;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(752, 492);
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        actionOpenDir = new QAction(MainWindow);
        actionOpenDir->setObjectName(QStringLiteral("actionOpenDir"));
        actionOut = new QAction(MainWindow);
        actionOut->setObjectName(QStringLiteral("actionOut"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 752, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionOpenFile);
        menu->addAction(actionOpenDir);
        menu->addSeparator();
        menu->addAction(actionOut);
        menu->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpenFile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        actionOpenFile->setShortcut(QApplication::translate("MainWindow", "Meta+O", 0));
        actionOpenDir->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", 0));
        actionOpenDir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+O", 0));
        actionOut->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", 0));
        actionOut->setShortcut(QApplication::translate("MainWindow", "Alt+S", 0));
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Meta+S", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        menu_4->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
