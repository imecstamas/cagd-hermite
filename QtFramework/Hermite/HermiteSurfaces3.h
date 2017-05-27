#pragma once

#include "BicubicHermitePatches3.h"
#include "../Core/Materials.h"
#include "../Core/Constants.h"
#include "Core/ShaderPrograms.h"

namespace cagd
{
    class HermiteSurface3
    {
    public:
        class Attributes
        {
        public:
            BicubicHermitePatch3 *patch;
            TriangulatedMesh3    *img;
            Material             *material;
            ShaderProgram        *shader;

            std::vector<BicubicHermitePatch3*> neighbours;
        };

    protected:
        std::vector<Attributes> _attributes;

    public:

        GLvoid Render();

        GLvoid ContinueExistingPatch(BicubicHermitePatch3 *patch, PatchDirection dir);
    };
}
