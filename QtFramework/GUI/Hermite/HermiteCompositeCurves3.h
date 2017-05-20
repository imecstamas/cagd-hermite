#include "HermiteArcs3.h"

namespace cagd {
    class HermiteCompositeCurve3
    {
    protected:
        std::vector<ArcAttributes> _attributes;
     public:
        class ArcAttributes
        {
        public:
            HermiteArc3 *arc;
            GenericCurve3 *image;
//            Color4 *color;
            ArcAttributes *next, *previous;
        };//default construtor

        //constructor, copy constructor, destructor, =
        //insert new isolated arc
//        continue existing arc based on a selected direction (enum Direction{LEFT,RIGHT})
        //join existing two arcs
        //glue, merge existing two arcs
        //translate/scale/rotate
    };
}
