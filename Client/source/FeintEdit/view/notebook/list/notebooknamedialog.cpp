#include "notebooknamedialog.h"
#include "notebooknameitem.h"

#include <util/json/jsondata.h>

#include <util/appcolorhelper.h>
#include <util/qvariantutil.h>
#include <util/screenfit.h>
#include <util/settinghelper.h>
#include <util/stringutil.h>

#include <util/graphic/effectutil.h>
#include <util/graphic/innerdialogrect.h>

#include <qpainter.h>

#include <plug/appstatic.h>
NotebookNameDialog *NotebookNameDialog::dialog=NULL;
NotebookNameDialog::NotebookNameDialog(QWidget *parent):
    QFrame(parent)
{
    //setAutoFillBackground(true);
    title=new QLabel(this);
    title->setStyleSheet(tr("QLabel{color:%1;border:2px solid %1;"
                            "border-left:none;border-top:none;border-right:none;}").arg(AppColorHelper::colorBot()));
    title->setAlignment(Qt::AlignCenter);
    ScreenFit::fitFont(title);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose);

}

QString NotebookNameDialog::getTitle() const
{
    return m_title;
}

void NotebookNameDialog::setTitle(const QString &title)
{
    m_title = title;
    this->title->setText(StringUtil::fitToLength(title,AppStatic::maxTitleLength));
    this->title->setToolTip(title);
}

void NotebookNameDialog::setUserTri(bool value)
{
    userTri = value;
}

void NotebookNameDialog::paintEvent(QPaintEvent *event)
{

    if(userTri){
        InnerDialogRect *rect=new InnerDialogRect(InnerDialogRect::UP);
        rect->setTri(ScreenFit::fitToScreen(tri));
        rect->draw(this,ScreenFit::fitToScreen(tri));
    }else{
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QBrush(QColor(240,240,240,240)));
        painter.setPen(QColor(0,0,0,0));
        painter.drawRoundRect(0,0,this->width(),this->height()
                              ,ScreenFit::fitToScreen(5),ScreenFit::fitToScreen(5));
    }
}

void NotebookNameDialog::resizeEvent(QResizeEvent *event)
{
    title->resize(this->width()*0.8,title->height());
    title->setGeometry((this->width()-title->width())/2,top()+tri,title->width(),title->height());
    list->setGeometry(0,top()+tri+title->height(),this->width(),this->height()-(top()+bottom())-title->height());
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
            +ScreenFit::fitToScreen(tri)+title->height();

    list->setUnSelectStyle("#noFocus{background:transparent;color:#444}"
                           "#noFocus:hover{background:#3176ff;color:#eee}");
    list->setSelectStyle("#focus{background:transparent;color:#444}"
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

