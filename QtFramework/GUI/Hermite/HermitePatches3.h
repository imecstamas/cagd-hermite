#include "Core/TensorProductSurface3.h"

namespace cagd {
    class HermitePatch3: public TensorProductSurface3
    {
    protected:
        //possible shape parameters
    public:
        HermitePatch3 (/*  */);
        GLboolean UBlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const;
        GLboolean VBlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const;
        // (lent) ez a lelke 5-6-os lecke: project related example
        GLboolean CalculatePartialDerivatives(GLuint max_order_of_partial_derivatives, GLdouble u, GLdouble v, PartialDerivatives &pd) const; // ez a lelke 5-6-os lecke: project related example
        //setters, getters
        //setCorner, setVTangent, setUTangent(int i, int j, const DCoordinate3 l tangent), setTwistVector
    };
}
