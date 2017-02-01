#include "setting.h"

Setting::Setting()
{

}

int Setting::fontSize() const
{
    return m_fontSize;
}

QString Setting::fontFamily() const
{
    return m_fontFamily;
}

QString Setting::workspacing() const
{
    return m_workspacing;
}

int Setting::isShareImage() const
{
    return m_isShareImage;
}

int Setting::autoSave() const
{
    return m_autoSave;
}

QString Setting::currentNoteBook() const
{
    return m_currentNote;
}

QString Setting::currentBookName() const
{
    return m_currentBookName;
}

void Setting::setFontSize(int fontSize)
{
    m_fontSize = fontSize;
}

void Setting::setFontFamily(QString fontFamily)
{
    m_fontFamily = fontFamily;
}

void Setting::setWorkspacing(QString workspacing)
{
    m_workspacing = workspacing;
}

void Setting::setIsShareImage(int isShareImage)
{
    m_isShareImage = isShareImage;
}

void Setting::setAutoSave(int autoSave)
{
    m_autoSave = autoSave;
}

void Setting::setCurrentNoteBook(QString currentNote)
{
    m_currentNote = currentNote;
}

void Setting::setCurrentBookName(QString currentBookName)
{
    m_currentBookName = currentBookName;
}
