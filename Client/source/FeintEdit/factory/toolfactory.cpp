#include "toolfactory.h"

#include <view/tool/notebooktool.h>
#include <view/tool/notetool.h>

ToolFactory::ToolFactory()
{

}

QDialog *ToolFactory::createTool(QWidget *parent,Model model)
{
    switch(model)
    {
    case Note:
        return new NoteTool(parent);
        break;

    case NoteBook:
        return new NotebookTool(parent);
        break;

    }
}
