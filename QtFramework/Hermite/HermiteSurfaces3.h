#pragma once

#include "BicubicHermitePatches3.h"
#include "../Core/Materials.h"

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

            std::vector<BicubicHermitePatch3*> neighbours;
        };

        std::vector<Attributes> _attributes;

        void Render(){
            for (GLuint i=0; i<_attributes.size(); ++i)
            {
                if (_attributes[i].patch && _attributes[i].img && _attributes[i].material){
                    _attributes[i].material -> Apply();
                    _attributes[i].img -> Render();
                }
            }
        }

        void InsertNewIsolatedPatch(BicubicHermitePatch3 patch){
            Attributes surface;
            surface.patch = &patch;
            //surface.patch->SetNoNeightbours();
            surface.material = &MatFBRuby;
            surface.img = patch.GenerateImage(30,30,GL_STATIC_DRAW);
            surface.img->UpdateVertexBufferObjects();
            _attributes.insert(_attributes.end(),surface);
        }

        void ContinueExistingPatchToRight(BicubicHermitePatch3 *patch, DCoordinate3 right_bottom, DCoordinate3 right_top){
            BicubicHermitePatch3 new_patch;
            GLdouble x,y,z;

            patch->GetData(1, 0, x, y, z);
            new_patch.SetCorner(0,0,x,y,z);

            patch->GetData(1, 1, x, y, z);
            new_patch.SetCorner(0,1,x,y,z);

            new_patch.SetCorner(1,0,right_bottom);
            new_patch.SetCorner(1,1,right_top);
            InsertNewIsolatedPatch(new_patch);



            //patch.SetNeightbours(2, _nr_of_patches);

//            _patches[_nr_of_patches].SetNoNeightbours();

//            _patches[_patch_number].SetNeightbours(0, _nr_of_patches);

//            _patches[_nr_of_patches].SetNeightbours(4, _patch_number);
        }
    };
}
