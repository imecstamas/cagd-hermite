#pragma once

#include "../Core/LinearCombination3.h"

namespace cagd
{
    class HermiteArc3: public LinearCombination3
    {
    public:
        HermiteArc3();

        GLboolean BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble>& blending_values) const;
        GLboolean CalculateDerivatives(GLuint max_order_of_derivatives, GLdouble u, Derivatives& d) const;

        GLboolean SetCorner(GLuint corner_index, GLdouble x, GLdouble y, GLdouble z);
        GLboolean SetCorner(GLuint corner_index, const DCoordinate3 &v);
        GLboolean GetCorner(GLuint index, GLdouble x, GLdouble y, GLdouble z) const;
        GLboolean GetCorner(GLuint index, DCoordinate3& point) const;

        GLboolean SetTangent(GLuint corner_index, GLdouble x, GLdouble y, GLdouble z);
        GLboolean SetTangent(GLuint corner_index, const DCoordinate3 &v);
        GLboolean GetTangent(GLuint index, GLdouble x, GLdouble y, GLdouble z) const;
        GLboolean GetTangent(GLuint index, DCoordinate3& point) const;
    };
}
