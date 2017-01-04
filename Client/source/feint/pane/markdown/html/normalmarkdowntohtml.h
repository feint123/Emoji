#ifndef NORMALMARKDOWNTOHTML_H
#define NORMALMARKDOWNTOHTML_H

#include "markdowntohtml.h"

#include <QObject>


class NormalMarkDownToHtml:public QObject

{
      Q_OBJECT
public:
    NormalMarkDownToHtml(QString markdown);
     QString createHtml();
private:

    QString markdown;

    QVector<HtmlRule> htmlRules;
    QHash<QString, QString> labelHash;

    HtmlRule rule;

    int orderlistUnClose;
    int unOrderListUnClose;

    struct OrderList{
        int level;
        bool isClose;
        QString orderType;
        QString text;
    };
    /**
     * @brief The LineHtml struct
     * type=1：当行不存在多行标签。
     * type=2：列表标签
     */
    struct LineHtml{
        int type;
        QString text;
    };

    int getLineType(QString label);
    QStringList splitMarkDown();
    LineHtml paserLine(QString text);


    QVector<OrderList> orderListList;

    QString listColse;
    bool isFirstUnOrder;

    MarkDownToHtml *html;

    void paserOrderList(QString *text,int index,int length,HtmlRule rule);


    QString endOrderList(int endIndex);



    int getTabNum(QString str);

};

#endif // NORMALMARKDOWNTOHTML_H
