#ifndef FEINTMENU_H
#define FEINTMENU_H

#include <QIcon>
#include <QToolBox>
#include <QUrl>
#include <QWidget>
#include <widget/button/menubutton.h>
namespace Ui {
class FeintMenu;
}

class FeintMenu : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString boxColor READ boxColor WRITE setBoxColor NOTIFY boxColorChanged)
    Q_PROPERTY(QString boxBackgroundColor READ boxBackgroundColor WRITE setBoxBackgroundColor NOTIFY boxBackgroundColorChanged)
    Q_PROPERTY(QString tabColor READ tabColor WRITE setTabColor NOTIFY tabColorChanged)
    Q_PROPERTY(QString tabBackgroundColor READ tabBackgroundColor WRITE setTabBackgroundColor NOTIFY tabBackgroundColorChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString intro READ intro WRITE setIntro NOTIFY introChanged)
public:
    explicit FeintMenu(QWidget *parent = 0,QString color="#f9f9f9");
    ~FeintMenu();
    void addTopItem(const QString &name);
    void addTopItem(const QString &name,const QIcon &icon);
    void addSubItem(int topId,const QString &name,const QIcon &icon);
    void finishSub(int topId);



    QString boxColor() const;


    QString boxBackgroundColor() const;

    QString tabColor() const;

    QString tabBackgroundColor() const;


    QString name() const;

    QString intro() const;

public slots:
    void setBoxColor(QString boxColor);

    void setPortrait(QString url);

    void setBoxBackgroundColor(QString boxBackgroundColor);

    void setTabColor(QString tabColor);

    void setTabBackgroundColor(QString tabBackgroundColor);

    void setName(QString name);

    void setIntro(QString intro);

    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void menuItemClicked(int,int);
    void boxColorChanged(QString boxColor);

    void boxBackgroundColorChanged(QString boxBackgroundColor);

    void tabColorChanged(QString tabColor);

    void tabBackgroundColorChanged(QString tabBackgroundColor);

    void nameChanged(QString name);

    void introChanged(QString intro);

private:
    Ui::FeintMenu *ui;
    int topItemCount;
    int subId;
    QString baseStyle;
    QString currentStyle;
    QWidget* createItem();
    QList<QWidget*> itemList;
    QToolBox *toolBox;
    void setAllColor();
    QString m_boxColor;
    QString m_boxBackgroundColor;
    QString m_tabColor;
    QString m_tabBackgroundColor;
    QString m_portrait;

    QString m_name;
    QString m_intro;
};

#endif // FEINTMENU_H
