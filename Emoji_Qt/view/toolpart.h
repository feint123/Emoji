#ifndef TOOLPART_H
#define TOOLPART_H

#include <QDialog>
#include <QSlider>

namespace Ui {
class ToolPart;
}

class ToolPart : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(int red READ red WRITE setRed NOTIFY colorChanged)
    Q_PROPERTY(int green READ green WRITE setGreen NOTIFY colorChanged)
    Q_PROPERTY(int blue READ blue WRITE setBlue NOTIFY colorChanged)
    Q_PROPERTY(QPoint place READ place WRITE setPlace NOTIFY placeChanged)
    Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize NOTIFY fontSizeChanged)
    Q_PROPERTY(QFont font READ font WRITE setFont NOTIFY fontChanged)
public:
    enum ColorPart{RED,GREEN,BLUE};
    explicit ToolPart(QWidget *parent = 0);
    void startZoom();
    ~ToolPart();

    int red() const
    {
        return m_red;
    }

    int green() const
    {
        return m_green;
    }

    int blue() const
    {
        return m_blue;
    }

    QPoint place() const
    {
        return m_place;
    }

    int fontSize() const
    {
        return m_fontSize;
    }

    QFont font() const
    {
        return m_font;
    }

public slots:
    void setRed(int red)
    {
        if (m_red == red)
            return;

        m_red = red;
        emit colorChanged(red,ColorPart::RED);
    }

    void setGreen(int green)
    {
        if (m_green == green)
            return;

        m_green = green;
        emit colorChanged(green,ColorPart::GREEN);
    }

    void setBlue(int blue)
    {
        if (m_blue == blue)
            return;

        m_blue = blue;
        emit colorChanged(blue,ColorPart::BLUE);
    }

    void setPlace(QPoint place)
    {
        if (m_place == place)
            return;

        m_place = place;
        emit placeChanged(place);
    }

    void setFontSize(int fontSize)
    {
        if (m_fontSize == fontSize)
            return;

        m_fontSize = fontSize;
        emit fontSizeChanged(fontSize);
    }

    void setFont(QFont font)
    {
        if (m_font == font)
            return;
        font.setPointSize(this->fontSize());
        m_font = font;
        emit fontChanged(font);
    }

signals:
    void colorChanged(int red,ColorPart part);

    void placeChanged(QPoint place);

    void fontSizeChanged(int fontSize);

    void fontChanged(QFont font);

    void zoomIn();

    void zoomOut();

private slots:

    void on_redSlider_sliderMoved(int position);

    void on_greenSlider_sliderMoved(int position);

    void on_blueSlider_sliderMoved(int position);

    void on_turnGray_toggled(bool checked);

    void on_compress_toggled(bool checked);

    void on_autoMoveComb_toggled(bool checked);

    void on_sizeSpin_valueChanged(int arg1);

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_zoomIn_clicked();

    void on_zoomOut_clicked();

private:
    Ui::ToolPart *ui;
    void initImage();
    void initSlider(QSlider *slider);
    double scale;
    int m_red;
    int m_green;
    int m_blue;
    QPoint m_place;
    int m_fontSize;
    QFont m_font;
};

#endif // TOOLPART_H
