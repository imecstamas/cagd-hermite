#include "MainWindow.h"
#include "Core/Constants.h"

namespace cagd
{
    MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    {
        setupUi(this);

    /*

      the structure of the main window's central widget

     *---------------------------------------------------*
     |                 central widget                    |
     |                                                   |
     |  *---------------------------*-----------------*  |
     |  |     rendering context     |   scroll area   |  |
     |  |       OpenGL widget       | *-------------* |  |
     |  |                           | | side widget | |  |
     |  |                           | |             | |  |
     |  |                           | |             | |  |
     |  |                           | *-------------* |  |
     |  *---------------------------*-----------------*  |
     |                                                   |
     *---------------------------------------------------*

    */
        _side_widget = new SideWidget(this);

        _scroll_area = new QScrollArea(this);
        _scroll_area->setWidget(_side_widget);
        _scroll_area->setSizePolicy(_side_widget->sizePolicy());
        _scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        _gl_widget = new GLWidget(this);

        centralWidget()->setLayout(new QHBoxLayout());
        centralWidget()->layout()->addWidget(_gl_widget);
        centralWidget()->layout()->addWidget(_scroll_area);

        // creating a signal slot mechanism between the rendering context and the side widget
        connect(_side_widget->rotate_x_slider, SIGNAL(valueChanged(int)), _gl_widget, SLOT(set_angle_x(int)));
        connect(_side_widget->rotate_y_slider, SIGNAL(valueChanged(int)), _gl_widget, SLOT(set_angle_y(int)));
        connect(_side_widget->rotate_z_slider, SIGNAL(valueChanged(int)), _gl_widget, SLOT(set_angle_z(int)));

        connect(_side_widget->zoom_factor_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_zoom_factor(double)));

        connect(_side_widget->trans_x_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_trans_x(double)));
        connect(_side_widget->trans_y_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_trans_y(double)));
        connect(_side_widget->trans_z_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_trans_z(double)));

        connect(_side_widget->pc_spin_box, SIGNAL(valueChanged(int)), _gl_widget, SLOT(setParametricCurveIndex(int)));

//        connect(_side_widget->show_parametric_curves_radio_btn, SIGNAL(toggled(bool)), _gl_widget, SLOT(setVisibilityOfParametricCurves(bool)));

//        connect(_side_widget->show_cyclic_curves_radio_btn, SIGNAL(toggled(bool)), _gl_widget, SLOT(setVisibilityOfCyclicCurves(bool)));

//        connect(_side_widget->show_animated_model_radio_button, SIGNAL(toggled(bool)), _gl_widget, SLOT(setShowAnimatedModel(bool)));

        connect(_side_widget->shaderTypeSpinBox, SIGNAL(valueChanged(int)), _gl_widget, SLOT(setShaderType(int)));

        connect(_side_widget->materialSpinBox, SIGNAL(valueChanged(int)), _gl_widget, SLOT(setMaterialType(int)));

        connect(_side_widget->button_north, SIGNAL(clicked()), _gl_widget, SLOT(addHermitePatchNorth()));

        connect(_side_widget->button_north_east, SIGNAL(clicked()), _gl_widget, SLOT(addHermitePatchNorthEast()));

        connect(_side_widget->button_east, SIGNAL(clicked()), _gl_widget, SLOT(addHermitePatchEast()));

        connect(_side_widget->button_south_east, SIGNAL(clicked()), _gl_widget, SLOT(addHermitePatchSouthEast()));

        connect(_side_widget->button_south, SIGNAL(clicked()), _gl_widget, SLOT(addHermitePatchSouth()));

        connect(_side_widget->button_south_west, SIGNAL(clicked()), _gl_widget, SLOT(addHermitePatchSouthWest()));

        connect(_side_widget->button_west, SIGNAL(clicked()), _gl_widget, SLOT(addHermitePatchWest()));

        connect(_side_widget->button_north_west, SIGNAL(clicked()), _gl_widget, SLOT(addHermitePatchNorthWest()));

    }

    //--------------------------------
    // implementation of private slots
    //--------------------------------
    void MainWindow::on_action_Quit_triggered()
    {
        qApp->exit(0);
    }
}
