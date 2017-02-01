#include "notebooknamedialog.h"
#include "notebooknameitem.h"

#include <util/json/jsondata.h>

#include <util/appcolorhelper.h>
#include <util/qvariantutil.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>

#include <util/graphic/effectutil.h>
#include <util/graphic/innerdialogrect.h>

#include <qpainter.h>
NotebookNameDialog *NotebookNameDialog::dialog=NULL;
NotebookNameDialog::NotebookNameDialog(QWidget *parent):
    QFrame(parent)
{
    //setAutoFillBackground(true);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose);

}

void NotebookNameDialog::setUserTri(bool value)
{
    userTri = value;
}

void NotebookNameDialog::paintEvent(QPaintEvent *event)
{

    if(userTri){
        InnerDialogRect *rect=new InnerDialogRect(InnerDialogRect::UP);
        rect->setTri(tri);
        rect->draw(this,this->width()/3);
    }else{
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QBrush(QColor(240,240,240,240)));
        painter.setPen(QColor(0,0,0,0));
        painter.drawRoundRect(0,0,this->width(),this->height(),5,5);
    }
}

void NotebookNameDialog::resizeEvent(QResizeEvent *event)
{
    list->setGeometry(0,top()+tri,this->width(),this->height()-(top()+bottom()));
}

int NotebookNameDialog::getHeight()
{
    return preHeight;
}

void NotebookNameDialog::createList()
{
    list=new ListView(this);
    list->setScrollHandle(AppColorHelper::scrollHandle());
    list->setScrollPage(AppColorHelper::scrollPage());
    list->createView();
    JsonData *datas=new JsonData(SettingHelper::workPath("notebooks.json").toUtf8(),"notebooks");
    QVariantUtil *util=new QVariantUtil();
    QList<QVariant> itemValues=util->turn<NoteBook>(datas->selectAll<NoteBook>());
    preHeight=itemValues.count()*ScreenFit::fitToScreen(24)
            +ScreenFit::fitToScreen(top())
            +ScreenFit::fitToScreen(bottom())
            +ScreenFit::fitToScreen(tri);

    list->setUnSelectStyle("#noFocus{background:transparent;color:#444;padding-left:16px;}"
                           "#noFocus:hover{background:#3176ff;color:#eee}");
    list->setSelectStyle("#focus{background:transparent;color:#444;padding-left:16px;}"
                         "#focus:hover{background:#3176ff;color:#eee}");
    list->setData(itemValues);
    list->setItem(new NotebookNameItem());
//    list->setGeometry(0,0,this->width(),this->height());
    list->setSpacing(0);
    connect(list,SIGNAL(selectItem(QVariant)),this,SLOT(onListItemDoubleClicked(QVariant)));
}

NotebookNameDialog::~NotebookNameDialog()
{
    dialog=NULL;
}

NotebookNameDialog *NotebookNameDialog::getInstance(QWidget *parent)
{
    if(dialog==NULL)
        dialog=new NotebookNameDialog(parent);
    else if(dialog->parent()!=parent&&parent!=0)
        dialog->setParent(parent);
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

