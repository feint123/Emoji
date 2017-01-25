#ifndef MARKDOWNTITLE_H
#define MARKDOWNTITLE_H

#include <QWidget>

namespace Ui {
class MarkDownTitle;
}

class MarkDownTitle : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString createDate READ createDate WRITE setCreateDate)
public:
    explicit MarkDownTitle(QWidget *parent = 0);
    ~MarkDownTitle();

    QString title() const;

    QString createDate() const;

    void setPlaceHolderText(const QString &text);
public slots:
    void setTitle(QString title);

    void setCreateDate(QString createDate);

signals:
    void titleChanged(QString title);

private:
    Ui::MarkDownTitle *ui;
    QString m_title;
    QString m_createDate;
};

#endif // MARKDOWNTITLE_H
