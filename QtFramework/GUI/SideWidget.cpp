#include "SideWidget.h"
#include <iostream>

using namespace std;

namespace cagd
{
    SideWidget::SideWidget(QWidget *parent): QWidget(parent)
    {
        setupUi(this);

        QPalette p = rotate_x_slider->palette();

        p.setColor(QPalette::Highlight, QColor(255,50,10).lighter());

        rotate_x_slider->setPalette(p);

        p = rotate_y_slider->palette();

        p.setColor(QPalette::Highlight, QColor(50,255,10).lighter());

        rotate_y_slider->setPalette(p);

        comboBox->addItem("Corner");
        comboBox->addItem("VTangent");
        comboBox->addItem("UTangent");
        comboBox->addItem("TwistVector");

        connect(radioButton_arc, SIGNAL(toggled(bool)), this, SLOT(updateComboItems(bool)));
    }

    void SideWidget::updateComboItems(bool arcsShown){
        comboBox->clear();
        if (arcsShown)
        {
            comboBox->addItem("Corner");
            comboBox->addItem("Tangent");
        }else{
            comboBox->addItem("Corner");
            comboBox->addItem("VTangent");
            comboBox->addItem("UTangent");
            comboBox->addItem("TwistVector");
        }
    }
}
