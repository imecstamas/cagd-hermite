#pragma once

#include "../Core/TensorProductSurfaces3.h"

namespace cagd
{
    class BicubicHermitePatch3: public TensorProductSurface3
    {
    protected:
        //
        GLuint _neightbours[8];
    public:
        // default constructor
        BicubicHermitePatch3();

        // copy constructor
        BicubicHermitePatch3(const BicubicHermitePatch3 &surface);

        // inherited pure abstract virtual methods
        GLboolean UBlendingFunctionValues(GLdouble u_knot, RowMatrix<GLdouble>& blending_values) const;
        GLboolean VBlendingFunctionValues(GLdouble v_knot, RowMatrix<GLdouble>& blending_values) const;
        GLboolean CalculatePartialDerivatives(GLuint maximum_order_of_partial_derivatives, GLdouble u, GLdouble v, PartialDerivatives& pd) const;

        GLboolean SetCorner(GLuint row, GLuint column, GLdouble x, GLdouble y, GLdouble z);
        GLboolean SetCorner(GLuint row, GLuint column, const DCoordinate3& corner);
        GLboolean GetCorner(GLuint row, GLuint column, GLdouble& x, GLdouble& y, GLdouble& z) const;
        GLboolean GetCorner(GLuint row, GLuint column, DCoordinate3& point) const;

        GLboolean SetUTangent(GLuint row, GLuint column, GLdouble x, GLdouble y, GLdouble z);
        GLboolean SetUTangent(GLuint row, GLuint column, const DCoordinate3& u_tangent);
        GLboolean GetUTangent(GLuint row, GLuint column, GLdouble& x, GLdouble& y, GLdouble& z) const;
        GLboolean GetUTangent(GLuint row, GLuint column, DCoordinate3& point) const;

        GLboolean SetVTangent(GLuint row, GLuint column, GLdouble x, GLdouble y, GLdouble z);
        GLboolean SetVTangent(GLuint row, GLuint column, const DCoordinate3& v_tangent);
        GLboolean GetVTangent(GLuint row, GLuint column, GLdouble& x, GLdouble& y, GLdouble& z) const;
        GLboolean GetVTangent(GLuint row, GLuint column, DCoordinate3& point) const;

        GLboolean SetTwistVector(GLuint row, GLuint column, GLdouble x, GLdouble y, GLdouble z);
        GLboolean SetTwistVector(GLuint row, GLuint column, const DCoordinate3& twist);
        GLboolean GetTwistVector(GLuint row, GLuint column, GLdouble& x, GLdouble& y, GLdouble& z) const;
        GLboolean GetTwistVector(GLuint row, GLuint column, DCoordinate3& point) const;

        GLboolean SetNoNeightbours();
        GLboolean SetNeightbours(GLuint nr, GLuint neightbour);

        GLuint GetNeightbour(GLuint nr);
    };
}
