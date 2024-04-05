#ifndef RUBIKSIDE_H
#define RUBIKSIDE_H

#include <QQuick3DGeometry>
#include <iostream>
#include <QColor>

#include <QTimerEvent>

class RubikSide : public QQuick3DGeometry
{
    Q_OBJECT
    QML_NAMED_ELEMENT(RubikSide)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(int y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(int z READ z WRITE setZ NOTIFY zChanged)

public:
    RubikSide();

    QColor color() const { return color_; }
    void setColor(QColor color);

    int x() const { return x_;}
    void setX(int x);

    int y() const { return y_; }
    void setY(int y);

    int z() const { return z_; }
    void setZ(int z);

signals:
    void colorChanged(QColor color);
    void xChanged();
    void yChanged();
    void zChanged();

protected:
    void timerEvent(QTimerEvent *event)
    {
        static int i = 0;

        std::cerr << "\nTimer ID:" << event->timerId();
        if(i % 6 == 0)
        {
            QColor green("green");
            setColor(green);
        }
        else if(i % 6 == 1)
        {
            QColor green("red");
            setColor(green);
        }
        else if(i % 6 == 2)
        {
            QColor green("blue");
            setColor(green);
        }
        else if(i % 6 == 3)
        {
            QColor green("white");
            setColor(green);
        }
        else if(i % 6 == 4)
        {
            QColor green("yellow");
            setColor(green);
        }
        else if(i % 6 == 5)
        {
            QColor green("orange");
            setColor(green);
        }
        ++i;
    }

private:
    void updateData();
    void PrepareTile(int x, int y, int z, const QColor& color, QByteArray& tile);



/*    void counterChanged();

*/

private:
    QColor color_;
    int x_;
    int y_;
    int z_;
};

#endif // RUBIKSIDE_H
