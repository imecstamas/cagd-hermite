#pragma once

#include "../Core/LinearCombination3.h"

namespace cagd
{
    class HermiteArc3: public LinearCombination3
    {
    public:
        HermiteArc3();

        GLboolean BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble>& values) const;
        GLboolean CalculateDerivatives(GLuint max_order_of_derivatives, GLdouble u, Derivatives& d) const;

        GLboolean SetCorner(GLuint corner_index, GLdouble x, GLdouble y, GLdouble z);
        GLboolean SetCorner(GLuint corner_index, const DCoordinate3 &v);

        GLboolean SetTangent(GLuint corner_index, GLdouble x, GLdouble y, GLdouble z);
        GLboolean SetTangent(GLuint corner_index, const DCoordinate3 &v);
    };
}
