#include "CompositeHermiteCurves3.h"

using namespace cagd;

GLvoid CompositeHermiteCurve3::Render(){
    //TODO
}

GLvoid CompositeHermiteCurve3::Insert(ArcAttributes attribute){
    _attributes.insert(_attributes.end(), attribute);
}

GLvoid CompositeHermiteCurve3::ContinueExistingCurve(CompositeHermiteCurve3 *arc, ArcAttributes attribute, ArcDirection dir){
    HermiteArc3 new_arc;

    if (dir == RIGHT){

    } else if (dir == LEFT){

    }
}
