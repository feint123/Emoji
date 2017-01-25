#ifndef FILECOPYDIALOG_H
#define FILECOPYDIALOG_H

#include <qframe.h>



class FileCopyDialog:public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName NOTIFY fileNameChanged)
public:
    FileCopyDialog(QWidget *parent=0);
    QString fileName() const;
    void setDir(QString dir);

public slots:
    void setFileName(QString fileName);

signals:
    void fileNameChanged(QString fileName);

private:

    QString m_fileName;


protected:
    void paintEvent(QPaintEvent *event);
};

#endif // FILECOPYDIALOG_H
