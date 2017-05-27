#include "HermiteSurfaces3.h"

using namespace cagd;

GLvoid HermiteSurface3::Render(){
    for (GLuint i=0; i<_attributes.size(); ++i)
    {
        if (_attributes[i].patch && _attributes[i].img && _attributes[i].material){
            _attributes[i].shader->Enable(GL_TRUE);
            _attributes[i].material->Apply();
            _attributes[i].img->Render();
        }
    }
}

GLvoid HermiteSurface3::ContinueExistingPatch(BicubicHermitePatch3 *patch, PatchDirection dir){
    BicubicHermitePatch3 new_patch;
    switch (dir) {
    case 0:
        //NORTH
        break;
    case 1:
        //NORTH-WEST
        break;
    case 2:
        //WEST
        break;
    case 3:
        //SOUTH-WEST
        break;
    case 4:
        //SOUTH
        break;
    case 5:
        //SOUTH-EAST
        break;
    case 6:
        //EAST
        break;
    case 7:
        //NORTH-EAST
        break;
    default:
        break;
    }
}

