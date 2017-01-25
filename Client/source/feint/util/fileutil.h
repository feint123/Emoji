#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <QIODevice>
#include <QImage>



class FileUtil:public QObject
{
    Q_OBJECT
public:
    FileUtil();

    void setLocalPathList(const QStringList &value);


    void setNetPath(const QString &value);

    void setFileName(const QString &value);

    static QString onlyName(QString mark);

    bool copyFile(QString fromFile,QString toFile);

signals:
    void fileCopySuccess(QString);
public slots:
    void loadNetImage();
    QImage loadImage();
    void onNetImageLoad(QImage image);
    QImage loadLocalImage();
private:
    QStringList localPathList;
    QString fileName;
    QString netPath;

    QImage netImage;

};

#endif // FILEUTIL_H
