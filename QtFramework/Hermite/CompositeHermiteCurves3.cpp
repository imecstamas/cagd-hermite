#include "CompositeHermiteCurves3.h"
#include "../Core/Constants.h"

using namespace cagd;

CompositeHermiteCurve3::CompositeHermiteCurve3(){
    _attributes.ResizeColumns(3);
}

GLvoid CompositeHermiteCurve3::Render(){
    for (GLuint i=0; i<_attributes.GetColumnCount(); ++i)
    {
        if (_attributes[i].arc && _attributes[i].image){
            glDisable(GL_LIGHTING);
            _attributes[i].image->RenderDerivatives(0, GL_LINE_STRIP);

//            glColor3f(0.0,1.0,0.0);
//            _attributes[i].image->RenderDerivatives(1,GL_LINES);
//            _attributes[i].image->RenderDerivatives(1, GL_POINTS);

//            glColor3f(0.0,0.0,1.0);
//            _attributes[i].image->RenderDerivatives(2,GL_LINES);
//            _attributes[i].image->RenderDerivatives(2, GL_POINTS);

            _attributes[i].image->UpdateVertexBufferObjects();
        }
    }
}

GLvoid CompositeHermiteCurve3::Insert(ArcDirection dir, ArcAttributes attribute){
    int d = dir;
    _attributes[d] = attribute;
}

GLvoid CompositeHermiteCurve3::Remove(ArcDirection dir){
    ArcAttributes attr;
    int d = dir;
    _attributes[d] = attr;
}

CompositeHermiteCurve3::ArcAttributes* CompositeHermiteCurve3::GetArc(ArcDirection dir)
{
    int d = dir;
    return &_attributes[d];
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
    CompositeHermiteCurve3::Insert(dir, attribute);
}

GLvoid CompositeHermiteCurve3::RemoveExistingCurve(HermiteArc3 *arc, ArcDirection dir){
    CompositeHermiteCurve3::Remove(dir);
}

GLvoid CompositeHermiteCurve3::UpdateExistingCurve(HermiteArc3 *arc, ArcAttributes &attribute, ArcDirection dir){
    DCoordinate3 cord;
    if (dir == RIGHT){
        arc->GetCorner(1,cord);
        attribute.arc->SetCorner(0,cord);
        arc->GetTangent(1,cord);
        attribute.arc->SetTangent(0,cord);
    } else if (dir == LEFT){
        arc->GetCorner(0,cord);
        attribute.arc->SetCorner(1,cord);
        arc->GetTangent(0,cord);
        attribute.arc->SetTangent(1,cord);
    }
    attribute.image = attribute.arc->GenerateImage(3, 30);
    attribute.image->UpdateVertexBufferObjects();
}
