#ifndef WORD_H
#define WORD_H

#include <qobject.h>



class Word:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString all READ all WRITE setAll)
    Q_PROPERTY(QString collect READ collect WRITE setCollect)
    Q_PROPERTY(QString note READ note WRITE setNote)
    Q_PROPERTY(QString book READ book WRITE setBook)
    Q_PROPERTY(QString markLab READ markLab WRITE setMarkLab)
    Q_PROPERTY(QString markQuick READ markQuick WRITE setMarkQuick)
    Q_PROPERTY(QString read READ read WRITE setRead)
    Q_PROPERTY(QString insert READ insert WRITE setInsert)
    Q_PROPERTY(QString photo READ photo WRITE setPhoto)
    Q_PROPERTY(QString title READ title WRITE setTitle)
    Q_PROPERTY(QString bold READ bold WRITE setBold)
    Q_PROPERTY(QString italic READ italic WRITE setItalic)
    Q_PROPERTY(QString codeBlock READ codeBlock WRITE setCodeBlock)
    Q_PROPERTY(QString del READ del WRITE setDel)
    Q_PROPERTY(QString devide READ devide WRITE setDevide)
    Q_PROPERTY(QString orderList READ orderList WRITE setOrderList)
    Q_PROPERTY(QString unOrderList READ unOrderList WRITE setUnOrderList)
    Q_PROPERTY(QString zoomIn READ zoomIn WRITE setZoomIn)
    Q_PROPERTY(QString zoomOut READ zoomOut WRITE setZoomOut)
    Q_PROPERTY(QString in READ in WRITE setIn)
    Q_PROPERTY(QString out READ out WRITE setOut)
    Q_PROPERTY(QString moveTo READ moveTo WRITE setMoveTo)
    Q_PROPERTY(QString copyTo READ copyTo WRITE setCopyTo)
    Q_PROPERTY(QString new_ READ new_ WRITE setNew_)
    Q_PROPERTY(QString last READ last WRITE setLast)
    Q_PROPERTY(QString edit READ edit WRITE setEdit)
    Q_PROPERTY(QString update READ update WRITE setUpdate)
    Q_PROPERTY(QString message READ message WRITE setMessage)
    Q_PROPERTY(QString recircle READ recircle WRITE setRecircle)
    Q_PROPERTY(QString setting READ setting WRITE setSetting)
    Q_PROPERTY(QString font READ font WRITE setFont)
    Q_PROPERTY(QString size READ size WRITE setSize)
    Q_PROPERTY(QString fontFamily READ fontFamily WRITE setFontFamily)
    Q_PROPERTY(QString file READ file WRITE setFile)
    Q_PROPERTY(QString ok READ ok WRITE setOk)
    Q_PROPERTY(QString share READ share WRITE setShare)
    Q_PROPERTY(QString cancel READ cancel WRITE setCancel)
    Q_PROPERTY(QString remove READ remove WRITE setRemove)
    Q_PROPERTY(QString open READ open WRITE setOpen)
    Q_PROPERTY(QString save READ save WRITE setSave)
    Q_PROPERTY(QString cut READ cut WRITE setCut)
    Q_PROPERTY(QString copy READ copy WRITE setCopy)
    Q_PROPERTY(QString restore READ restore WRITE setRestore)
    Q_PROPERTY(QString preview READ preview WRITE setPreview)
    Q_PROPERTY(QString paste READ paste WRITE setPaste)
    Q_PROPERTY(QString block READ block WRITE setBlock)
    Q_PROPERTY(QString tip_1 READ tip_1 WRITE setTip_1)
    Q_PROPERTY(QString tip_2 READ tip_2 WRITE setTip_2)
    Q_PROPERTY(QString tip_4 READ tip_4 WRITE setTip_4)
    Q_PROPERTY(QString tip_3 READ tip_3 WRITE setTip_3)
    Q_PROPERTY(QString tip_5 READ tip_5 WRITE setTip_5 NOTIFY tip_5Changed)
    Q_PROPERTY(QString tip_6 READ tip_6 WRITE setTip_6)
    Q_PROPERTY(QString tip_7 READ tip_7 WRITE setTip_7)
    Q_PROPERTY(QString tip_8 READ tip_8 WRITE setTip_8)
