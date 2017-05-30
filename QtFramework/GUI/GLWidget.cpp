#include "GLWidget.h"

#include <iostream>
#include <GL/GLU.h>
#include <Core/Exceptions.h>
#include "Test/TestFunctions.h"
#include "Core/Constants.h"
#include "Core/TriangulatedMeshes3.h"
#include "Core/Materials.h"
#include "Core/DCoordinates3.h"
#include "Hermite/HermiteSurfaces3.h"

using namespace std;

namespace cagd {

//--------------------------------
// special and default constructor
//--------------------------------
GLWidget::GLWidget(QWidget *parent, const QGLFormat &format): QGLWidget(format, parent)
{
    _timer = new QTimer(this);
    _timer->setInterval(0);

    connect(_timer, SIGNAL(timeout()), this, SLOT(_animate()));
}

//--------------------------------------------------------------------------------------
// this virtual function is called once before the first call to paintGL() or resizeGL()
//--------------------------------------------------------------------------------------
void GLWidget::initializeGL()
{

    // creating a perspective projection matrix
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    _aspect = (float)width() / (float)height();
    _z_near = 1.0;
    _z_far = 1000.0;
    _fovy = 45.0;

    gluPerspective(_fovy, _aspect, _z_near, _z_far);

    // setting the model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    _eye[0] = _eye[1] = 0.0, _eye[2] = 6.0;
    _center[0] = _center[1] = _center[2] = 0.0;
    _up[0] = _up[2] = 0.0, _up[1] = 1.0;

    gluLookAt(_eye[0], _eye[1], _eye[2], _center[0], _center[1], _center[2], _up[0], _up[1], _up[2]);

    // enabling depth test
    glEnable(GL_DEPTH_TEST);

    // setting the color of background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // initial values of transformation parameters
    _angle_x = _angle_y = _angle_z = 0.0;
    _trans_x = _trans_y = _trans_z = 0.0;
    _zoom = 1.0;

    try
    {
        // initializing the OpenGL Extension Wrangler library
        GLenum error = glewInit();

        if (error != GLEW_OK)
        {
            throw Exception("Could not initialize the OpenGL Extension Wrangler Library!");
        }

        if (!glewIsSupported("GL_VERSION_2_0"))
        {
            throw Exception("Your graphics card is not compatible with OpenGL 2.0+! "
                            "Try to update your driver or buy a new graphics adapter!");
        }

        //loading shader types
        _shaders.ResizeColumns(4);
        if (!_shaders[0].InstallShaders("Shaders/directional_light.vert","Shaders/directional_light.frag", GL_TRUE)){
            cout << "error installing shader";
        }
        if (!_shaders[1].InstallShaders("Shaders/toon.vert","Shaders/toon.frag", GL_TRUE)){
            cout << "error installing shader";
        }
        if (!_shaders[2].InstallShaders("Shaders/two_sided_lighting.vert","Shaders/two_sided_lighting.frag", GL_TRUE)){
            cout << "error installing shader";
        }
        if (!_shaders[3].InstallShaders("Shaders/reflection_lines.vert","Shaders/reflection_lines.frag", GL_TRUE)){
            cout << "error installing shader";
        }

        _shaders[1].Enable();
        _shaders[1].SetUniformVariable4f("default_outline_color", 1.0, 0.0, 0.0, 1.0);
        _shaders[1].Disable();

        _shaders[3].Enable();
        _shaders[3].SetUniformVariable1f("scale_factor", 14.0);
        _shaders[3].SetUniformVariable1f("smoothing", 1.0);
        _shaders[3].SetUniformVariable1f("shading", 0.1);
        _shaders[3].Disable();

        //materials
        _materials.ResizeColumns(7);
        _materials[0] = MatFBBrass;
        _materials[1] = MatFBEmerald;
        _materials[2] = MatFBGold;
        _materials[3] = MatFBPearl;
        _materials[4] = MatFBRuby;
        _materials[5] = MatFBSilver;
        _materials[6] = MatFBTurquoise;

//        //Negyzet
//        _patch.SetCorner(0,0,0.0,0.0,0.0);
//        _patch.SetCorner(0,1,0.0,1.0,0.0);
//        _patch.SetCorner(1,0,1.0,0.0,0.0);
//        _patch.SetCorner(1,1,1.0,1.0,0.0);

//        //Probalkozas
//        //        _patch.SetVTangent(0,0,0.0,-1.0,0.0);
//                _patch.SetVTangent(0,1,1.0,-1.0,0.0);
//        //        _patch.SetVTangent(1,0,-2.0,0.0,0.0);
//                _patch.SetVTangent(1,1,-1.0,0.0,0.0);

//                _patch.SetUTangent(0,0,1.0,1.0,1.0);
//                _patch.SetUTangent(0,1,1.0,1.0,1.0);
//                _patch.SetUTangent(1,0,1.0,2.0,0.0);
//                _patch.SetUTangent(1,1,0.0,0.0,0.0);

//                _patch.SetTwistVector(0,0,1.0,0.0,0.0);
//                _patch.SetTwistVector(0,1,0.0,0.0,0.0);
//        //        _patch.SetTwistVector(1,0,0.0,0.0,0.0);
//        //        _patch.SetTwistVector(1,1,0.0,0.0,0.0);

        _what_to_modify = 0;

        _patch.SetCorner(0,0,-2.0,-2.0,0.0);
        _patch.SetCorner(0,1,+2.0,-2.0,0.0);
        _patch.SetCorner(1,0,-2.0,+2.0,0.0);
        _patch.SetCorner(1,1,+2.0,+2.0,1.0);

        _patch.SetVTangent(0,0, 0.0,0.0,3.0);
        _patch.SetVTangent(0,1, 0.0,0.0,3.0);
        _patch.SetVTangent(1,0, 0.0,0.0,3.0);
        _patch.SetVTangent(1,1, 0.0,0.0,3.0);

        _patch.SetUTangent(0,0,0.0,0.0,-3.0);
        _patch.SetUTangent(0,1, 0.0,0.0,-3.0);
        _patch.SetUTangent(1,0,0.0,0.0,-3.0);
        _patch.SetUTangent(1,1,0.0,0.0,-3.0);

        _patch.SetTwistVector(0,0,0.0,0.0,0.0);
        _patch.SetTwistVector(0,1,0.0,0.0,0.0);
        _patch.SetTwistVector(1,0,0.0,0.0,0.0);
        _patch.SetTwistVector(1,1,0.0,0.0,0.0);

        HermiteSurface3::Attributes attribute;
        attribute.patch = &_patch;
        attribute.material = &MatFBPearl;
        attribute.shader = &_shaders[0];
        attribute.img = _patch.GenerateImage(30,30,GL_STATIC_DRAW);
        attribute.img ->UpdateVertexBufferObjects();

        _surface.Insert(START, attribute);

        _arc.SetCorner(0,-1.0, 0.0, 0.0);
        _arc.SetCorner(1,+1.0, 0.0, 0.0);
        _arc.SetTangent(0,2.0, 2.0, 0.0);
        _arc.SetTangent(1,0.0, 0.0, -3.0);

        CompositeHermiteCurve3::ArcAttributes arcAttribute;
        arcAttribute.arc = &_arc;
        arcAttribute.image = _arc.GenerateImage(3,30);
        arcAttribute.image ->UpdateVertexBufferObjects();

        _curve.Insert(arcAttribute);
        _show_patch = true;
        // parametric curves

        // create and store your geometry in display lists or vertex buffer objects
        // ...
        _pc_curve_count = 5;
        _pc.ResizeColumns(_pc_curve_count);
        _img_pc.ResizeColumns(_pc_curve_count);

        RowMatrix<ParametricCurve3::Derivative> derivative(2);
        derivative(0) = torus::d0;
        derivative(1) = torus::d1;

        _div_point_count = 100;
        _pc[0] = new ParametricCurve3(derivative,torus::u_min, torus::u_max);

        derivative(0) = lissajou::d0;
        derivative(1) = lissajou::d1;
        _pc[1] = new ParametricCurve3(derivative, lissajou::u_min, lissajou::u_max);

        derivative(0) = hypo::d0;
        derivative(1) = hypo::d1;
        _pc[2] = new ParametricCurve3(derivative, hypo::u_min, hypo::u_max);

        derivative(0) = cyclo::d0;
        derivative(1) = cyclo::d1;
        _pc[3] = new ParametricCurve3(derivative, cyclo::u_min, cyclo::u_max);

        derivative(0) = spiral_on_cone::d0;
        derivative(1) = spiral_on_cone::d1;
        _pc[4] = new ParametricCurve3(derivative, spiral_on_cone::u_min, spiral_on_cone::u_max);

        for (GLuint i = 0; i<_pc_curve_count; i++){
            _img_pc[i] = _pc[i]->GenerateImage(_div_point_count);
            _img_pc[i] -> UpdateVertexBufferObjects();
        }

        _pc_index = 0;
        _show_parametric_curves = true;
        _show_animated_model = false;
        _show_cyclic_curves = false;
        _shader_type = 0;
        _material_type = 0;

        // cyclic curves
        _cc = 0; _image_of_cc = 0;

        GLuint _n = 4;
        _cc = new CyclicCurve3(_n);
        if(!_cc)
        {
            cout << "error";
        }

        GLdouble step = TWO_PI/(2*_n+1);

        for(GLuint i = 0; i<=2*_n; ++i)
        {
            DCoordinate3 &cp = (* _cc)[i];
            GLdouble u = i*step;
            cp[0] = cos(u);
            cp[1] = sin(u);
            cp[2] = -2.0 + 4.0 *(GLdouble)rand()/(GLdouble)RAND_MAX;
        }

        if(!_cc->UpdateVertexBufferObjectsOfData())
        {
            cout << "error";
        }

        GLuint _mod = 3,_div =200;
        _image_of_cc = _cc->GenerateImage(_mod,_div);

        if(!_image_of_cc->UpdateVertexBufferObjects())
        {
            cout << "error";
        }

        //animated models
        _models.ResizeColumns(2);
        if (_models[0].LoadFromOFF("Models/mouse.off", GL_TRUE))
        {
            if (_models[0].UpdateVertexBufferObjects())
            {
                _angle = 0.0;
                _timer->start();
            }
        }

        if (_models[1].LoadFromOFF("Models/elephant.off", GL_TRUE))
        {
            _models[1].UpdateVertexBufferObjects();
        }

        //lights
        glEnable(GL_LIGHTING);
        glEnable(GL_NORMALIZE);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glEnable(GL_LIGHT2);

        HCoordinate3 direction0(0.0, 0.0, 1.0, 0.0);
        Color4 ambient0 (0.4,0.4,0.4,1.0);
        Color4 diffuse0 (0.8,0.8,0.8,1.0);
        Color4 specular0(1.0,1.0,1.0,1.0);
        dl0 = new DirectionalLight(GL_LIGHT0, direction0, ambient0, diffuse0, specular0);

        HCoordinate3 direction1(0.0, 1.0, 1.0, 0.0);
        Color4 ambient1 (0.0,0.4,0.0,1.0);
        Color4 diffuse1 (0.0,0.8,0.0,1.0);
        Color4 specular1(0.0,1.0,0.0,1.0);
        dl1 = new DirectionalLight(GL_LIGHT1, direction1, ambient0, diffuse0, specular0);
    }
    catch (Exception &e)
    {
        cout << e << endl;
    }
    emit xChanged(-2.0);
    emit yChanged(-2.0);
    emit zChanged(0.0);
}

//-----------------------
// the rendering function
//-----------------------
void GLWidget::paintGL()
{
    // clears the color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // stores/duplicates the original model view matrix
    glPushMatrix();
    //lightning
    if(dl0 && dl1){
        dl0->Enable();
        dl1->Enable();
    }
    // applying transformations
    glRotatef(_angle_x, 1.0, 0.0, 0.0);
    glRotatef(_angle_y, 0.0, 1.0, 0.0);
    glRotatef(_angle_z, 0.0, 0.0, 1.0);
    glTranslated(_trans_x, _trans_y, _trans_z);
    glScaled(_zoom, _zoom, _zoom);

    if (_show_patch){
        _surface.Render();
    }else{
        glDisable(GL_LIGHTING);
        glColor3f(1.0, 0.0, 0.0);
        _curve.Render();
//        _image_of_arc->RenderDerivatives(0, GL_LINE_STRIP);
//        _image_of_arc->RenderDerivatives(1, GL_LINES);

        //                    glColor3f(1.0,0.0,0.0);
        //                 _image_of_arc->RenderDerivatives(0,GL_LINE_LOOP);
        //                _image_of_arc->RenderDerivatives(0, GL_POINTS);

        //                glColor3f(0.0,1.0,0.0);
        //                _image_of_arc->RenderDerivatives(1,GL_LINES);
        //                _image_of_arc->RenderDerivatives(1, GL_POINTS);

        //                glColor3f(0.0,0.0,1.0);
        //                _image_of_arc->RenderDerivatives(2,GL_LINES);
        //                _image_of_arc->RenderDerivatives(2, GL_POINTS);
    }

//    if (_show_parametric_curves)
//    {
//        if (_img_pc[_pc_index])
//        {
//            //          	..szin...transzormaciok esetleg..
//            _img_pc[_pc_index]->RenderDerivatives(0, GL_LINE_LOOP);
//        }
//    }

//    if (_show_animated_model)
//    {
//        if (_pc_index % 2 == 0)
//        {
//            _pc_index = 0;
//        }
//            else
//        {
//            _pc_index = 1;
//        }

//        _shaders[_shader_type].Enable(GL_TRUE);
//        _materials[_material_type].Apply();
//        _models[_pc_index].Render();
//        _shaders[_shader_type].Disable();
//    }

//    if (_show_cyclic_curves)
//    {
//        if(_cc)
//        {
//            glColor3f(1.0,0.0,0.0);
//            _cc->RenderData(GL_LINE_LOOP);
//        }

//        if(_image_of_cc)
//        {
//            glColor3f(1.0,0.0,0.0);
//            // _image_of_cc->RenderDerivatives(0,GL_LINE_LOOP);
//            _image_of_cc->RenderDerivatives(0, GL_POINTS);
//            glColor3f(0.0,1.0,0.0);

//            _image_of_cc->RenderDerivatives(1,GL_LINES);
//            _image_of_cc->RenderDerivatives(1, GL_POINTS);

//            glColor3f(0.0,0.0,1.0);
//            _image_of_cc->RenderDerivatives(2,GL_LINES);
//            _image_of_cc->RenderDerivatives(2, GL_POINTS);
//        }
//    }

    //    // render your geometry (this is oldest OpenGL rendering technique, later we will use some advanced methods)

    // pops the current matrix stack, replacing the current matrix with the one below it on the stack,
    // i.e., the original model view matrix is restored


   // render your geometry (this is oldest OpenGL rendering technique, later we will use some advanced methods)
    if(dl0 && dl1){
        dl0->Disable();
        dl1->Disable();
    }

    // pops the current matrix stack, replacing the current matrix with the one below it on the stack,
    // i.e., the original model view matrix is restored

    glPopMatrix();
}

//----------------------------------------------------------------------------
// when the main window is resized one needs to redefine the projection matrix
//----------------------------------------------------------------------------
void GLWidget::resizeGL(int w, int h)
{
    // setting the new size of the rendering context
    glViewport(0, 0, w, h);

    // redefining the projection matrix
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    _aspect = (float)w / (float)h;

    gluPerspective(_fovy, _aspect, _z_near, _z_far);

    // switching back to the model view matrix
    glMatrixMode(GL_MODELVIEW);

    updateGL();
}

void GLWidget::_animate()
{
    GLfloat *vertex = _models[_pc_index].MapVertexBuffer(GL_READ_WRITE);
    GLfloat *normal = _models[_pc_index].MapNormalBuffer(GL_READ_ONLY);
    _angle += DEG_TO_RADIAN;
    if (_angle >= TWO_PI)
    {
        _angle -= TWO_PI;
    }
    GLfloat scale = sin(_angle) / 3000.0;
    for (GLuint i = 0 ; i < _models[_pc_index].VertexCount(); ++i)
    {
        for (GLuint coordinate = 0 ; coordinate < 3 ; ++coordinate , ++vertex , ++normal)
            *vertex += scale * (*normal) ;
    }
    _models[_pc_index].UnmapVertexBuffer();
    _models[_pc_index].UnmapNormalBuffer();
    updateGL() ;
}

//-----------------------------------
// implementation of the public slots
//-----------------------------------

void GLWidget::set_angle_x(int value)
{
    if (_angle_x != value)
    {
        _angle_x = value;
        updateGL();
    }
}

void GLWidget::set_angle_y(int value)
{
    if (_angle_y != value)
    {
        _angle_y = value;
        updateGL();
    }
}

void GLWidget::set_angle_z(int value)
{
    if (_angle_z != value)
    {
        _angle_z = value;
        updateGL();
    }
}

void GLWidget::set_zoom_factor(double value)
{
    if (_zoom != value)
    {
        _zoom = value;
        updateGL();
    }
}

void GLWidget::set_trans_x(double value)
{
    if (_trans_x != value)
    {
        _trans_x = value;
        updateGL();
    }
}

void GLWidget::set_trans_y(double value)
{
    if (_trans_y != value)
    {
        _trans_y = value;
        updateGL();
    }
}

void GLWidget::set_trans_z(double value)
{
    if (_trans_z != value)
    {
        _trans_z = value;
        updateGL();
    }
}

void GLWidget::setParametricCurveIndex(int value)
{
    if (_pc_index != value)
    {
        _pc_index = value;
        if (_models[_pc_index].UpdateVertexBufferObjects())
        {
            _angle = 0.0;
            _timer->start();
        }
        updateGL();
    }
}

void GLWidget::setVisibilityOfParametricCurves(bool value)
{
    if (_show_parametric_curves != value)
    {
        _show_parametric_curves = value;
        updateGL();
    }
}

void GLWidget::setVisibilityOfCyclicCurves(bool value)
{
    if (_show_cyclic_curves != value)
    {
        _show_cyclic_curves = value;
        updateGL();
    }
}

void GLWidget::setShowAnimatedModel(bool value)
{
    if (_show_animated_model != value)
    {
        _show_animated_model = value;
        updateGL();
    }
}

void GLWidget::setShaderType(int value)
{
    value = value %4;
    if (_shader_type != value){
        _shader_type = value;
        updateGL();
    }
}

void GLWidget::setMaterialType(int value)
{
    if (_material_type != value)
    {
        _material_type = value;
        updateGL();
    }
}

void GLWidget::addHermitePatchToDirection(PatchDirection dir)
{
    HermiteSurface3::Attributes attribute;
    attribute.material = &_materials[_material_type];
    attribute.shader = &_shaders[_shader_type];
    _surface.ContinueExistingPatch(&_patch,attribute,dir);
    updateGL();
}

void GLWidget::addHermiteArcToDirection(ArcDirection dir)
{
    CompositeHermiteCurve3::ArcAttributes arcAttribute;
    _curve.ContinueExistingCurve(&_arc, arcAttribute, dir);
}

void GLWidget::addHermiteArcLeft(){
    addHermiteArcToDirection(LEFT);
}

void GLWidget::addHermiteArcRight(){
    addHermiteArcToDirection(RIGHT);
}


void GLWidget::addHermitePatchNorth()
{
    addHermitePatchToDirection(N);
}

void GLWidget::addHermitePatchNorthEast()
{
    addHermitePatchToDirection(NE);
}

void GLWidget::addHermitePatchEast()
{
    addHermitePatchToDirection(E);
}

void GLWidget::addHermitePatchSouthEast()
{
    addHermitePatchToDirection(SE);
}

void GLWidget::addHermitePatchSouth()
{
    addHermitePatchToDirection(S);
}

void GLWidget::addHermitePatchSouthWest()
{
    addHermitePatchToDirection(SW);
}

void GLWidget::addHermitePatchWest()
{
    addHermitePatchToDirection(W);
}

void GLWidget::addHermitePatchNorthWest()
{
    addHermitePatchToDirection(NW);
}

void GLWidget::setShowPatch(bool value)
{
    if (_show_patch != value)
    {
        _show_patch = value;
        updateGL();
    }
}

void GLWidget::setWhatToModify(int value)
{
    DCoordinate3 point;
    if (_what_to_modify != value)
    {
        _what_to_modify = value;
        if (_what_to_modify == 0){
            _patch.GetCorner(0,0,point);
        }else if (_what_to_modify == 1){
            _patch.GetVTangent(0,0,point);
        }else if (_what_to_modify == 2){
            _patch.GetUTangent(0,0,point);
        }else{
            _patch.GetTwistVector(0,0,point);
        }
        emit xChanged(point.x());
        emit yChanged(point.y());
        emit zChanged(point.z());
    }
}

void GLWidget::setX(double value)
{
    DCoordinate3 point;
    HermiteSurface3::Attributes *attribute, *attributeNorth, *attributeNorthWest, *attributeWest;
    attribute = _surface.GetPatch(START);
    attributeNorth = _surface.GetPatch(N);
    attributeNorthWest = _surface.GetPatch(NW);
    attributeWest = _surface.GetPatch(W);

    if (_what_to_modify == 0){
        attribute->patch->GetCorner(0,0, point);
        attribute->patch->SetCorner(0,0,value,point.y(), point.z());
    }else if (_what_to_modify == 1){
        attribute->patch->GetVTangent(0,0, point);
        attribute->patch->SetVTangent(0,0,value,point.y(), point.z());
    }else if (_what_to_modify == 2){
        attribute->patch->GetUTangent(0,0, point);
        attribute->patch->SetUTangent(0,0,value,point.y(), point.z());
    }else {
        attribute->patch->GetTwistVector(0,0, point);
        attribute->patch->SetTwistVector(0,0,value,point.y(), point.z());
    }
    attribute->img = attribute->patch->GenerateImage(30,30,GL_STATIC_DRAW);
    attribute->img->UpdateVertexBufferObjects();

    if (attributeNorth && attributeNorth->patch)
    {
        _surface.UpdateExistingPatch(attribute->patch,*attributeNorth,N);
    }
    if (attributeNorthWest && attributeNorthWest->patch)
    {
        _surface.UpdateExistingPatch(attribute->patch,*attributeNorthWest,NW);
    }
    if (attributeWest && attributeWest->patch)
    {
        _surface.UpdateExistingPatch(attribute->patch,*attributeWest,W);
    }

    updateGL();
}

void GLWidget::setY(double value)
{    
    DCoordinate3 point;
    HermiteSurface3::Attributes *attribute, *attributeNorth, *attributeNorthWest, *attributeWest;
    attribute = _surface.GetPatch(START);
    attributeNorth = _surface.GetPatch(N);
    attributeNorthWest = _surface.GetPatch(NW);
    attributeWest = _surface.GetPatch(W);
    if (_what_to_modify == 0){
        attribute->patch->GetCorner(0,0, point);
        attribute->patch->SetCorner(0,0,point.x(),value, point.z());
    }else if (_what_to_modify == 1){
        attribute->patch->GetVTangent(0,0, point);
        attribute->patch->SetVTangent(0,0,point.x(),value, point.z());
    }else if (_what_to_modify == 2){
        attribute->patch->GetUTangent(0,0, point);
        attribute->patch->SetUTangent(0,0,point.x(),value, point.z());
    }else {
        attribute->patch->GetTwistVector(0,0, point);
        attribute->patch->SetTwistVector(0,0,point.x(),value, point.z());
    }
    attribute->img = attribute->patch->GenerateImage(30,30,GL_STATIC_DRAW);
    attribute->img->UpdateVertexBufferObjects();
    if (attributeNorth && attributeNorth->patch)
    {
        _surface.UpdateExistingPatch(attribute->patch,*attributeNorth,N);
    }
    if (attributeNorthWest && attributeNorthWest->patch)
    {
        _surface.UpdateExistingPatch(attribute->patch,*attributeNorthWest,NW);
    }
    if (attributeWest && attributeWest->patch)
    {
        _surface.UpdateExistingPatch(attribute->patch,*attributeWest,W);
    }
    updateGL();
}

void GLWidget::setZ(double value)
{
    DCoordinate3 point;
    HermiteSurface3::Attributes *attribute, *attributeNorth, *attributeNorthWest, *attributeWest;
    attribute = _surface.GetPatch(START);
    attributeNorth = _surface.GetPatch(N);
    attributeNorthWest = _surface.GetPatch(NW);
    attributeWest = _surface.GetPatch(W);
    if (_what_to_modify == 0){
        attribute->patch->GetCorner(0,0, point);
        attribute->patch->SetCorner(0,0,point.x(),point.y(), value);
    }else if (_what_to_modify == 1){
        attribute->patch->GetVTangent(0,0, point);
        attribute->patch->SetVTangent(0,0,point.x(),point.y(), value);
    }else if (_what_to_modify == 2){
        attribute->patch->GetUTangent(0,0, point);
        attribute->patch->SetUTangent(0,0,point.x(),point.y(), value);
    }else {
        attribute->patch->GetTwistVector(0,0, point);
        attribute->patch->SetTwistVector(0,0,point.x(),point.y(), value);
    }
    attribute->img = attribute->patch->GenerateImage(30,30,GL_STATIC_DRAW);
    attribute->img->UpdateVertexBufferObjects();
    if (attributeNorth && attributeNorth->patch)
    {
        _surface.UpdateExistingPatch(attribute->patch,*attributeNorth,N);
    }
    if (attributeNorthWest && attributeNorthWest->patch)
    {
        _surface.UpdateExistingPatch(attribute->patch,*attributeNorthWest,NW);
    }
    if (attributeWest && attributeWest->patch)
    {
        _surface.UpdateExistingPatch(attribute->patch,*attributeWest,W);
    }
    updateGL();
}

GLWidget::~GLWidget()
{

}
}
