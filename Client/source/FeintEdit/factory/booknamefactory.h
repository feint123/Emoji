#ifndef BOOKNAMEFACTORY_H
#define BOOKNAMEFACTORY_H

#include <view/notebook/list/notebooknamedialog.h>



class BookNameFactory
{
public:
    BookNameFactory();
    static NotebookNameDialog* create(QString title);
};

#endif // BOOKNAMEFACTORY_H
