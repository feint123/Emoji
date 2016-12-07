#ifndef SETTINGTEXTANALYSIS_H
#define SETTINGTEXTANALYSIS_H

#include "xmlanalysis.h"

#include <QString>



class SettingTextAnalysis:public XmlAnalysis
{
public:
    SettingTextAnalysis();
    void* analysis(QDomDocument* doc);
};

#endif // SETTINGTEXTANALYSIS_H
