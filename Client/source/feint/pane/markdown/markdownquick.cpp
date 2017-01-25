#include "markdownquick.h"
#include <QDebug>

MarkDownQuick::MarkDownQuick(MarkDownEdit *edit)
{
    this->edit=edit;
    createActions();
    QMenu *qM=new QMenu();
    qM->addActions(actionList);
    edit->addActions(actionList);
    edit->setQuickMenu(qM);
}

int MarkDownQuick::baseSize() const
{
    return m_baseSize;
}

void MarkDownQuick::addHeader1()
{
    addHeaders(1);
}

void MarkDownQuick::addHeader2()
{
    addHeaders(2);
}

void MarkDownQuick::addHeader3()
{
    addHeaders(3);
}

void MarkDownQuick::addHeader4()
{
    addHeaders(4);
}

void MarkDownQuick::addHeader5()
{
    addHeaders(5);
}

void MarkDownQuick::addHeader6()
{
    addHeaders(6);
}

void MarkDownQuick::addBlod()
{
    addDoubel("**");
}

void MarkDownQuick::addItalic()
{
    addDoubel("_");
}

void MarkDownQuick::addCode()
{
    addDoubel("`");
}

void MarkDownQuick::addOrderList()
{
    addBlock("1. ");
}

void MarkDownQuick::addUnOrderList()
{
    addBlock("- ");
}

void MarkDownQuick::addBlock()
{
    if(edit->textCursor().hasSelection())
    {
        QTextCursor cursor=edit->textCursor();
        cursor.setPosition(cursor.selectionStart());
        int end=edit->textCursor().selectionEnd();

        cursor.movePosition(QTextCursor::StartOfBlock);
        cursor.insertText("> ");
        while(cursor.anchor()<=end){
            cursor.movePosition(QTextCursor::NextBlock);
            cursor.insertText("> ");
        }
        edit->setTextCursor(cursor);
    }else
        addBlock("> ");
}


void MarkDownQuick::insertUrl()
{

}

void MarkDownQuick::zoomInEdit()
{
    zoom(true,1);
}

void MarkDownQuick::zoomOutEdit()
{
    zoom(false,1);
}

void MarkDownQuick::addDevide()
{
    QTextCursor cursor=edit->textCursor();
    cursor.insertText("----");
    edit->setTextCursor(cursor);
}

void MarkDownQuick::setBaseSize(int baseSize)
{
    m_baseSize = baseSize;
    emit baseSizeChanged(baseSize);
}

void MarkDownQuick::createActions()
{
    header1=new QAction("#标题");
    header2=new QAction("##标题");
    header3=new QAction("###标题");
    header4=new QAction("####标题");
    header5=new QAction("#####标题");
    header6=new QAction("######标题");
    bold=new QAction("**加粗**");
    italic=new QAction("_斜体_");
    code=new QAction("`代码块`");
    devide=new QAction("----分隔线");
    orderList=new QAction("1. 有序列表");
    unOrderList=new QAction("- 无序列表");
    block=new QAction("> 区块引用");
    image=new QAction("![]插入图片");
    zoomIn=new QAction("放大 ＋");
    zoomOut=new QAction("缩小 －");

    connect(header1,SIGNAL(triggered(bool)),this,SLOT(addHeader1()));
    connect(header2,SIGNAL(triggered(bool)),this,SLOT(addHeader2()));
    connect(header3,SIGNAL(triggered(bool)),this,SLOT(addHeader3()));
    connect(header4,SIGNAL(triggered(bool)),this,SLOT(addHeader4()));
    connect(header6,SIGNAL(triggered(bool)),this,SLOT(addHeader6()));
    connect(header5,SIGNAL(triggered(bool)),this,SLOT(addHeader5()));
    connect(bold,SIGNAL(triggered(bool)),this,SLOT(addBlod()));
    connect(italic,SIGNAL(triggered(bool)),this,SLOT(addItalic()));
    connect(code,SIGNAL(triggered(bool)),this,SLOT(addCode()));
    connect(devide,SIGNAL(triggered(bool)),this,SLOT(addDevide()));
    connect(orderList,SIGNAL(triggered(bool)),this,SLOT(addOrderList()));
    connect(unOrderList,SIGNAL(triggered(bool)),this,SLOT(addUnOrderList()));
    connect(block,SIGNAL(triggered(bool)),this,SLOT(addBlock()));
    connect(image,SIGNAL(triggered(bool)),edit,SLOT(on_insert_image()));
    connect(zoomIn,SIGNAL(triggered(bool)),this,SLOT(zoomInEdit()));
    connect(zoomOut,SIGNAL(triggered(bool)),this,SLOT(zoomOutEdit()));
    addShortCuts();

    actionList.append(header1);
    actionList.append(header2);
    actionList.append(header3);
    actionList.append(header4);
    actionList.append(header5);
    actionList.append(header6);
    actionList.append(bold);
    actionList.append(italic);
    actionList.append(code);
    actionList.append(devide);
    actionList.append(orderList);
    actionList.append(unOrderList);
    actionList.append(block);
    actionList.append(image);
    actionList.append(zoomIn);
    actionList.append(zoomOut);

}

