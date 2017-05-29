#pragma once

#include <GL/glew.h>
#include <QGLWidget>
#include <QGLFormat>
#include <QTimer>
#include "Core/Matrices.h"
#include "Core/GenericCurves3.h"
#include "Core/CyclicCurves3.h"
#include "Parametric/ParametricCurves3.h"
#include "Core/TriangulatedMeshes3.h"
#include "Core/Lights.h"
#include "Core/ShaderPrograms.h"
#include "Core/Materials.h"
#include "Hermite/BicubicHermitePatches3.h"
#include "Hermite/HermiteSurfaces3.h"
#include "Hermite/HermiteArcs3.h"
#include "Hermite/CompositeHermiteCurves3.h"
#include <string.h>

namespace cagd {

    class GLWidget: public QGLWidget
    {
        Q_OBJECT

    private:

        HermiteSurface3 _surface;
        CompositeHermiteCurve3 _curve;
        //kezdo patch;
        BicubicHermitePatch3 _patch;
        TriangulatedMesh3 *_before_interpolation, *_after_interpolation;

        HermiteArc3 _arc;
        GenericCurve3* _image_of_arc;

        bool _show_patch;

        // variables defining the projection matrix
        float       _aspect;            // aspect ratio of the rendering window
        float       _fovy;              // field of view in direction y
        float       _z_near, _z_far;    // distance of near and far clipping planes

        // variables defining the model-view matrix
        float       _eye[3], _center[3], _up[3];

        // variables needed by transformations
        int         _angle_x, _angle_y, _angle_z;
        double      _zoom;
        double      _trans_x, _trans_y, _trans_z;

        // your other declarations
        // parametric curves
        GLuint _pc_curve_count, _div_point_count;
        RowMatrix<ParametricCurve3 *> _pc;
        RowMatrix<GenericCurve3 *> _img_pc;

        // cyclic curves
        CyclicCurve3* _cc;
        GenericCurve3* _image_of_cc;

        // animated models
        QTimer *_timer;
        GLfloat _angle;

        RowMatrix<TriangulatedMesh3> _models;
        RowMatrix<ShaderProgram> _shaders;
        RowMatrix<Material> _materials;

        DirectionalLight *dl0,*dl1,*dl2;

        int  _pc_index;
        bool _show_parametric_curves;
        bool _show_cyclic_curves;
        bool _show_curve_points;
        bool _show_tangent_vectors;
        bool _show_animated_model;
        int _shader_type;
        int _material_type;

    private slots:
        void _animate();
        void addHermitePatchToDirection(PatchDirection dir);
        void addHermiteArcToDirection(ArcDirection dir);

    public:
        // special and default constructor
        // the format specifies the properties of the rendering window
        GLWidget(QWidget* parent = 0, const QGLFormat& format = QGL::Rgba | QGL::DepthBuffer | QGL::DoubleBuffer);

        // redeclared virtual functions
        void initializeGL();
        void paintGL();
        void resizeGL(int w, int h);
        ~GLWidget();

    public slots:
        // public event handling methods/slots
        void set_angle_x(int value);
        void set_angle_y(int value);
        void set_angle_z(int value);

        void set_zoom_factor(double value);

        void set_trans_x(double value);
        void set_trans_y(double value);
        void set_trans_z(double value);

        void setParametricCurveIndex(int value);

        void setVisibilityOfParametricCurves(bool value);

        void setVisibilityOfCyclicCurves(bool value);

        void setShowAnimatedModel(bool value);

        void setShaderType(int value);

        void setMaterialType(int value);

        void addHermitePatchNorth();

        void addHermitePatchNorthEast();

        void addHermitePatchEast();

        void addHermitePatchSouthEast();

        void addHermitePatchSouth();

        void addHermitePatchSouthWest();

        void addHermitePatchWest();

        void addHermitePatchNorthWest();

        void setShowPatch(bool value);

    };
}
