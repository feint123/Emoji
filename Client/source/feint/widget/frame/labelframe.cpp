#include "labelframe.h"
#include "labellabel.h"

#include <QDebug>

LabelFrame::LabelFrame(QWidget *parent):
    QFrame(parent)
{
    edit=new QLineEdit();
    edit->setStyleSheet("border:none;background:#d7d7d7;color:#252526;height:24px;min-width:64px;");
    this->setStyleSheet("background:#d7d7d7;border:none;");
    hb=new QHBoxLayout();
    hb->setContentsMargins(8,0,8,0);
    hb->addWidget(edit);
    connect(edit,SIGNAL(textChanged(QString)),this,SLOT(wantSplite(QString)));
    this->setLayout(hb);
}

void LabelFrame::wantSplite(QString string)
{


    if(string.contains(';')||string.contains("；")){
        if(string.length()>1)
            addLabel();
        this->edit->setText("");
    }
}

void LabelFrame::deletePartOfLableString(QString str)
{
    int index=labelString.indexOf(str);
    labelString.remove(index,index+str.length());
}

void LabelFrame::addLabel()
{
    labelString+=this->edit->text().trimmed();
    LabelLabel *label=new LabelLabel();
    QString lab=this->edit->text().trimmed();
    label->setRealText(lab);
    label->setText(lab.mid(0,this->edit->text().length()-1));
    connect(label,SIGNAL(removeLabel(QString)),this,SLOT(deletePartOfLableString(QString)));
    hb->addWidget(label);
    hb->setDirection(QHBoxLayout::RightToLeft);
}


QString LabelFrame::getLabelString() const
{
    return labelString;
}
