#include "rubikside.h"
#include <QRandomGenerator>
#include <QVector3D>

RubikSide::RubikSide()
{
    updateData();
}

void RubikSide::setBColor(bool color)
{
    if (bcolor_ == color)
        return;

    bcolor_ = color;
    emit bcolorChanged();
}

void RubikSide::setUV(bool enable)
{
    if (uv_ == enable)
        return;

    uv_ = enable;
    emit uvChanged();
    // updateData();
    // update();
}

void RubikSide::setUVAdjust(float f)
{
    if (uvAdjust_ == f)
        return;

    uvAdjust_ = f;
    emit uvAdjustChanged();
   //  updateData();
    // update();
}
/*
void RubikSide::setCounter(int counter)
{
    counter_ = counter;
    emit counterChanged();

    updateData();
}
*/
void RubikSide::setColor(int color)
{
    color_ = color;
    emit colorChanged();

    // updateData();
}

void RubikSide::updateData()
{
    QByteArray v;
    v.resize(6 * 3 * sizeof(float));
    float *p = reinterpret_cast<float *>(v.data());

    // a triangle, front face = counter-clockwise
    *p++ = -1.0f; *p++ = -1.0f; *p++ = 0.0f;
    *p++ = 1.0f; *p++ = -1.0f; *p++ = 0.0f;
    *p++ = 1.0f; *p++ = 1.0f; *p++ = 0.0f;

    *p++ = 1.0f; *p++ = 1.0f; *p++ = 0.0f;
    *p++ = -1.0f; *p++ = 1.0f; *p++ = 0.0f;
    *p++ = -1.0f; *p++ = -1.0f; *p++ = 0.0f;

    setVertexData(v);

    setStride(3 * sizeof(float));
    setBounds(QVector3D(-1.0f, -1.0f, 0.0f), QVector3D(+1.0f, +1.0f, 0.0f));

    setPrimitiveType(QQuick3DGeometry::PrimitiveType::Triangles);


    addAttribute(QQuick3DGeometry::Attribute::PositionSemantic,
                 0,
                 QQuick3DGeometry::Attribute::F32Type);

}
