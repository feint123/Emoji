#include "plughelper.h"
#include "wordhelper.h"

#include <domain/word.h>
#include <domain/wordstatic.h>

WordHelper::WordHelper()
{

}

void WordHelper::initWord()
{
    Word *word=PlugHelper::loadPlug<Word>(":/config/word.json");

    WordStatic::all=word->all().toUtf8();
    WordStatic::collect=word->collect().toUtf8();
    WordStatic::block=word->block().toUtf8();
    WordStatic::blod=word->bold().toUtf8();
    WordStatic::book=word->book().toUtf8();
    WordStatic::cancel=word->cancel().toUtf8();
    WordStatic::codeBlock=word->codeBlock().toUtf8();
    WordStatic::copy=word->copy().toUtf8();
    WordStatic::copyTo=word->copyTo().toUtf8();
    WordStatic::cut=word->cut().toUtf8();
    WordStatic::del=word->del().toUtf8();
    WordStatic::devide=word->devide().toUtf8();
    WordStatic::edit=word->edit().toUtf8();
    WordStatic::file=word->file().toUtf8();
    WordStatic::font=word->font().toUtf8();
    WordStatic::fontFamily=word->fontFamily().toUtf8();
    WordStatic::in=word->in().toUtf8();
    WordStatic::insert=word->insert().toUtf8();
    WordStatic::italic=word->italic().toUtf8();
    WordStatic::last=word->last().toUtf8();
    WordStatic::markLab=word->markLab().toUtf8();
    WordStatic::markQuick=word->markQuick().toUtf8();
    WordStatic::message=word->message().toUtf8();
    WordStatic::moveTo=word->moveTo().toUtf8();
    WordStatic::new_=word->new_().toUtf8();
    WordStatic::note=word->note().toUtf8();
    WordStatic::ok=word->ok().toUtf8();
    WordStatic::open=word->open().toUtf8();
    WordStatic::orderList=word->orderList().toUtf8();
    WordStatic::out=word->out().toUtf8();
    WordStatic::paste=word->paste().toUtf8();
    WordStatic::photo=word->photo().toUtf8();
    WordStatic::read=word->read().toUtf8();
    WordStatic::recircle=word->recircle().toUtf8();
    WordStatic::remove=word->remove().toUtf8();
    WordStatic::save=word->save().toUtf8();
    WordStatic::setting=word->setting().toUtf8();
    WordStatic::share=word->share().toUtf8();
    WordStatic::size=word->size().toUtf8();
    WordStatic::preview=word->preview().toUtf8();
    WordStatic::restore=word->restore().toUtf8();
    WordStatic::tip_1=word->tip_1().toUtf8();
    WordStatic::tip_2=word->tip_2().toUtf8();
    WordStatic::tip_3=word->tip_3().toUtf8();
    WordStatic::tip_4=word->tip_4().toUtf8();
    WordStatic::tip_5=word->tip_5().toUtf8();
    WordStatic::tip_6=word->tip_6().toUtf8();
    WordStatic::tip_7=word->tip_7().toUtf8();
    WordStatic::tip_8=word->tip_8().toUtf8();
    WordStatic::title=word->title().toUtf8();
    WordStatic::unOrderList=word->unOrderList().toUtf8();
    WordStatic::update=word->update().toUtf8();
    WordStatic::zoomIn=word->zoomIn().toUtf8();
    WordStatic::zoomOut=word->zoomOut().toUtf8();
}
