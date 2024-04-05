#include "rubikside.h"
#include <QRandomGenerator>
#include <QVector3D>


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

    clear();
    int stride = 7 * sizeof(float);

    // 3 vertices in total for the triangle
    QByteArray vertexData( 2 * 3 * stride, Qt::Initialization::Uninitialized);

    PrepareTile(0, 0, 0, QColor("green"), vertexData);

    setVertexData(vertexData);
    setStride(stride);
    setBounds(QVector3D(-1.0f, -1.0f, 0.0f), QVector3D(+1.0f, +1.0f, 0.0f));

    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Triangles);

    addAttribute(QQuick3DGeometry::Attribute::PositionSemantic,
                 0,
                 QQuick3DGeometry::Attribute::F32Type);

    addAttribute(QQuick3DGeometry::Attribute::ColorSemantic,
                 3 * sizeof(float),
                 QQuick3DGeometry::Attribute::F32Type);


}

void RubikSide::PrepareTile(int x, int y, int z, const QColor &color, QByteArray &tile)
{
    float *p = reinterpret_cast<float *>(tile.data());

    // a triangle, front face = counter-clockwise
    *p++ = -1.0f; // x
    *p++ = -1.0f; // y
    *p++ = 0.0f;  // z

    *p++ = color.redF();
    *p++ = color.greenF();
    *p++ = color.blueF();
    *p++ = color.alphaF();

    *p++ = 1.0f;
    *p++ = -1.0f;
    *p++ = 0.0f;

    *p++ = color.redF();
    *p++ = color.greenF();
    *p++ = color.blueF();
    *p++ = color.alphaF();

    *p++ = 1.0f;
    *p++ = 1.0f;
    *p++ = 0.0f;

    *p++ = color.redF();
    *p++ = color.greenF();
    *p++ = color.blueF();
    *p++ = color.alphaF();

    *p++ = -1.0f; // x
    *p++ = -1.0f; // y
    *p++ = 0.0f;  // z

    *p++ = color.redF();
    *p++ = color.greenF();
    *p++ = color.blueF();
    *p++ = color.alphaF();

    *p++ = 1.0f;
    *p++ = 1.0f;
    *p++ = 0.0f;

    *p++ = color.redF();
    *p++ = color.greenF();
    *p++ = color.blueF();
    *p++ = color.alphaF();

    *p++ = -1.0f;
    *p++ = 1.0f;
    *p++ = 0.0f;

    *p++ = color.redF();
    *p++ = color.greenF();
    *p++ = color.blueF();
    *p++ = color.alphaF();
}
