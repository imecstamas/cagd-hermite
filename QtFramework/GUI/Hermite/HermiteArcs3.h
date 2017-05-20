#include "Core/LinearCombination3.h"

namespace cagd {
    class HermiteArc3 : public LinearCombination3
    {
    public:
        HermiteArc3 (/* possible parameters */);
        GLboolean BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const;
        GLboolean CalculateDerivatives(GLuint max_order_of_derivatives, GLdouble u, Derivatives &d) const;
        //setters, getters
    };
}
