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

            Attributes()
            {
                patch    = nullptr;
                img      = nullptr;
                material = nullptr;
                shader   = nullptr;
            }

            Attributes(const Attributes &attributes):
                patch(attributes.patch ? new BicubicHermitePatch3(*attributes.patch) : nullptr),
                img(attributes.img ? new TriangulatedMesh3(*attributes.img) : nullptr),
                material(attributes.material),
                shader(attributes.shader)
            {
            }

            Attributes& operator =(const Attributes &attributes)
            {
                if (this != &attributes)
                {
                    if (patch)
                    {
                        delete patch, patch = nullptr;
                    }

                    if (img)
                    {
                        delete img, img = nullptr;
                    }

                    patch = (attributes.patch ? new BicubicHermitePatch3(*attributes.patch) : nullptr),
                    img = (attributes.img ? new TriangulatedMesh3(*attributes.img) : nullptr),
                    material = (attributes.material),
                    shader = (attributes.shader);
                }

                return *this;
            }
        };

    protected:
        RowMatrix<Attributes> _attributes;

    public:

        HermiteSurface3();

        GLvoid HermiteSurface3::Insert(PatchDirection dir, Attributes attribute);

        Attributes* HermiteSurface3::GetPatch(PatchDirection dir);

        GLvoid HermiteSurface3::Render();

        GLvoid HermiteSurface3::ContinueExistingPatch(BicubicHermitePatch3 *patch, Attributes attribute, PatchDirection dir);

        GLvoid HermiteSurface3::UpdateExistingPatch(BicubicHermitePatch3 *patch, Attributes &attribute, PatchDirection dir);
    };
}
