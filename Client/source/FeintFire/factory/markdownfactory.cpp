#include "mainpartfactory.h"
#include "markdownfactory.h"

#include <fileload/articaluploaddialog.h>

#include <graphic/screenhelper.h>

#include <user/settinghelper.h>

MarkDownFactory::MarkDownFactory()
{

}

MarkDown *MarkDownFactory::create(FeintSetting::STYLE style)
{
    QSize screenSize=ScreenHelper::getScreenSize();
    ArticalUploadDialog *upload=new ArticalUploadDialog();
    upload->setWindowFlags(Qt::FramelessWindowHint);
    upload->setAutoFillBackground(false);
    upload->setDelay(42);
    upload->setTypeList(MainPartFactory::createTabList());

    QStringList markIcons;
    markIcons<<":/image/dark/resource/image/dark/share.png"<<
               ":/image/dark/resource/image/dark/new.png"<<
               ":/image/dark/resource/image/dark/file.png"<<
               ":/image/dark/resource/image/dark/save.png"<<
               ":/image/dark/resource/image/dark/save_other.png"<<
               ":/image/dark/resource/image/dark/tip.png";
    //根据每一行的字数来设定编辑器的宽度
    QFont font(SettingHelper::getFontFamily());
    font.setPointSize(SettingHelper::getFontSize());
    QFontMetrics m(font);
    MarkDown *markdown=new MarkDown(0,upload,m.maxWidth()*45);
    markdown->setFont(font);
    markdown->setCachePath(SettingHelper::cachePath());
    markdown->createControlIcon(markIcons);
    markdown->setTitle(markdown->getTitle());
    markdown->createFormat();
    markdown->resize(screenSize.height()*0.8,screenSize.height()*0.85);
    connect(markdown,SIGNAL(startSharing(bool,QString)),upload,SLOT(onshared(bool,QString)));

    return markdown;
}
