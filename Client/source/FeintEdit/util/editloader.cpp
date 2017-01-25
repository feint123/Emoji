#include "editloader.h"
#include "settinghelper.h"

#include <pane/markdown/markdownmanager.h>

EditLoader::EditLoader(QString note)
{
    this->note=note;
}

void EditLoader::load(MarkDownEdit *edit)
{
    if(!loadLocal(edit))
        loadNet(edit);
}

bool EditLoader::loadLocal(MarkDownEdit *edit)
{
    MarkdownManager *manager=new MarkdownManager();
    manager->load(tr("%1/%2.fei").arg(SettingHelper::workspacing()).arg(this->note));
    QString content=manager->loadContent()->content();

    edit->setText(content);
    edit->refreshFormat();
    return true;
}

bool EditLoader::loadNet(MarkDownEdit *edit)
{

}
