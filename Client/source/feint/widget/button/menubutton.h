#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>






class MenuButton:public QPushButton
{
    Q_OBJECT
public:
    MenuButton(QWidget* parent);

    int getTopId() const;
    void setTopId(int value);
    void setColor(const QString &bgColor,const QString &color);

    QString getColor() const;

    int getId() const;
    void setId(int value);

private:
    int topId;
    int id;
    QString baseStyle;
    QString borderColor;
    QString currentStyle;
    QString color;

};

#endif // MENUBUTTON_H
