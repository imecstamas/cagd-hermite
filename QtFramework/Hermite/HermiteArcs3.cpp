#include "Hermite/HermiteArcs3.h"
#include <iostream>

using namespace std;

namespace cagd {

HermiteArc3::HermiteArc3():LinearCombination3(0.0,1.0,4,GL_STATIC_DRAW)
{
}

GLboolean HermiteArc3::BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble>& blending_values) const
{
    if (u < _u_min || u > _u_max)
    {
        blending_values.ResizeColumns(0);
        return GL_FALSE;
    }

    blending_values.ResizeColumns(4);

    GLdouble u2 = u * u, u3 = u2 * u;

    blending_values[0] =  2.0 * u3 - 3.0 * u2 + 1.0;
    blending_values[1] = -2.0 * u3 + 3.0 * u2;
    blending_values[2] =        u3 - 2.0 * u2 + u;
    blending_values[3] =        u3 -       u2;

    return GL_TRUE;
}

GLboolean HermiteArc3::CalculateDerivatives(GLuint maximum_order_of_derivatives, GLdouble u, Derivatives& d) const
{
    Matrix<GLdouble> dF(maximum_order_of_derivatives + 1, _data.GetRowCount());
    d.ResizeRows(maximum_order_of_derivatives + 1);
    d.LoadNullVectors();


    GLdouble u2 = u * u, u3 = u2 * u;
    // zeroth order derivatives of basis functions
    dF(0, 0) = 2.0 * u3 - 3.0 * u2 + 1.0;
    dF(0, 1) = -2.0 * u3 + 3.0 * u2;
    dF(0, 2) =        u3 - 2.0 * u2 + u;
    dF(0, 3) =       u3 -       u2;

    if (maximum_order_of_derivatives >= 1)
    {
        // first order derivatives of basis functions
        dF(1, 0) = 6.0 * u2 - 6.0 * u;
        dF(1, 1) = -6.0 * u2 + 6.0 * u;
        dF(1, 2) = 3.0 * u2 - 4.0 * u + 1.0;
        dF(1, 3) = 3.0 * u2 - 2.0 * u;
    }

    if (maximum_order_of_derivatives >= 2)
    {
        // second order derivatives of basis functions
        dF(2, 0) = 6.0 * (2.0 * u -1.0);
        dF(2, 1) = 6.0 - 12.0 * u;
        dF(2, 2) = 6.0 * u - 4.0;
        dF(2, 3) = 6.0 * u - 2.0;
    }

    if (maximum_order_of_derivatives >= 3)
    {
        // third order derivatives of basis functions
        dF(3, 0) = 12;
        dF(3, 1) = -12;
        dF(3, 2) = 6;
        dF(3, 3) = 6;
    }

    // fourth and higher order derivatives are identically zero

    // evaluation of zeroth and higher order derivatives
    for (GLuint r = 0; r <= maximum_order_of_derivatives; r++)
    {
        for (GLuint i = 0; i < _data.GetRowCount(); i++)
        {
            d[r] += _data[i] * dF(r, i);
        }
    }
    return GL_TRUE;
}

GLboolean HermiteArc3::SetCorner(GLuint corner_index, GLdouble x, GLdouble y, GLdouble z)
{
    if (corner_index > 1){
        return GL_FALSE;
    }
    DCoordinate3 &reference = _data[corner_index];
    reference[0] = x;
    reference[1] = y;
    reference[2] = z;
    return GL_TRUE;
}

GLboolean HermiteArc3::SetCorner(GLuint corner_index, const DCoordinate3 &v)
{
    if (corner_index > 1){
        return GL_FALSE;
    }
    _data[corner_index] = v;
    return GL_TRUE;
}

GLboolean HermiteArc3::GetCorner(GLuint index, GLdouble x, GLdouble y, GLdouble z) const
{
    if (index > 1){
        return GL_FALSE;
    }

    x = _data[(unsigned int)index].x();
    y = _data[(unsigned int)index].y();
    z = _data[(unsigned int)index].z();

    return GL_TRUE;
}

GLboolean HermiteArc3::GetCorner(GLuint index, DCoordinate3 &point) const
{
    if (index > 1){
        return GL_FALSE;
    }

    point.x() = _data[(unsigned int)index].x();
    point.y() = _data[(unsigned int)index].y();
    point.z() = _data[(unsigned int)index].z();

    return GL_TRUE;
}

GLboolean HermiteArc3::SetTangent(GLuint corner_index, GLdouble x, GLdouble y, GLdouble z)
{
        if (corner_index > 1){
            return GL_FALSE;
        }

        DCoordinate3 &reference = _data[corner_index + 2];
        reference[0] = x;
        reference[1] = y;
        reference[2] = z;
        return GL_TRUE;
}

GLboolean HermiteArc3::SetTangent(GLuint corner_index, const DCoordinate3 &v)
{
    if (corner_index > 1){
        return GL_FALSE;
    }
    _data[corner_index+2] = v;
    return GL_TRUE;
}

GLboolean HermiteArc3::GetTangent(GLuint index, GLdouble x, GLdouble y, GLdouble z) const
{
    if (index > 1){
        return GL_FALSE;
    }

    x = _data[(unsigned int)(2 + index)].x();
    y = _data[(unsigned int)(2 + index)].y();
    z = _data[(unsigned int)(2 + index)].z();

    return GL_TRUE;
}

GLboolean HermiteArc3::GetTangent(GLuint index, DCoordinate3 &point) const
{
    if (index > 1){
        return GL_FALSE;
    }

    point.x() = _data[(unsigned int)(2 + index)].x();
    point.y() = _data[(unsigned int)(2 + index)].y();
    point.z() = _data[(unsigned int)(2 + index)].z();

    return GL_TRUE;
}
}
