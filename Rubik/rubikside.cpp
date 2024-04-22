#include "rubikside.h"
#include <QRandomGenerator>
#include <QVector3D>
#include <QDebug>

RubikSide::RubikSide()
{
    updateData();

    startTimer(1500);
    setColor("white");
}

void RubikSide::setX(int x)
{
    x_ = x;
    // emit xChanged();
    // updateData();
    // update();
}

void RubikSide::setY(int y)
{

    y_ = y;
    // emit yChanged();
   //  updateData();
    // update();
}

void RubikSide::setZ(int z)
{
    z_ = z;
    // emit zChanged();
}

void RubikSide::setColor(QColor color)
{
    color_ = color;
    emit colorChanged(color_);
}

void RubikSide::updateData()
{
    int stride = 7 * sizeof(float);

    int tileSize = 2 * 3 * stride;
    QByteArray vertexData( 18 * tileSize, Qt::Initialization::Uninitialized);

    // x,y to współżędne w ścianie, z - numer ściany
    PrepareTile(0, 0, 0, QColor("green"), vertexData, tileSize / sizeof(float));
    PrepareTile(1, 0, 0, QColor("blue"), vertexData, tileSize / sizeof(float));
    PrepareTile(2, 0, 0, QColor("yellow"), vertexData, tileSize / sizeof(float));
    PrepareTile(0, 1, 0, QColor("red"), vertexData, tileSize / sizeof(float));
    PrepareTile(1, 1, 0, QColor("white"), vertexData, tileSize / sizeof(float));
    PrepareTile(2, 1, 0, QColor("orange"), vertexData, tileSize / sizeof(float));
    PrepareTile(0, 2, 0, QColor("blue"), vertexData, tileSize / sizeof(float));
    PrepareTile(1, 2, 0, QColor("green"), vertexData, tileSize / sizeof(float));
    PrepareTile(2, 2, 0, QColor("red"), vertexData, tileSize / sizeof(float));

    PrepareTile(0, 0, 1, QColor("white"), vertexData, tileSize / sizeof(float));
    PrepareTile(1, 0, 1, QColor("blue"), vertexData, tileSize / sizeof(float));
    PrepareTile(2, 0, 1, QColor("yellow"), vertexData, tileSize / sizeof(float));
    PrepareTile(0, 1, 1, QColor("red"), vertexData, tileSize / sizeof(float));
    PrepareTile(1, 1, 1, QColor("white"), vertexData, tileSize / sizeof(float));
    PrepareTile(2, 1, 1, QColor("orange"), vertexData, tileSize / sizeof(float));
    PrepareTile(0, 2, 1, QColor("blue"), vertexData, tileSize / sizeof(float));
    PrepareTile(1, 2, 1, QColor("green"), vertexData, tileSize / sizeof(float));
    PrepareTile(2, 2, 1, QColor("red"), vertexData, tileSize / sizeof(float));

    setVertexData(vertexData);
    setStride(stride);
    setBounds(QVector3D(-1.0f, -1.0f, -1.0f), QVector3D(+1.0f, +1.0f, +1.0f));

    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Triangles);

    addAttribute(QQuick3DGeometry::Attribute::PositionSemantic,
                 0,
                 QQuick3DGeometry::Attribute::F32Type);

    addAttribute(QQuick3DGeometry::Attribute::ColorSemantic,
                 3 * sizeof(float),
                 QQuick3DGeometry::Attribute::F32Type);
}

void RubikSide::PrepareTile(int x, int y, int z, const QColor &color, QByteArray &tile, const int tileSize)
{
    float *p = reinterpret_cast<float *>(tile.data());

    int rowSize = 3 * tileSize;
    int sideSize = 3 * rowSize;
    p += x * tileSize + y * rowSize + z * sideSize;

    if(z == 0)
        z = 1;
    else if(z == 1)
        z = -1;

    // I trójkąt
    if(z == 1)
    {
        *p++ = -1.0f + (x * 2.0f / 3.0f); // x
        *p++ = 1.0f / 3.0f - (y * 2.0f / 3.0f); // y
        *p++ = z;  // z

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();

        *p++ = -1.0f / 3.0f + (x * 2.0f / 3.0f);
        *p++ = 1.0f / 3.0f - (y * 2.0f / 3.0f);
        *p++ = z;

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();

        *p++ = -1.0f / 3.0f + (x * 2.0f / 3.0f);
        *p++ = 1.0f - (y * 2.0f / 3.0f);
        *p++ = z;

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();
    }
    else if(z == -1)
    {
        *p++ = -1.0f + (x * 2.0f / 3.0f); // x
        *p++ = 1.0f / 3.0f - (y * 2.0f / 3.0f); // y
        *p++ = z;  // z

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();

        *p++ = -1.0f / 3.0f + (x * 2.0f / 3.0f);
        *p++ = 1.0f / 3.0f - (y * 2.0f / 3.0f);
        *p++ = z;

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();

        *p++ = -1.0f / 3.0f + (x * 2.0f / 3.0f);
        *p++ = 1.0f - (y * 2.0f / 3.0f);
        *p++ = z;

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();
    }


    // II trójkąt

    *p++ = -1.0f + (x * 2.0f / 3.0f); // x
    *p++ = 1.0f / 3.0f - (y * 2.0f / 3.0f); // y
    *p++ = z;  // z

    *p++ = color.redF();
    *p++ = color.greenF();
    *p++ = color.blueF();
    *p++ = color.alphaF();

    if(z == 1)
    {
        *p++ = -1.0f / 3.0f + (x * 2.0f / 3.0f);
        *p++ = 1.0f - (y * 2.0f / 3.0f);
        *p++ = z;

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();

        *p++ = -1.0f + (x * 2.0f / 3.0f);
        *p++ = 1.0f - (y * 2.0f / 3.0f);
        *p++ = z;

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();
    }
    else if(z == -1)
    {
        *p++ = -1.0f + (x * 2.0f / 3.0f);
        *p++ = 1.0f - (y * 2.0f / 3.0f);
        *p++ = z;

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();

        *p++ = -1.0f / 3.0f + (x * 2.0f / 3.0f);
        *p++ = 1.0f - (y * 2.0f / 3.0f);
        *p++ = z;

        *p++ = color.redF();
        *p++ = color.greenF();
        *p++ = color.blueF();
        *p++ = color.alphaF();
    }
}
