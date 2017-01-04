#ifndef FEINTSETTING_H
#define FEINTSETTING_H


class FeintSetting
{


public:
    enum STYLE{
        Daily,
        Dark
    };
    FeintSetting();
    void setColorStyle(STYLE style);
    STYLE getColorStyle();
    virtual void createDailyStyle();
    virtual void createDarkStyle();
private:
    STYLE cstyle;

};

#endif // FEINTSETTING_H
