#ifndef RUBIKSIDE_H
#define RUBIKSIDE_H

#include <QQuick3DGeometry>

class RubikSide : public QQuick3DGeometry
{
    Q_OBJECT
    QML_NAMED_ELEMENT(RubikSide)
    // Q_PROPERTY(int counter READ counter WRITE setCounter NOTIFY counterChanged)

    Q_PROPERTY(bool bcolor READ bcolor WRITE setBColor NOTIFY bcolorChanged)
    Q_PROPERTY(int color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(bool uv READ uv WRITE setUV NOTIFY uvChanged)
    Q_PROPERTY(float uvAdjust READ uvAdjust WRITE setUVAdjust NOTIFY uvAdjustChanged)


public:
    RubikSide();

    /*
    int counter() const { return counter_; }
    void setCounter(int counter);
*/
    bool bcolor() const { return bcolor_; }
    void setBColor(bool color);

    int color() const { return color_; }
    void setColor(int color);

    bool uv() const { return uv_;}
    void setUV(bool enable);

    float uvAdjust() const { return uvAdjust_; }
    void setUVAdjust(float f);

private:
    void updateData();

signals:
    void bcolorChanged();
    void colorChanged();
    void uvChanged();
    void uvAdjustChanged();


/*    void counterChanged();

*/

private:
    // int counter_;
    bool bcolor_;
    int color_;
    float uvAdjust_ = 0.0f;
    bool uv_ = false;
};

#endif // RUBIKSIDE_H
