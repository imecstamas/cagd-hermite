#include "BicubicHermitePatches3.h"

namespace cagd
{
    BicubicHermitePatch3::BicubicHermitePatch3(): TensorProductSurface3(0.0, 1.0, 0.0, 1.0, 4, 4, 0, 0)
    {

    }

    BicubicHermitePatch3::BicubicHermitePatch3(const BicubicHermitePatch3 &surface): TensorProductSurface3(surface)
    {

    }

    GLboolean BicubicHermitePatch3::UBlendingFunctionValues(GLdouble u, RowMatrix<GLdouble>& blending_values) const
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

    GLboolean BicubicHermitePatch3::VBlendingFunctionValues(GLdouble v, RowMatrix<GLdouble>& blending_values) const
    {
        if (v < _v_min || v > _v_max)
        {
            blending_values.ResizeColumns(0);
            return GL_FALSE;
        }

        blending_values.ResizeColumns(4);

        GLdouble v2 = v * v, v3 = v2 * v;

        blending_values[0] =  2.0 * v3 - 3.0 * v2 + 1.0;
        blending_values[1] = -2.0 * v3 + 3.0 * v2;
        blending_values[2] =        v3 - 2.0 * v2 + v;
        blending_values[3] =        v3 -       v2;

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::CalculatePartialDerivatives(GLuint maximum_order_of_partial_derivatives, GLdouble u, GLdouble v, PartialDerivatives &pd) const
    {
        if (u < _u_min || u > _u_max || v < _v_min || v > _v_max || maximum_order_of_partial_derivatives > 1)
        {
            return GL_FALSE;
        }

        RowMatrix<GLdouble> u_blending_values(4);

        GLdouble u2 = u * u, u3 = u2 * u;

        u_blending_values[0] =  2.0 * u3 - 3.0 * u2 + 1.0;
        u_blending_values[1] = -2.0 * u3 + 3.0 * u2;
        u_blending_values[2] =        u3 - 2.0 * u2 + u;
        u_blending_values[3] =        u3 -       u2;

        RowMatrix<GLdouble> d1_u_blending_values(4);

        d1_u_blending_values[0] =  6.0 * u2 - 6.0 * u;
        d1_u_blending_values[1] = -6.0 * u2 + 6.0 * u;
        d1_u_blending_values[2] =  3.0 * u2 - 4.0 * u + 1.0;
        d1_u_blending_values[3] =  3.0 * u2 - 2.0 * u;


        RowMatrix<GLdouble> v_blending_values(4);

        GLdouble v2 = v * v, v3 = v2 * v;

        v_blending_values[0] =  2.0 * v3 - 3.0 * v2 + 1.0;
        v_blending_values[1] = -2.0 * v3 + 3.0 * v2;
        v_blending_values[2] =        v3 - 2.0 * v2 + v;
        v_blending_values[3] =        v3 -       v2;

        RowMatrix<GLdouble> d1_v_blending_values(4);

        d1_v_blending_values[0] =  6.0 * v2 - 6.0 * v;
        d1_v_blending_values[1] = -6.0 * v2 + 6.0 * v;
        d1_v_blending_values[2] =  3.0 * v2 - 4.0 * v + 1.0;
        d1_v_blending_values[3] =  3.0 * v2 - 2.0 * v;

        pd.ResizeRows( 2 ) ;
        pd.LoadNullVectors();

        for (GLuint i = 0; i < _data.GetRowCount(); ++i)
        {
            DCoordinate3 aux_d0_v, aux_d1_v;

            for (GLuint j = 0; j < _data.GetColumnCount(); ++j)
            {
                aux_d0_v += _data(i, j) *    v_blending_values[j];
                aux_d1_v += _data(i, j) * d1_v_blending_values[j];
            }

            // surface point
            pd(0,0) += aux_d0_v *     u_blending_values[i];

            // u-directional first order partial derivative
            pd(1,0) += aux_d0_v * d1_u_blending_values[i];

            // v-directional first order partial derivative
            pd(1,1) += aux_d1_v *    u_blending_values[i];
        }

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::SetCorner(GLuint row, GLuint column, GLdouble x, GLdouble y, GLdouble z)
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        DCoordinate3 &reference = _data(row, column);

        reference[0] = x;
        reference[1] = y;
        reference[2] = z;

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::SetCorner(GLuint row, GLuint column, const DCoordinate3& corner)
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        _data(row, column) = corner;

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::GetCorner(GLuint row, GLuint column, GLdouble &x, GLdouble &y, GLdouble &z) const
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        x=_data((unsigned int)row, (unsigned int) column).x();
        y=_data((unsigned int)row, (unsigned int) column).y();
        z=_data((unsigned int)row, (unsigned int) column).z();

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::GetCorner(GLuint row, GLuint column, DCoordinate3 &point) const
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        point.x() = (_data((unsigned int)row, (unsigned int) column).x());
        point.y() = (_data((unsigned int)row, (unsigned int) column).y());
        point.z() = (_data((unsigned int)row, (unsigned int) column).z());

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::SetUTangent(GLuint row, GLuint column, GLdouble x, GLdouble y, GLdouble z)
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        DCoordinate3 &reference = _data(2 + row, column);

        reference[0] = x;
        reference[1] = y;
        reference[2] = z;

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::SetUTangent(GLuint row, GLuint column, const DCoordinate3& u_tangent)
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        _data(2 + row, column) = u_tangent;

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::GetUTangent(GLuint row, GLuint column, GLdouble &x, GLdouble &y, GLdouble &z) const
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        x=_data((unsigned int)(2 + row), (unsigned int) column).x();
        y=_data((unsigned int)(2 + row), (unsigned int) column).y();
        z=_data((unsigned int)(2 + row), (unsigned int) column).z();

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::GetUTangent(GLuint row, GLuint column, DCoordinate3 &point) const
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        point.x() = (_data((unsigned int)(2 + row), (unsigned int) column).x());
        point.y() = (_data((unsigned int)(2 + row), (unsigned int) column).y());
        point.z() = (_data((unsigned int)(2 + row), (unsigned int) column).z());

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::SetVTangent(GLuint row, GLuint column, GLdouble x, GLdouble y, GLdouble z)
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        DCoordinate3 &reference = _data(row, 2 + column);

        reference[0] = x;
        reference[1] = y;
        reference[2] = z;

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::SetVTangent(GLuint row, GLuint column, const DCoordinate3& v_tangent)
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        _data(row, 2  +column) = v_tangent;

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::GetVTangent(GLuint row, GLuint column, GLdouble &x, GLdouble &y, GLdouble &z) const
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        x=_data((unsigned int)row, (unsigned int)(2+column)).x();
        y=_data((unsigned int)row, (unsigned int)(2+column)).y();
        z=_data((unsigned int)row, (unsigned int)(2+column)).z();

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::GetVTangent(GLuint row, GLuint column, DCoordinate3 &point) const
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        point.x() = (_data((unsigned int)row, (unsigned int)(2+column)).x());
        point.y() = (_data((unsigned int)row, (unsigned int)(2+column)).y());
        point.z() = (_data((unsigned int)row, (unsigned int)(2+column)).z());

        return GL_TRUE;
    }


    GLboolean BicubicHermitePatch3::SetTwistVector(GLuint row, GLuint column, GLdouble x, GLdouble y, GLdouble z)
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        DCoordinate3 &reference = _data(2 + row, 2 + column);

        reference[0] = x;
        reference[1] = y;
        reference[2] = z;

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::SetTwistVector(GLuint row, GLuint column, const DCoordinate3& twist)
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        _data(2 + row, 2 + column) = twist;

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::GetTwistVector(GLuint row, GLuint column, GLdouble &x, GLdouble &y, GLdouble &z) const
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        x=_data((unsigned int)(2+row), (unsigned int)(2+column)).x();
        y=_data((unsigned int)(2+row), (unsigned int)(2+column)).y();
        z=_data((unsigned int)(2+row), (unsigned int)(2+column)).z();

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::GetTwistVector(GLuint row, GLuint column, DCoordinate3 &point) const
    {
        if (row > 1 || column > 1)
        {
            return GL_FALSE;
        }

        point.x() = (_data((unsigned int)(2+row), (unsigned int)(2+column)).x());
        point.y() = (_data((unsigned int)(2+row), (unsigned int)(2+column)).y());
        point.z() = (_data((unsigned int)(2+row), (unsigned int)(2+column)).z());

        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::SetNoNeightbours()
    {
        for(int i = 0; i < 7; i++)
        {
            _neightbours[i] = -1;
        }
        return GL_TRUE;
    }

    GLboolean BicubicHermitePatch3::SetNeightbours(GLuint nr, GLuint neightbour)
    {
        _neightbours[nr] = neightbour;

        return GL_TRUE;
    }

    GLuint BicubicHermitePatch3::GetNeightbour(GLuint nr)
    {
        return _neightbours[nr];
    }
}
