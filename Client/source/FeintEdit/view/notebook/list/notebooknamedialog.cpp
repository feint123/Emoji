#include "notebooknamedialog.h"
#include "notebooknameitem.h"

#include <util/json/jsondata.h>

#include <util/qvariantutil.h>
#include <util/settinghelper.h>

#include <util/graphic/effectutil.h>

#include <qpainter.h>
NotebookNameDialog *NotebookNameDialog::dialog=NULL;
NotebookNameDialog::NotebookNameDialog(QWidget *parent):
    QFrame(parent)
{
    //setAutoFillBackground(true);
}

void NotebookNameDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor(240,240,240,200)));
    painter.setPen(QColor(0,0,0,0));
    painter.drawRoundRect(0,0,this->width(),this->height(),5,5);
}

void NotebookNameDialog::resizeEvent(QResizeEvent *event)
{
    list->setGeometry(0,top(),this->width(),this->height()-(top()+bottom()));
}

int NotebookNameDialog::getHeight()
{
    return preHeight;
}

void NotebookNameDialog::createList()
{
    list=new ListView(this);
    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    QVariantUtil *util=new QVariantUtil();
    QList<QVariant> itemValues=util->turn<NoteBook>(datas->selectAll<NoteBook>());
    preHeight=itemValues.count()*24+top()+bottom();
    list->setSelectStyle("#focus{background:#2064db;color:#f9f9f9;padding-left:16px;}");
    list->setUnSelectStyle("#noFocus{background:transparent;color:#444;padding-left:16px;}"
                           "#noFocus:hover{background:#3176ff;color:#eee}");
    list->setData(itemValues);
    list->setItem(new NotebookNameItem());
//    list->setGeometry(0,0,this->width(),this->height());
    list->setSpacing(0);
    connect(list,SIGNAL(selectItemDouble(QVariant)),this,SLOT(onListItemDoubleClicked(QVariant)));
}

NotebookNameDialog::~NotebookNameDialog()
{
    dialog=NULL;
}

NotebookNameDialog *NotebookNameDialog::getInstance(QWidget *parent)
{
    if(dialog==NULL)
        dialog=new NotebookNameDialog(parent);
    return dialog;
}

int NotebookNameDialog::top() const
{
    return m_top;
}

int NotebookNameDialog::bottom() const
{
    return m_bottom;
}

void NotebookNameDialog::setTop(int top)
{
    m_top = top;
}

void NotebookNameDialog::setBottom(int bottom)
{
    m_bottom = bottom;
}

void NotebookNameDialog::onListItemDoubleClicked(QVariant item)
{
    NoteBook book=qvariant_cast<NoteBook>(item);
    emit bookClicked(&book);
}

