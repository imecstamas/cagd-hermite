#include "HermiteSurfaces3.h"

using namespace cagd;

GLvoid HermiteSurface3::Render(){
    for (GLuint i=0; i<_attributes.size(); ++i)
    {
        if (_attributes[i].patch && _attributes[i].img && _attributes[i].material){
//            _attributes[i].shader->Enable(GL_TRUE);//TODO disable after render
            _attributes[i].material->Apply();
            _attributes[i].img->Render();
        }
    }
}

GLvoid HermiteSurface3::Insert(Attributes attribute){
    _attributes.insert(_attributes.end(), attribute);
}

GLvoid HermiteSurface3::ContinueExistingPatch(BicubicHermitePatch3 *patch, PatchDirection dir){
    BicubicHermitePatch3 new_patch;
//    switch (dir) {
//    case 0:
        DCoordinate3 cord;
        patch->GetCorner(0, 0, cord);
        new_patch.SetCorner(1, 0, cord);
        patch->GetVTangent(0, 0, cord);
        new_patch.SetVTangent(1, 0, cord);
        patch->GetUTangent(0, 0, cord);
        new_patch.SetUTangent(1, 0, cord);
        patch->GetTwistVector(0, 0, cord);
        new_patch.SetTwistVector(1, 0, cord);

        patch->GetCorner(0, 1, cord);
        new_patch.SetCorner(1, 1, cord);
        patch->GetVTangent(0, 1, cord);
        new_patch.SetVTangent(1, 1, cord);
        patch->GetUTangent(0, 1, cord);
        new_patch.SetUTangent(1, 1, cord);
        patch->GetTwistVector(0, 1, cord);
        new_patch.SetTwistVector(1, 1, cord);

        DCoordinate3 newCorner00, oldCorner10;
        patch->GetCorner(0,0, newCorner00);
        patch->GetCorner(1,0, oldCorner10);
        newCorner00 = 2*newCorner00 - oldCorner10;
        new_patch.SetCorner(0, 0, newCorner00);

        DCoordinate3 newCorner01, oldCorner11;
        patch->GetCorner(0,1, newCorner01);
        patch->GetCorner(1,1, oldCorner11);
        newCorner01 = 2*newCorner01 - oldCorner11;
        new_patch.SetCorner(0, 1, newCorner01);

        Attributes attribute;
        attribute.material = &MatFBGold;
        attribute.img = new_patch.GenerateImage(30,30,GL_STATIC_DRAW);
        attribute.img ->UpdateVertexBufferObjects();
        _attributes.insert(_attributes.end(), attribute);

//        break;
//    case 1:
//        //NORTH-WEST
//        break;
//    case 2:
//        //WEST
//        break;
//    case 3:
//        //SOUTH-WEST
//        break;
//    case 4:
//        //SOUTH
//        break;
//    case 5:
//        //SOUTH-EAST
//        break;
//    case 6:
//        //EAST
//        break;
//    case 7:
//        //NORTH-EAST
//        break;
//    default:
//        break;
//    }
}

