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
        RowMatrix<Attributes> _attributes;

    public:

        HermiteSurface3();

        GLvoid HermiteSurface3::Insert(PatchDirection dir, Attributes attribute);

        Attributes* HermiteSurface3::GetPatch(PatchDirection dir);

        GLvoid HermiteSurface3::Render();

        GLvoid HermiteSurface3::ContinueExistingPatch(BicubicHermitePatch3 *patch, Attributes attribute, PatchDirection dir);
    };
}
