#include "CompositeHermiteCurves3.h"
#include "../Core/Constants.h"

using namespace cagd;

GLvoid CompositeHermiteCurve3::Render(){
    for (GLuint i=0; i<_attributes.size(); ++i)
    {
        if (_attributes[i].arc && _attributes[i].image){
            glDisable(GL_LIGHTING);
            _attributes[i].image->RenderDerivatives(0, GL_LINE_STRIP);
        }
    }
}

GLvoid CompositeHermiteCurve3::Insert(ArcAttributes attribute){
    _attributes.insert(_attributes.end(), attribute);
}

GLvoid CompositeHermiteCurve3::ContinueExistingCurve(HermiteArc3 *arc, ArcAttributes attribute, ArcDirection dir){
    HermiteArc3 new_arc;
    DCoordinate3 cord;
    DCoordinate3 near, far;

    if (dir == RIGHT){
        arc->GetCorner(1,cord);
        new_arc.SetCorner(0,cord);
        arc->GetTangent(1,cord);
        new_arc.SetTangent(0,cord);

        //new Corner
        arc->GetCorner(1, near);
        arc->GetCorner(0, far);
        new_arc.SetCorner(1, 2*near - far);
    } else if (dir == LEFT){
        arc->GetCorner(0,cord);
        new_arc.SetCorner(1,cord);
        arc->GetTangent(0,cord);
        new_arc.SetTangent(1,cord);

        //new Corner
        arc->GetCorner(0, near);
        arc->GetCorner(1, far);
        new_arc.SetCorner(0, 2*near - far);
    }

    attribute.arc = &new_arc;
    attribute.image = new_arc.GenerateImage(3, 30);
    attribute.image->UpdateVertexBufferObjects();
    CompositeHermiteCurve3::Insert(attribute);
}