public:
    Word();

    QString all() const
    {
        return m_all;
    }

    QString note() const
    {
        return m_note;
    }

    QString book() const
    {
        return m_book;
    }

    QString markLab() const
    {
        return m_markLab;
    }

    QString markQuick() const
    {
        return m_markQuick;
    }

    QString read() const
    {
        return m_read;
    }

    QString insert() const
    {
        return m_insert;
    }

    QString photo() const
    {
        return m_photo;
    }

    QString title() const
    {
        return m_title;
    }

    QString bold() const
    {
        return m_bold;
    }

    QString italic() const
    {
        return m_italic;
    }

    QString codeBlock() const
    {
        return m_codeBlock;
    }

    QString del() const
    {
        return m_del;
    }

    QString devide() const
    {
        return m_devide;
    }

    QString orderList() const
    {
        return m_orderList;
    }

    QString unOrderList() const
    {
        return m_unOrderList;
    }

    QString zoomIn() const
    {
        return m_zoomIn;
    }

    QString zoomOut() const
    {
        return m_zoomOut;
    }

    QString in() const
    {
        return m_in;
    }

    QString out() const
    {
        return m_out;
    }

    QString moveTo() const
    {
        return m_moveTo;
    }

    QString copyTo() const
    {
        return m_copyTo;
    }

    QString new_() const
    {
        return m_new_;
    }

    QString last() const
    {
        return m_last;
    }

    QString edit() const
    {
        return m_edit;
    }

    QString update() const
    {
        return m_update;
    }

    QString message() const
    {
        return m_message;
    }

    QString recircle() const
    {
        return m_recircle;
    }

    QString setting() const
    {
        return m_setting;
    }

    QString font() const
    {
        return m_font;
    }

    QString size() const
    {
        return m_size;
    }

    QString fontFamily() const
    {
        return m_fontFamily;
    }

    QString file() const
    {
        return m_file;
    }

    QString ok() const
    {
        return m_ok;
    }

    QString share() const
    {
        return m_share;
    }

    QString cancel() const
    {
        return m_cancel;
    }

    QString remove() const
    {
        return m_remove;
    }

    QString open() const
    {
        return m_open;
    }

    QString save() const
    {
        return m_save;
    }

    QString cut() const
    {
        return m_cut;
    }

    QString copy() const
    {
        return m_copy;
    }

    QString paste() const
    {
        return m_paste;
    }

    QString block() const
    {
        return m_block;
    }

    QString tip_1() const
    {
        return m_tip_1;
    }

    QString tip_2() const
    {
        return m_tip_2;
    }

    QString tip_4() const
    {
        return m_tip_4;
    }

    QString tip_3() const
    {
        return m_tip_3;
    }

    QString tip_5() const
    {
        return m_tip_5;
    }

    QString tip_6() const
    {
        return m_tip_6;
    }

    QString tip_7() const
    {
        return m_tip_7;
    }

    QString tip_8() const
    {
        return m_tip_8;
    }

    QString restore() const
    {
        return m_restore;
    }

    QString preview() const
    {
        return m_preview;
    }

    QString collect() const
    {
        return m_collect;
    }

