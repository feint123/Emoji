#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QMouseEvent>
#include <QPushButton>






class MenuButton:public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(bool state READ state WRITE setState NOTIFY stateChanged)
public:
    MenuButton(QWidget* parent);

    int getTopId() const;
    void setTopId(int value);
    void setColor(const QString &bgColor,const QString &color);

    QString getColor() const;

    int getId() const;
    void setId(int value);

    QString getCheckColor() const;
    void setCheckColor(const QString &value);

    bool state() const;

public slots:
    void setState(bool state);

signals:
    void stateChanged(bool state);

private slots:
    void on_toggled(bool checked);

private:
    int topId;
    int id;
    QString baseStyle;
    QString bgColor;
    QString currentStyle;
    QString color;
    QString checkColor;

    void setCheckBgColor();



    bool m_state;
};

#endif // MENUBUTTON_H
