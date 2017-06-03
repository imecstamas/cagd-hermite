#pragma once

#include "HermiteArcs3.h"
#include "../Core/Colors4.h"
#include "../Core/Constants.h"

namespace cagd
{
    class CompositeHermiteCurve3
    {
    public:
        class ArcAttributes
        {
        public:
            HermiteArc3     *arc;       // (*arc)[i][0]
            GenericCurve3   *image;     // arc->GenerateImage, image->{UpdateVertexBufferObjects|RenderDerivatives}
            Color4          *color;
            // ...
            //esetleg lehetne listat hasznalni az enumbeli index-ekkel
            ArcAttributes   *next, *prev;
        };

    protected:
        RowMatrix<ArcAttributes> _attributes;

    public:

        CompositeHermiteCurve3();

        GLvoid CompositeHermiteCurve3::Insert(ArcDirection dir, ArcAttributes attribute);

        ArcAttributes* CompositeHermiteCurve3::GetArc(ArcDirection dir);

        GLvoid CompositeHermiteCurve3::Render();

        GLvoid CompositeHermiteCurve3::ContinueExistingCurve(HermiteArc3 *curve, ArcAttributes attribute, ArcDirection dir);

        GLvoid CompositeHermiteCurve3::UpdateExistingCurve(HermiteArc3 *curve, ArcAttributes &attribute, ArcDirection dir);

        // (copy) ctor, operator =, dtor
        // insert, erase, continue, join, merge arcs
        // render
    };

}