public slots:
    void setAll(QString all)
    {
        m_all = all;
    }

    void setNote(QString note)
    {
        m_note = note;
    }

    void setBook(QString book)
    {
        m_book = book;
    }

    void setMarkLab(QString markLab)
    {
        m_markLab = markLab;
    }

    void setMarkQuick(QString markQuick)
    {
        m_markQuick = markQuick;
    }

    void setRead(QString read)
    {
        m_read = read;
    }

    void setInsert(QString insert)
    {
        m_insert = insert;
    }

    void setPhoto(QString photo)
    {
        m_photo = photo;
    }

    void setTitle(QString title)
    {
        m_title = title;
    }

    void setBold(QString bold)
    {
        m_bold = bold;
    }

    void setItalic(QString italic)
    {
        m_italic = italic;
    }

    void setCodeBlock(QString codeBlock)
    {
        m_codeBlock = codeBlock;
    }

    void setDel(QString del)
    {
        m_del = del;
    }

    void setDevide(QString devide)
    {
        m_devide = devide;
    }

    void setOrderList(QString orderList)
    {
        m_orderList = orderList;
    }

    void setUnOrderList(QString unOrderList)
    {
        m_unOrderList = unOrderList;
    }

    void setZoomIn(QString zoomIn)
    {
        m_zoomIn = zoomIn;
    }

    void setZoomOut(QString zoomOut)
    {
        m_zoomOut = zoomOut;
    }

    void setIn(QString in)
    {
        m_in = in;
    }

    void setOut(QString out)
    {
        m_out = out;
    }

    void setMoveTo(QString moveTo)
    {
        m_moveTo = moveTo;
    }

    void setCopyTo(QString copyTo)
    {
        m_copyTo = copyTo;
    }

    void setNew_(QString m_new)
    {
        m_new_ = m_new;
    }

    void setLast(QString last)
    {
        m_last = last;
    }

    void setEdit(QString edit)
    {
        m_edit = edit;
    }

    void setUpdate(QString update)
    {
        m_update = update;
    }

    void setMessage(QString message)
    {
        m_message = message;
    }

    void setRecircle(QString recircle)
    {
        m_recircle = recircle;
    }

    void setSetting(QString setting)
    {
        m_setting = setting;
    }

    void setFont(QString font)
    {
        m_font = font;
    }

    void setSize(QString size)
    {
        m_size = size;
    }

    void setFontFamily(QString fontFamily)
    {
        m_fontFamily = fontFamily;
    }

    void setFile(QString file)
    {
        m_file = file;
    }

    void setOk(QString ok)
    {
        m_ok = ok;
    }

    void setShare(QString share)
    {
        m_share = share;
    }

    void setCancel(QString cancel)
    {
        m_cancel = cancel;
    }

    void setRemove(QString remove)
    {
        m_remove = remove;
    }

    void setOpen(QString open)
    {
        m_open = open;
    }

    void setSave(QString save)
    {
        m_save = save;
    }

    void setCut(QString cut)
    {
        m_cut = cut;
    }

    void setCopy(QString copy)
    {
        m_copy = copy;
    }

    void setPaste(QString paste)
    {
        m_paste = paste;
    }

    void setBlock(QString block)
    {
        m_block = block;
    }

    void setTip_1(QString tip_1)
    {
        m_tip_1 = tip_1;
    }

    void setTip_2(QString tip_2)
    {
        m_tip_2 = tip_2;
    }

    void setTip_4(QString tip_4)
    {
        m_tip_4 = tip_4;
    }

    void setTip_3(QString tip_3)
    {
        m_tip_3 = tip_3;
    }

    void setTip_5(QString tip_5)
    {
        if (m_tip_5 == tip_5)
            return;

        m_tip_5 = tip_5;
        emit tip_5Changed(tip_5);
    }

    void setTip_6(QString tip_6)
    {
        m_tip_6 = tip_6;
    }

    void setTip_7(QString tip_7)
    {
        m_tip_7 = tip_7;
    }

    void setTip_8(QString tip_8)
    {
        m_tip_8 = tip_8;
    }

    void setRestore(QString restore)
    {
        m_restore = restore;
    }

    void setPreview(QString preview)
    {
        m_preview = preview;
    }

    void setCollect(QString collect)
    {
        m_collect = collect;
    }

signals:
    void tip_5Changed(QString tip_5);

private:
    QString m_all;
    QString m_note;
    QString m_book;
    QString m_markLab;
    QString m_markQuick;
    QString m_read;
    QString m_insert;
    QString m_photo;
    QString m_title;
    QString m_bold;
    QString m_italic;
    QString m_codeBlock;
    QString m_del;
    QString m_devide;
    QString m_orderList;
    QString m_unOrderList;
    QString m_zoomIn;
    QString m_zoomOut;
    QString m_in;
    QString m_out;
    QString m_moveTo;
    QString m_copyTo;
    QString m_new_;
    QString m_last;
    QString m_edit;
    QString m_update;
    QString m_message;
    QString m_recircle;
    QString m_setting;
    QString m_font;
    QString m_size;
    QString m_fontFamily;
    QString m_file;
    QString m_ok;
    QString m_share;
    QString m_cancel;
    QString m_remove;
    QString m_open;
    QString m_save;
    QString m_cut;
    QString m_copy;
    QString m_paste;
    QString m_block;
    QString m_tip_1;
    QString m_tip_2;
    QString m_tip_4;
    QString m_tip_3;
    QString m_tip_5;
    QString m_tip_6;
    QString m_tip_7;
    QString m_tip_8;
    QString m_restore;
    QString m_preview;
    QString m_collect;
};

#endif // WORD_H
