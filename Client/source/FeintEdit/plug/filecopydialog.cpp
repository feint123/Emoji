#include "filecopydialog.h"

#include <QFileSystemWatcher>
#include <QPainter>

#include <util/settinghelper.h>

FileCopyDialog::FileCopyDialog(QWidget *parent):
    QFrame(parent)
{
    connect(this,SIGNAL(fileNameChanged(QString)),this,SLOT(update()));
    resize(800,80);
}

QString FileCopyDialog::fileName() const
{
    return m_fileName;
}

void FileCopyDialog::setFileName(QString fileName)
{
    if (m_fileName == fileName)
        return;

    m_fileName = fileName;
    emit fileNameChanged(fileName);
}

void FileCopyDialog::setDir(QString dir)
{
    QFileSystemWatcher *watcher=new QFileSystemWatcher;
    watcher->addPath(dir);
    connect(watcher,SIGNAL(directoryChanged(QString)),this,SLOT(setFileName(QString)));
}

void FileCopyDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QFont font;
    font.setPointSize(SettingHelper::fontSize());
    painter.setFont(font);
    painter.drawText(height()/2,height()/2+QFontMetrics(font).height()/2,fileName());
    QBrush brush;
    brush.setColor(QColor(220,220,220,220));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(QColor(0,0,0,0));
    painter.drawRect(0,0,this->width(),this->height());
}
