#include "notebooktool.h"
#include "ui_notebooktool.h"

#include <util/appcolorhelper.h>
#include <util/screenfit.h>

#include <QPainter>

#include <domain/wordstatic.h>

#include <plug/appstatic.h>

NotebookTool::NotebookTool(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NotebookTool)
{
    ui->setupUi(this);
    setObjectName("tool");
    setStyleSheet(tr("#tool{border-image:url(%4)}"
                  "QPushButton{border:none;"
                  "border-image:url(%1);color:%2;padding-left:8px;padding-right:8px;}"
                     "QPushButton:pressed{border-image:url(%3)}")
                  .arg(":/image/tool_btn_normal.png").arg(AppColorHelper::colorBot())
                  .arg(":/image/tool_btn_click.png").arg(":/image/tool_bar.svg"));
    setWindowFlags(Qt::FramelessWindowHint);

    ui->inBookBtn->setText(WordStatic::in+WordStatic::book);
    ui->newBookBtn->setText(WordStatic::new_+WordStatic::book);
    ui->inBookBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ui->newBookBtn->setFixedHeight(ScreenFit::fitToScreen(AppStatic::standardBtnHeight));
    ScreenFit::fitFont(ui->inBookBtn);
    ScreenFit::fitFont(ui->newBookBtn);

    action=new NotebookAction(this);
    connect(this,SIGNAL(newBook(QWidget*)),action,SLOT(newBook(QWidget*)));
    connect(this,SIGNAL(inBook(QWidget*)),action,SLOT(inBook(QWidget*)));

    QMargins m=this->contentsMargins();
    setContentsMargins(m.left(),m.top(),ScreenFit::fitToScreen(32),m.bottom());
}

NotebookTool::~NotebookTool()
{
    delete ui;
}

void NotebookTool::on_newBookBtn_clicked()
{
    emit newBook((QWidget*)this->parent());
}

void NotebookTool::on_inBookBtn_clicked()
{
    emit inBook(this);
}
