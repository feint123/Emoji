#ifndef APPCOLOR_H
#define APPCOLOR_H

#include <QObject>



class AppColor:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString menuBg READ menuBg WRITE setMenuBg)
    Q_PROPERTY(QString menuCheck READ menuCheck WRITE setMenuCheck)
    Q_PROPERTY(QString noteList READ noteList WRITE setNoteList)
    Q_PROPERTY(QString noteListShadow READ noteListShadow WRITE setNoteListShadow)
    Q_PROPERTY(QString editorBg READ editorBg WRITE setEditorBg)
    Q_PROPERTY(QString editHeaderColor READ editHeaderColor WRITE setEditHeaderColor)
    Q_PROPERTY(QString colorTop READ colorTop WRITE setColorTop)
    Q_PROPERTY(QString colorMid READ colorMid WRITE setColorMid)
    Q_PROPERTY(QString colorBot READ colorBot WRITE setColorBot)
    Q_PROPERTY(QString scrollHandle READ scrollHandle WRITE setScrollHandle)
    Q_PROPERTY(QString scrollPage READ scrollPage WRITE setScrollPage)

public:
    AppColor();

    QString menuBg() const
    {
        return m_menuBg;
    }

    QString menuCheck() const
    {
        return m_menuCheck;
    }

    QString noteList() const
    {
        return m_noteList;
    }

    QString noteListShadow() const
    {
        return m_noteListShadow;
    }

    QString editorBg() const
    {
        return m_editorBg;
    }

    QString editHeaderColor() const
    {
        return m_editHeaderColor;
    }

    QString colorTop() const
    {
        return m_colorTop;
    }

    QString colorMid() const
    {
        return m_colorMid;
    }

    QString colorBot() const
    {
        return m_colorBot;
    }

    QString scrollHandle() const
    {
        return m_scrollHandle;
    }

    QString scrollPage() const
    {
        return m_scrollPage;
    }

public slots:
    void setMenuBg(QString menuBg)
    {
        m_menuBg = menuBg;
    }

    void setMenuCheck(QString menuCheck)
    {
        m_menuCheck = menuCheck;
    }

    void setNoteList(QString noteList)
    {
        m_noteList = noteList;
    }

    void setNoteListShadow(QString noteListShadow)
    {
        m_noteListShadow = noteListShadow;
    }

    void setEditorBg(QString editorBg)
    {
        m_editorBg = editorBg;
    }

    void setEditHeaderColor(QString editHeaderColor)
    {
        m_editHeaderColor = editHeaderColor;
    }

    void setColorTop(QString colorTop)
    {
        m_colorTop = colorTop;
    }

    void setColorMid(QString colorMid)
    {
        m_colorMid = colorMid;
    }

    void setColorBot(QString colorBot)
    {
        m_colorBot = colorBot;
    }

    void setScrollHandle(QString scrollHandle)
    {
        m_scrollHandle = scrollHandle;
    }

    void setScrollPage(QString scrollPage)
    {
        m_scrollPage = scrollPage;
    }

private:

    QString m_menuBg;
    QString m_menuCheck;
    QString m_noteList;
    QString m_noteListShadow;
    QString m_editorBg;
    QString m_editHeaderColor;
    QString m_colorTop;
    QString m_colorMid;
    QString m_colorBot;
    QString m_scrollHandle;
    QString m_scrollPage;
};

#endif // APPCOLOR_H
