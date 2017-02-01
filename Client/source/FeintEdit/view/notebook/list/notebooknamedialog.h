#ifndef NOTEBOOKNAMEDIALOG_H
#define NOTEBOOKNAMEDIALOG_H

#include <QFrame>

#include <widget/view/listview.h>

#include <domain/notebook.h>



class NotebookNameDialog:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(int top READ top WRITE setTop)
    Q_PROPERTY(int bottom READ bottom WRITE setBottom)
public:
    int getHeight();

    void createList();
    ~NotebookNameDialog();
    static NotebookNameDialog* getInstance(QWidget *parent=0);
    int top() const;

    int bottom() const;

    void setUserTri(bool value);

public slots:
    void setTop(int top);

    void setBottom(int bottom);

signals:
    void bookClicked(NoteBook *book);

private slots:
    void onListItemDoubleClicked(QVariant item);
private:
    ListView *list;
    NotebookNameDialog(QWidget *parent);
    static NotebookNameDialog * dialog;
    int preHeight;

    // QWidget interface
    int m_top;

    int m_bottom;

    int tri=8;

    bool userTri=false;

protected:
    void paintEvent(QPaintEvent *event);

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // NOTEBOOKNAMEDIALOG_H
