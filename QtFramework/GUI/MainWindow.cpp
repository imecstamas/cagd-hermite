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

        connect(_side_widget->radioButton_patch, SIGNAL(clicked()),this, SLOT(showPatchRelatedInfo()));

        connect(_side_widget->radioButton_arc, SIGNAL(clicked()),this, SLOT(showArcRelatedInfo()));

        connect(_side_widget->patch_add_button, SIGNAL(clicked()),_gl_widget, SLOT(addToPatch()));

        connect(_side_widget->patch_remove_button, SIGNAL(clicked()),_gl_widget, SLOT(removeFromPatch()));

        connect(_side_widget->arc_add_button, SIGNAL(clicked()),_gl_widget, SLOT(addToArc()));

        connect(_side_widget->arc_remove_button, SIGNAL(clicked()),_gl_widget, SLOT(removeFromArc()));

        connect(_side_widget->arcLeftButton, SIGNAL(clicked()), _gl_widget, SLOT(addHermiteArcLeft()));

        connect(_side_widget->arcRightButton, SIGNAL(clicked()), _gl_widget, SLOT(addHermiteArcRight()));

        connect(_side_widget->spinBox_x, SIGNAL(valueChanged(double)),_gl_widget, SLOT(setX(double)));

        connect(_side_widget->spinBox_y, SIGNAL(valueChanged(double)),_gl_widget, SLOT(setY(double)));

        connect(_side_widget->spinBox_z, SIGNAL(valueChanged(double)),_gl_widget, SLOT(setZ(double)));

        connect(_side_widget->comboBox, SIGNAL(currentIndexChanged(int)),_gl_widget, SLOT(setWhatToModify(int)));

        connect(_gl_widget, SIGNAL(xChanged(double)), _side_widget->spinBox_x, SLOT(setValue(double)));

        connect(_gl_widget, SIGNAL(yChanged(double)), _side_widget->spinBox_y, SLOT(setValue(double)));

        connect(_gl_widget, SIGNAL(zChanged(double)), _side_widget->spinBox_z, SLOT(setValue(double)));

        }

    //--------------------------------
    // implementation of private slots
    //--------------------------------
    void MainWindow::on_action_Quit_triggered()
    {
        qApp->exit(0);
    }

    void MainWindow::blockSpinBoxSignals(bool block)
    {
        _side_widget->spinBox_x->blockSignals(block);
        _side_widget->spinBox_y->blockSignals(block);
        _side_widget->spinBox_z->blockSignals(block);
        _side_widget->comboBox->blockSignals(block);
    }

    void MainWindow::showPatchRelatedInfo()
    {
        blockSpinBoxSignals(true);
        _gl_widget->showPatch();
        _side_widget->updateComboItems(false);
        blockSpinBoxSignals(false);
    }

    void MainWindow::showArcRelatedInfo()
    {
        blockSpinBoxSignals(true);
        _gl_widget->showArc();
        _side_widget->updateComboItems(true);
        blockSpinBoxSignals(false);
    }
}
