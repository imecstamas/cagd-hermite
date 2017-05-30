#include "HermiteSurfaces3.h"

using namespace cagd;

HermiteSurface3::HermiteSurface3()
{
    _attributes.ResizeColumns(9);
}

GLvoid HermiteSurface3::Render(){
    for (GLuint i=0; i<_attributes.GetColumnCount(); ++i)
    {
        if (_attributes[i].patch && _attributes[i].img && _attributes[i].material && _attributes[i].shader){
            _attributes[i].shader->Enable(GL_TRUE);
            _attributes[i].material->Apply();
            _attributes[i].img->Render();
            _attributes[i].shader->Disable();
        }
    }
}

GLvoid HermiteSurface3::Insert(PatchDirection dir,Attributes attribute){
    int d = dir;
    _attributes[d] = attribute;
}

HermiteSurface3::Attributes* HermiteSurface3::GetPatch(int index)
{
    return &_attributes[index];
}

GLvoid HermiteSurface3::ContinueExistingPatch(BicubicHermitePatch3 *patch, Attributes attribute, PatchDirection dir){
    BicubicHermitePatch3 new_patch;
    DCoordinate3 cord;
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
    } else if (dir == NW) {
        patch->GetCorner(0,0, cord);
        new_patch.SetCorner(1,1, cord);
        patch->GetVTangent(0,0, cord);
        new_patch.SetVTangent(1,1, cord);
        patch->GetUTangent(0,0, cord);
        new_patch.SetUTangent(1,1, cord);
        patch->GetTwistVector(0,0, cord);
        new_patch.SetTwistVector(1,1, cord);

        //new Corners
        patch->GetCorner(0,0, near);
        patch->GetCorner(1,1, far);
        new_patch.SetCorner(0,0, 2*near - far);

        patch->GetCorner(1,0, far);
        new_patch.SetCorner(0,1, 2*near - far);

        patch->GetCorner(0,1, far);
        new_patch.SetCorner(1,0, 2*near - far);
    } else if (dir == SW) {
        patch->GetCorner(1,0, cord);
        new_patch.SetCorner(0,1, cord);
        patch->GetVTangent(1,0, cord);
        new_patch.SetVTangent(0,1, cord);
        patch->GetUTangent(1,0, cord);
        new_patch.SetUTangent(0,1, cord);
        patch->GetTwistVector(1,0, cord);
        new_patch.SetTwistVector(0,1, cord);

        //new Corners
        patch->GetCorner(1,0, near);
        patch->GetCorner(0,1, far);
        new_patch.SetCorner(1,0, 2*near - far);

        patch->GetCorner(1,1, far);
        new_patch.SetCorner(0,0, 2*near - far);

        patch->GetCorner(0,0, far);
        new_patch.SetCorner(1,1, 2*near - far);
    } else if (dir == SE) {
        patch->GetCorner(1,1, cord);
        new_patch.SetCorner(0,0, cord);
        patch->GetVTangent(1,1, cord);
        new_patch.SetVTangent(0,0, cord);
        patch->GetUTangent(1,1, cord);
        new_patch.SetUTangent(0,0, cord);
        patch->GetTwistVector(1,1, cord);
        new_patch.SetTwistVector(0,0, cord);

        //new Corners
        patch->GetCorner(1,1, near);
        patch->GetCorner(0,0, far);
        new_patch.SetCorner(1,1, 2*near - far);

        patch->GetCorner(0,1, far);
        new_patch.SetCorner(1,0, 2*near - far);

        patch->GetCorner(1,0, far);
        new_patch.SetCorner(0,1, 2*near - far);
    } else if (dir == NE){
        patch->GetCorner(0,1, cord);
        new_patch.SetCorner(1,0, cord);
        patch->GetVTangent(0,1, cord);
        new_patch.SetVTangent(1,0, cord);
        patch->GetUTangent(0,1, cord);
        new_patch.SetUTangent(1,0, cord);
        patch->GetTwistVector(0,1, cord);
        new_patch.SetTwistVector(1,0, cord);

        //new Corners
        patch->GetCorner(0,1, near);
        patch->GetCorner(1,0, far);
        new_patch.SetCorner(0,1, 2*near - far);

        patch->GetCorner(1,1, far);
        new_patch.SetCorner(0,0, 2*near - far);

        patch->GetCorner(0,0, far);
        new_patch.SetCorner(1,1, 2*near - far);
    }

    attribute.patch = &new_patch;
    attribute.img = new_patch.GenerateImage(30,30,GL_STATIC_DRAW);
    attribute.img ->UpdateVertexBufferObjects();
    HermiteSurface3::Insert(dir, attribute);
}