void MarkDownQuick::addHeaders(int level)
{
    int cursorPos=edit->textCursor().anchor();
    QTextCursor cursor=edit->textCursor();
    cursor.movePosition(QTextCursor::StartOfBlock);
    QString h="";
    for(int i=0;i<level;i++)
        h+="#";
    cursor.insertText(h);
    cursor.setPosition(cursorPos+level);
    edit->setTextCursor(cursor);
}

void MarkDownQuick::zoom(bool in, int incre)
{
    int pos= edit->textCursor().anchor();
    edit->selectAll();
    QTextCursor cursor=edit->textCursor();

    QTextCharFormat format=cursor.blockCharFormat();
    if(in){
        setBaseSize(baseSize()+1);
        format.setFontPointSize(baseSize());
    }
    else{
        setBaseSize(baseSize()-1);
        format.setFontPointSize(baseSize());
    }
    cursor.setCharFormat(format);
    cursor.clearSelection();
    cursor.setPosition(pos);
    edit->setTextCursor(cursor);
}

void MarkDownQuick::addShortCuts()
{
    header1->setShortcut(QKeySequence("Ctrl+1"));
    header2->setShortcut(QKeySequence("Ctrl+2"));
    header3->setShortcut(QKeySequence("Ctrl+3"));
    header4->setShortcut(QKeySequence("Ctrl+4"));
    header5->setShortcut(QKeySequence("Ctrl+5"));
    header6->setShortcut(QKeySequence("Ctrl+6"));

    bold->setShortcut(QKeySequence("Ctrl+B"));
    italic->setShortcut(QKeySequence("Ctrl+I"));
    code->setShortcut(QKeySequence("Ctrl+Shift+C"));

    image->setShortcut(QKeySequence("Ctrl+Shift+I"));

    zoomIn->setShortcut(QKeySequence("Ctrl+="));
    zoomOut->setShortcut(QKeySequence("Ctrl+-"));
}

void MarkDownQuick::addDoubel(QString part)
{
    if(edit->textCursor().hasSelection())
    {
        int start=edit->textCursor().selectionStart();
        int end=edit->textCursor().selectionEnd();
        QTextCursor cursor=edit->textCursor();
        cursor.setPosition(start);
        cursor.insertText(part);
        cursor.setPosition(end+part.length());
        cursor.insertText(part);
        edit->setTextCursor(cursor);
    }else
    {
        QTextCursor cursor=edit->textCursor();
        cursor.insertText(part+part);
        cursor.setPosition(cursor.anchor()-part.length());
        edit->setTextCursor(cursor);
    }

}

void MarkDownQuick::addBlock(QString start)
{
    QTextCursor cursor=edit->textCursor();
    int pos=cursor.anchor();
    cursor.movePosition(QTextCursor::StartOfBlock);
    cursor.insertText(start);
    cursor.setPosition(pos+start.length());
    edit->setTextCursor(cursor);
}
