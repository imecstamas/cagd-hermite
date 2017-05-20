#pragma once

#include "LinearCombination3.h"
#include "Matrices.h"

namespace cagd {
    class CyclicCurve3: public LinearCombination3 {

    protected:
        GLuint _n; //order
        GLdouble _c_n; //normalizing constant
        GLdouble _lambda_n; //phase change

//        TriangularMatrix _bc;//binomialcoefficients
        //               !
        TriangularMatrix<GLdouble> _bc;//binomialcoefficients

        GLdouble _CalculateNormalizingCoefficient(GLuint n);

//        GLvoid _CalculateBinomialCoefficients(GLuint m, RealSquareMatrix &bc);
        //                                              !               !
        GLvoid _CalculateBinomialCoefficients(GLuint m, TriangularMatrix<GLdouble> &bc);

    public:
        //specialconstructor
        CyclicCurve3(GLuint n,GLenum data_usage_flag=GL_STATIC_DRAW);

        //redeclareanddefineinheritedpurevirtualmethods
        GLboolean BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const;
        GLboolean CalculateDerivatives(GLuint max_order_of_derivatives, GLdouble u, Derivatives &d) const;
    };
}
