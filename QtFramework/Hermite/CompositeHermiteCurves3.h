#pragma once

#include "HermiteArcs3.h"
#include "../Core/Colors4.h"

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

            ArcAttributes()
            {
                *arc = nullptr;
                *image = nullptr;
                *color = nullptr;
                *next = nullptr;
                *prev = nullptr;
            }
        };

    protected:
        std::vector<ArcAttributes> _attributes;

    public:
        // (copy) ctor, operator =, dtor
        // insert, erase, continue, join, merge arcs
        // render
    };

}
