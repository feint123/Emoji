#include "fileutil.h"

#include <QCryptographicHash>
#include <QFile>
#include <QImage>
#include <QDebug>
#include <util/net/networkhelper.h>

FileUtil::FileUtil()
{

}

void FileUtil::setLocalPathList(const QStringList &value)
{
    localPathList = value;
}

void FileUtil::setNetPath(const QString &value)
{
    netPath = value;
}

void FileUtil::setFileName(const QString &value)
{
    fileName = value;
}

QString FileUtil::onlyName(QString mark)
{
    return tr("%1_%2").arg(QDateTime::currentDateTime().toMSecsSinceEpoch()).arg(mark);
}

QString FileUtil::imageTempPath(QString path, QString file)
{
    return tr("%1/%2/%2").arg(path).arg(file);
}

bool FileUtil::copyFile(QString fromFile, QString toFile)
{
    char* byteTemp = new char[4096];//字节数组
    int fileSize = 0;
    int totalCopySize = 0;
    QFile tofile(toFile);
    if(!tofile.open(QIODevice::WriteOnly))
        return false;
    QDataStream out(&tofile);
//    out.setVersion(QDataStream::Qt_4_8);

    QFile fromfile(fromFile);
    if(!fromfile.open(QIODevice::ReadOnly)){
        return false;
    }
    fileSize = fromfile.size();
    QDataStream in(&fromfile);

//    in.setVersion(QDataStream::Qt_4_8);
    while(!in.atEnd())
    {
        int readSize = 0;
            //读入字节数组,返回读取的字节数量，如果小于4096，则到了文件尾
        readSize = in.readRawData(byteTemp, 4096);
        out.writeRawData(byteTemp, readSize);
        totalCopySize += readSize;
    }
    if(totalCopySize == fileSize){

        emit fileCopySuccess(toFile);

        return true;
    }
    else
        return false;
}

void FileUtil::loadNetImage()
{
    NetworkHelper *net=new NetworkHelper;
    net->imageUrl(tr("%1/%2").arg(netPath).arg(fileName));
    connect(net,SIGNAL(imageOk(QImage)),this,SLOT(onNetImageLoad(QImage)));
}

QImage FileUtil::loadImage()
{
    QImage image=loadLocalImage();
    if(image.isNull()){
        loadNetImage();
        image=this->netImage;
    }
    return image;
}

void FileUtil::onNetImageLoad(QImage image)
{
    this->netImage=image;
}

QImage FileUtil::loadLocalImage()
{
    QImage image;
    for(QString path:localPathList)
    {
        QString fileName=tr("%1/%2").arg(path).arg(this->fileName);
        image.load(fileName);
        if(!image.isNull())
            break;
    }
    return image;
}


