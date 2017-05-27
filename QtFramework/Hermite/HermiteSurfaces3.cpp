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
    DCoordinate3 cord;
    Attributes attribute;
    DCoordinate3 near, far;
    if (dir == N){
        patch->GetCorner(0,0, cord);
        new_patch.SetCorner(1,0, cord);
        patch->GetVTangent(0,0, cord);
        new_patch.SetVTangent(1,0, cord);
        patch->GetUTangent(0,0, cord);
        new_patch.SetUTangent(1,0, cord);
        patch->GetTwistVector(0,0, cord);
        new_patch.SetTwistVector(1,0, cord);

        patch->GetCorner(0,1, cord);
        new_patch.SetCorner(1,1, cord);
        patch->GetVTangent(0,1, cord);
        new_patch.SetVTangent(1,1, cord);
        patch->GetUTangent(0,1, cord);
        new_patch.SetUTangent(1,1, cord);
        patch->GetTwistVector(0,1, cord);
        new_patch.SetTwistVector(1,1, cord);

        //new Corners
        patch->GetCorner(0,0, near);
        patch->GetCorner(1,0, far);
        new_patch.SetCorner(0, 0, 2*near - far);

        patch->GetCorner(0,1, near);
        patch->GetCorner(1,1, far);
        new_patch.SetCorner(0,1, 2*near - far);

        attribute.material = &MatFBGold;
        attribute.img = new_patch.GenerateImage(30,30,GL_STATIC_DRAW);
        attribute.img ->UpdateVertexBufferObjects();
        HermiteSurface3::Insert(attribute);
    } else if (dir == W){
        patch->GetCorner(0,0, cord);
        new_patch.SetCorner(0,1, cord);
        patch->GetVTangent(0,0, cord);
        new_patch.SetVTangent(0,1, cord);
        patch->GetUTangent(0,0, cord);
        new_patch.SetUTangent(0,1, cord);
        patch->GetTwistVector(0,0, cord);
        new_patch.SetTwistVector(0,1, cord);

        patch->GetCorner(1,0, cord);
        new_patch.SetCorner(1,1, cord);
        patch->GetVTangent(1,0, cord);
        new_patch.SetVTangent(1,1, cord);
        patch->GetUTangent(1,0, cord);
        new_patch.SetUTangent(1,1, cord);
        patch->GetTwistVector(1,0, cord);
        new_patch.SetTwistVector(1,1, cord);

        //new Corners
        patch->GetCorner(0,0, near);
        patch->GetCorner(0,1, far);
        new_patch.SetCorner(0,0, 2*near - far);

        patch->GetCorner(1,0, near);
        patch->GetCorner(1,1, far);
        new_patch.SetCorner(1,0, 2*near - far);

        attribute.material = &MatFBBrass;
        attribute.img = new_patch.GenerateImage(30,30,GL_STATIC_DRAW);
        attribute.img ->UpdateVertexBufferObjects();
        HermiteSurface3::Insert(attribute);
    } else if (dir == S){

        patch->GetCorner(1,0, cord);
        new_patch.SetCorner(0,0, cord);
        patch->GetVTangent(1,0, cord);
        new_patch.SetVTangent(0,0, cord);
        patch->GetUTangent(1,0, cord);
        new_patch.SetUTangent(0,0, cord);
        patch->GetTwistVector(1,0, cord);
        new_patch.SetTwistVector(0,0, cord);

        patch->GetCorner(1,1, cord);
        new_patch.SetCorner(0,1, cord);
        patch->GetVTangent(1,1, cord);
        new_patch.SetVTangent(0,1, cord);
        patch->GetUTangent(1,1, cord);
        new_patch.SetUTangent(0,1, cord);
        patch->GetTwistVector(1,1, cord);
        new_patch.SetTwistVector(0,1, cord);

        //new Corners
        patch->GetCorner(1,0, near);
        patch->GetCorner(0,0, far);
        new_patch.SetCorner(1,0, 2*near - far);

        patch->GetCorner(1,1, near);
        patch->GetCorner(0,1, far);
        new_patch.SetCorner(1,1, 2*near - far);

        attribute.material = &MatFBEmerald;
        attribute.img = new_patch.GenerateImage(30,30,GL_STATIC_DRAW);
        attribute.img ->UpdateVertexBufferObjects();
        HermiteSurface3::Insert(attribute);
    } else if (dir == E) {
        patch->GetCorner(0, 1, cord);
        new_patch.SetCorner(0, 0, cord);
        patch->GetVTangent(0, 1, cord);
        new_patch.SetVTangent(0, 0, cord);
        patch->GetUTangent(0, 1, cord);
        new_patch.SetUTangent(0, 0, cord);
        patch->GetTwistVector(0, 1, cord);
        new_patch.SetTwistVector(0, 0, cord);

        patch->GetCorner(1, 1, cord);
        new_patch.SetCorner(1, 0, cord);
        patch->GetVTangent(1, 1, cord);
        new_patch.SetVTangent(1, 0, cord);
        patch->GetUTangent(1, 1, cord);
        new_patch.SetUTangent(1, 0, cord);
        patch->GetTwistVector(1, 1, cord);
        new_patch.SetTwistVector(1, 0, cord);

        //new Corners
        patch->GetCorner(0,1, near);
        patch->GetCorner(0,0, far);
        new_patch.SetCorner(0,1, 2*near - far);

        patch->GetCorner(1,1, near);
        patch->GetCorner(1,0, far);
        new_patch.SetCorner(1,1, 2*near - far);

        attribute.material = &MatFBSilver;
        attribute.img = new_patch.GenerateImage(30,30,GL_STATIC_DRAW);
        attribute.img ->UpdateVertexBufferObjects();
        HermiteSurface3::Insert(attribute);
    }
}

