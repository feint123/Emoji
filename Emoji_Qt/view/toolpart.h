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
    Q_PROPERTY(int fontSize READ fontSize WRITE setFontSize NOTIFY fontSizeChanged)
    Q_PROPERTY(QFont font READ font WRITE setFont NOTIFY fontChanged)
    Q_PROPERTY(QString emojiString READ emojiString WRITE setEmojiString NOTIFY emojiStringChanged)
public:
    enum ColorPart{RED,GREEN,BLUE};
    explicit ToolPart(QWidget *parent = 0);
    void restart();
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


    int fontSize() const
    {
        return m_fontSize;
    }

    QFont font() const
    {
        return m_font;
    }


    QString emojiString() const
    {
        return m_emojiString;
    }

    int placeId() const
    {
        return m_placeId;
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
    void editEnable();

    void setEmojiString(QString emojiString)
    {
        if (m_emojiString == emojiString)
            return;

        m_emojiString = emojiString;
        emit emojiStringChanged(emojiString);
    }

    void setPlaceId(int placeId,bool ver)
    {
        if (m_placeId == placeId&&m_ver== ver)
            return;

        m_placeId = placeId;
        m_ver=ver;
        emit placeIdChanged(placeId,ver);
    }

signals:
    void colorChanged(int red,ToolPart::ColorPart part);

    void placeChanged(QPoint place);

    void fontSizeChanged(int fontSize);

    void fontChanged(QFont font);

    void zoomIn();

    void zoomOut();

    void emojiStringChanged(QString emojiString);

    void placeIdChanged(int placeId,bool ver);

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

    void on_hotComb_currentIndexChanged(const QString &arg1);


    void on_verComb_currentIndexChanged(const QString &arg1);

    void on_horiComb_currentIndexChanged(const QString &arg1);

    void on_hotEdit_textChanged(const QString &arg1);

private:
    Ui::ToolPart *ui;
    void initImage();
    void initText();
    void restartImage();
    void restartText();
    void initSlider(QSlider *slider);
    int transDirctWord(const QString& word);
    double scale;
    int m_red;
    int m_green;
    int m_blue;
    int m_fontSize;
    bool m_ver;
    QFont m_font;
    QString m_emojiString;
    int m_placeId;
};

#endif // TOOLPART_H
