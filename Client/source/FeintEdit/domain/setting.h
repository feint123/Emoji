#ifndef SETTING_H
#define SETTING_H

#include <QObject>



class Setting:public QObject
{
    Q_OBJECT
    Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize)
    Q_PROPERTY(QString fontFamily READ fontFamily WRITE setFontFamily)
    Q_PROPERTY(QString workspacing READ workspacing WRITE setWorkspacing)
    Q_PROPERTY(int isShareImage READ isShareImage WRITE setIsShareImage)
    Q_PROPERTY(int autoSave READ autoSave WRITE setAutoSave)
    Q_PROPERTY(QString currentNoteBook READ currentNoteBook WRITE setCurrentNoteBook)
    Q_PROPERTY(QString currentBookName READ currentBookName WRITE setCurrentBookName)
    Q_PROPERTY(QString currentNote READ currentNote WRITE setCurrentNote)

private:

    int m_fontSize;

    QString m_fontFamily;

    QString m_workspacing;

    int m_isShareImage;

    int m_autoSave;

    QString m_currentNote;

    QString m_currentBookName;

    QString m_currentBook;

public:
    Setting();
    int fontSize() const;
    QString fontFamily() const;

    QString workspacing() const;

    int isShareImage() const;

    int autoSave() const;

    QString currentNoteBook() const;

    QString currentBookName() const;

    QString currentNote() const
    {
        return m_currentBook;
    }

public slots:
    void setFontSize(int fontSize);
    void setFontFamily(QString fontFamily);
    void setWorkspacing(QString workspacing);
    void setIsShareImage(int isShareImage);
    void setAutoSave(int autoSave);
    void setCurrentNoteBook(QString currentNoteBook);
    void setCurrentBookName(QString currentBookName);
    void setCurrentNote(QString currentBook)
    {
        m_currentBook = currentBook;
    }
};

#endif // SETTING_H
