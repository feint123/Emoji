#ifndef XMLANALYSIS_H
#define XMLANALYSIS_H

#include <QDomDocument>

namespace Feint {
class XmlAnalysis;
}
class XmlAnalysis
{
public:
    XmlAnalysis();
    virtual void* analysis(QDomDocument* doc);
};

#endif // XMLANALYSIS_H
