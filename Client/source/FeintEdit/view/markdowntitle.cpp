#include "markdowntitle.h"
#include "ui_markdowntitle.h"

MarkDownTitle::MarkDownTitle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarkDownTitle)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    connect(ui->titleEdit,SIGNAL(textChanged(QString)),this,SLOT(setTitle(QString)));
}

MarkDownTitle::~MarkDownTitle()
{
    delete ui;
}

QString MarkDownTitle::title() const
{
    return ui->titleEdit->text();
}

QString MarkDownTitle::createDate() const
{
    return m_createDate;
}

void MarkDownTitle::setPlaceHolderText(const QString &text)
{
    ui->titleEdit->setPlaceholderText(text);
}

void MarkDownTitle::setTitle(QString title)
{
    m_title = title;
    ui->titleEdit->setText(title);
    emit titleChanged(title);
}

void MarkDownTitle::setCreateDate(QString createDate)
{
    m_createDate = createDate;
    ui->dateLab->setText(createDate);
}
