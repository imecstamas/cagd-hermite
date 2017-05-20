#include "HermitePatches3.h"

namespace cagd {
    class HermiteCompositeSurface3
    {
    protected:
        std::vector<PatchAttributes> _attributes;
        //possible shape parameters
    public:
        class PatchAttributes
        {
        public:
            HermitePatch3 *patch; //ez a lelke
            TriangulatedfMesh3 *image;
            Material *material;
            ShaderProgram *shader;
            std::vector<PatchAttributes*> neighbours; //8
            //default constructor -> nullptr;
        };

        //constr, copy constr, destrc, =
        //insert, join, merge (existing) patch(es)
        //enum Direction{N=0,NW,W,SW,S,SE,E,NE}
    };
}
