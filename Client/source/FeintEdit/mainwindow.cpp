#include "mainwindow.h"

#include <factory/markdownfactory.h>
#include <factory/menulinefactory.h>

#include <domain/notebook.h>

#include <controller/settingcontroller.h>

#include <QDebug>
#include <QDir>

#include <util/settinghelper.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowIcon(QIcon(":/image/feint.icns"));
    this->resize(800,1000);
    widgetStatus<<0<<0<<0<<0;
    for(int i=0;i<4;i++)
        widgets.append(new QWidget);
    loadController();
}

MainWindow::~MainWindow()
{

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    resizeMenuLine(menu);
    switch(current())
    {
    case 0:
        resizeMarkdown(this->edit);
        break;
    case 1:
        resizeNoteBooks(this->notebooks);
        break;
    case 2:
        break;
    case 3:
        resizeSetting(this->setting);
        break;
    default:
        break;
    }


}

void MainWindow::on_menu_clicked(int i)
{
    setCurrent(i);
}

void MainWindow::loadController()
{
    SettingController *menu=new SettingController(this);
}

void MainWindow::resizeMarkdown(Notes *edit)
{
    edit->setGeometry(this->menu->width(),0,this->width()-this->menu->width(),this->height());
}

void MainWindow::resizeMenuLine(MenuLine *menu)
{
    menu->setGeometry(0,0,menu->width(),this->height());
}

void MainWindow::resizeSetting(SettingDialog *dialog)
{
    dialog->setGeometry(this->menu->width(),0,this->width()-this->menu->width(),this->height());
}

void MainWindow::resizeNoteBooks(Notebooks *books)
{
    books->setGeometry(this->menu->width(),0,this->width()-this->menu->width(),this->height());
}

void MainWindow::setNotebooks(Notebooks *value)
{
    notebooks = value;
    widgetStatus[1]=1;
    widgets[1]=value;
}

Notebooks *MainWindow::getNotebooks() const
{
    return notebooks;
}

void MainWindow::removeUnusedWidget(int used)
{
    for(int i=0;i<widgets.count();i++)
    {
        if(i!=used)
        {
            if(widgetStatus[i]==1){
                widgets[i]->deleteLater();
                widgetStatus[i]=0;
            }
        }
    }
}

SettingDialog *MainWindow::getSetting() const
{
    return setting;
}

void MainWindow::setSetting(SettingDialog *value)
{
    setting = value;
    widgetStatus[3]=1;
    widgets[3]=value;
}

int MainWindow::current() const
{
    return m_current;
}

void MainWindow::setCurrent(int current)
{
    if (m_current == current)
        return;

    m_current = current;
    emit currentChanged(current);
}

MenuLine *MainWindow::getMenu() const
{
    return menu;
}

void MainWindow::setMenu(MenuLine *value)
{
    menu = value;
}

Notes *MainWindow::getEdit() const
{
    return edit;
}

void MainWindow::setEdit(Notes *value)
{
    edit = value;
    widgetStatus[0]=1;
    widgets[0]=edit;
}


