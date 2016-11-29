#ifndef IMAGERENDER_H
#define IMAGERENDER_H

#include <QImage>



class ImageRender
{
public:
    ImageRender();
    //生成灰度图
    static void grayImg(QImage *image,double gray=0.5);
    QImage getImage() const;
    void setImage(const QImage &value);
    //修改图片的亮度
    QImage changeLighting(double light);
    //修改图片质量，最大为1.0，最小为0.0
    QImage changeQuarty(double q=1.0);
    //修改图片的对比度
    QImage changeContrast();
    //修改图片rgb的比例
    QImage changeRgb(int r=50,int b=50,int g=50);
private:
    QImage image;
};

#endif // IMAGERENDER_H
