/********************************************************************************
** Form generated from reading UI file 'SideWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEWIDGET_H
#define UI_SIDEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SideWidget
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *rotate_x_slider;
    QLabel *label_2;
    QSlider *rotate_y_slider;
    QLabel *label_3;
    QSlider *rotate_z_slider;
    QLabel *label_4;
    QDoubleSpinBox *zoom_factor_spin_box;
    QLabel *label_5;
    QDoubleSpinBox *trans_x_spin_box;
    QLabel *label_6;
    QDoubleSpinBox *trans_y_spin_box;
    QLabel *label_7;
    QDoubleSpinBox *trans_z_spin_box;
    QRadioButton *show_animated_model_radio_button;
    QRadioButton *show_cyclic_curves_radio_btn;
    QRadioButton *show_parametric_curves_radio_btn;
    QSpinBox *pc_spin_box;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *shaderTypeSpinBox;
    QLabel *label_13;

    void setupUi(QWidget *SideWidget)
    {
        if (SideWidget->objectName().isEmpty())
            SideWidget->setObjectName(QStringLiteral("SideWidget"));
        SideWidget->resize(289, 606);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SideWidget->sizePolicy().hasHeightForWidth());
        SideWidget->setSizePolicy(sizePolicy);
        SideWidget->setMinimumSize(QSize(269, 0));
        groupBox = new QGroupBox(SideWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 271, 451));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(3, 21, 261, 184));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        rotate_x_slider = new QSlider(layoutWidget);
        rotate_x_slider->setObjectName(QStringLiteral("rotate_x_slider"));
        rotate_x_slider->setMinimum(-180);
        rotate_x_slider->setMaximum(180);
        rotate_x_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, rotate_x_slider);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        rotate_y_slider = new QSlider(layoutWidget);
        rotate_y_slider->setObjectName(QStringLiteral("rotate_y_slider"));
        rotate_y_slider->setMinimum(-180);
        rotate_y_slider->setMaximum(180);
        rotate_y_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, rotate_y_slider);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        rotate_z_slider = new QSlider(layoutWidget);
        rotate_z_slider->setObjectName(QStringLiteral("rotate_z_slider"));
        rotate_z_slider->setMinimum(-180);
        rotate_z_slider->setMaximum(180);
        rotate_z_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, rotate_z_slider);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        zoom_factor_spin_box = new QDoubleSpinBox(layoutWidget);
        zoom_factor_spin_box->setObjectName(QStringLiteral("zoom_factor_spin_box"));
        zoom_factor_spin_box->setDecimals(5);
        zoom_factor_spin_box->setMinimum(0.0001);
        zoom_factor_spin_box->setMaximum(10000);
        zoom_factor_spin_box->setSingleStep(0.1);
        zoom_factor_spin_box->setValue(1);

        formLayout->setWidget(3, QFormLayout::FieldRole, zoom_factor_spin_box);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        trans_x_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_x_spin_box->setObjectName(QStringLiteral("trans_x_spin_box"));
        trans_x_spin_box->setMinimum(-100);
        trans_x_spin_box->setMaximum(100);
        trans_x_spin_box->setSingleStep(0.1);

        formLayout->setWidget(4, QFormLayout::FieldRole, trans_x_spin_box);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        trans_y_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_y_spin_box->setObjectName(QStringLiteral("trans_y_spin_box"));
        trans_y_spin_box->setMinimum(-100);
        trans_y_spin_box->setMaximum(100);
        trans_y_spin_box->setSingleStep(0.1);

        formLayout->setWidget(5, QFormLayout::FieldRole, trans_y_spin_box);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        trans_z_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_z_spin_box->setObjectName(QStringLiteral("trans_z_spin_box"));
        trans_z_spin_box->setMinimum(-100);
        trans_z_spin_box->setMaximum(100);
        trans_z_spin_box->setSingleStep(0.1);

        formLayout->setWidget(6, QFormLayout::FieldRole, trans_z_spin_box);

        show_animated_model_radio_button = new QRadioButton(groupBox);
        show_animated_model_radio_button->setObjectName(QStringLiteral("show_animated_model_radio_button"));
        show_animated_model_radio_button->setGeometry(QRect(10, 420, 251, 20));
        show_cyclic_curves_radio_btn = new QRadioButton(groupBox);
        show_cyclic_curves_radio_btn->setObjectName(QStringLiteral("show_cyclic_curves_radio_btn"));
        show_cyclic_curves_radio_btn->setGeometry(QRect(10, 380, 251, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(show_cyclic_curves_radio_btn->sizePolicy().hasHeightForWidth());
        show_cyclic_curves_radio_btn->setSizePolicy(sizePolicy1);
        show_parametric_curves_radio_btn = new QRadioButton(groupBox);
        show_parametric_curves_radio_btn->setObjectName(QStringLiteral("show_parametric_curves_radio_btn"));
        show_parametric_curves_radio_btn->setEnabled(true);
        show_parametric_curves_radio_btn->setGeometry(QRect(10, 340, 251, 20));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(show_parametric_curves_radio_btn->sizePolicy().hasHeightForWidth());
        show_parametric_curves_radio_btn->setSizePolicy(sizePolicy2);
        show_parametric_curves_radio_btn->setChecked(true);
        pc_spin_box = new QSpinBox(groupBox);
        pc_spin_box->setObjectName(QStringLiteral("pc_spin_box"));
        pc_spin_box->setGeometry(QRect(40, 280, 191, 22));
        pc_spin_box->setMaximum(4);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 220, 47, 13));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 250, 47, 13));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(90, 220, 47, 13));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(160, 220, 47, 13));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(100, 250, 91, 16));
        shaderTypeSpinBox = new QSpinBox(groupBox);
        shaderTypeSpinBox->setObjectName(QStringLiteral("shaderTypeSpinBox"));
        shaderTypeSpinBox->setGeometry(QRect(230, 420, 31, 22));
        shaderTypeSpinBox->setMaximum(3);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(156, 420, 61, 20));
#ifndef QT_NO_SHORTCUT
        label->setBuddy(rotate_x_slider);
        label_2->setBuddy(rotate_y_slider);
        label_3->setBuddy(rotate_z_slider);
        label_4->setBuddy(zoom_factor_spin_box);
        label_5->setBuddy(trans_x_spin_box);
        label_6->setBuddy(trans_y_spin_box);
        label_7->setBuddy(trans_z_spin_box);
#endif // QT_NO_SHORTCUT

        retranslateUi(SideWidget);

        QMetaObject::connectSlotsByName(SideWidget);
    } // setupUi

    void retranslateUi(QWidget *SideWidget)
    {
        SideWidget->setWindowTitle(QApplication::translate("SideWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("SideWidget", "Transformations", Q_NULLPTR));
        label->setText(QApplication::translate("SideWidget", "Rotate around x", Q_NULLPTR));
        label_2->setText(QApplication::translate("SideWidget", "Rotate around y", Q_NULLPTR));
        label_3->setText(QApplication::translate("SideWidget", "Rotate around z", Q_NULLPTR));
        label_4->setText(QApplication::translate("SideWidget", "Zoom factor", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        zoom_factor_spin_box->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("SideWidget", "Translate along x", Q_NULLPTR));
        label_6->setText(QApplication::translate("SideWidget", "Translate along y", Q_NULLPTR));
        label_7->setText(QApplication::translate("SideWidget", "Translate along z", Q_NULLPTR));
        show_animated_model_radio_button->setText(QApplication::translate("SideWidget", "Show animated model", Q_NULLPTR));
        show_cyclic_curves_radio_btn->setText(QApplication::translate("SideWidget", "Show cyclic curves", Q_NULLPTR));
        show_parametric_curves_radio_btn->setText(QApplication::translate("SideWidget", "Show parametric curves", Q_NULLPTR));
        label_8->setText(QApplication::translate("SideWidget", "0. torus", Q_NULLPTR));
        label_9->setText(QApplication::translate("SideWidget", "3. cyclo", Q_NULLPTR));
        label_10->setText(QApplication::translate("SideWidget", "1. lissajou", Q_NULLPTR));
        label_11->setText(QApplication::translate("SideWidget", "2. hypo", Q_NULLPTR));
        label_12->setText(QApplication::translate("SideWidget", "4. spiral_on_cone", Q_NULLPTR));
        label_13->setText(QApplication::translate("SideWidget", "shaderType", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SideWidget: public Ui_SideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEWIDGET_H
