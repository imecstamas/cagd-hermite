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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
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
    QSpinBox *shaderTypeSpinBox;
    QLabel *label_13;
    QSpinBox *materialSpinBox;
    QLabel *label_14;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QPushButton *button_north_west;
    QPushButton *button_north;
    QPushButton *button_north_east;
    QPushButton *button_west;
    QPushButton *button_east;
    QPushButton *button_south_west;
    QPushButton *button_south;
    QPushButton *button_south_east;
    QLabel *label_8;
    QLabel *label_9;
    QRadioButton *radioButton_arc;
    QRadioButton *radioButton_patch;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *arcLeftButton;
    QLabel *label_10;
    QPushButton *arcRightButton;
    QComboBox *comboBox;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_15;
    QDoubleSpinBox *spinBox_x;
    QDoubleSpinBox *spinBox_y;
    QDoubleSpinBox *spinBox_z;

    void setupUi(QWidget *SideWidget)
    {
        if (SideWidget->objectName().isEmpty())
            SideWidget->setObjectName(QStringLiteral("SideWidget"));
        SideWidget->resize(289, 693);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SideWidget->sizePolicy().hasHeightForWidth());
        SideWidget->setSizePolicy(sizePolicy);
        SideWidget->setMinimumSize(QSize(269, 0));
        groupBox = new QGroupBox(SideWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 271, 431));
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

        shaderTypeSpinBox = new QSpinBox(groupBox);
        shaderTypeSpinBox->setObjectName(QStringLiteral("shaderTypeSpinBox"));
        shaderTypeSpinBox->setGeometry(QRect(180, 280, 31, 22));
        shaderTypeSpinBox->setMaximum(3);
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(120, 280, 61, 20));
        materialSpinBox = new QSpinBox(groupBox);
        materialSpinBox->setObjectName(QStringLiteral("materialSpinBox"));
        materialSpinBox->setGeometry(QRect(70, 280, 31, 22));
        materialSpinBox->setMaximum(6);
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 280, 47, 21));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 310, 271, 121));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        button_north_west = new QPushButton(layoutWidget1);
        button_north_west->setObjectName(QStringLiteral("button_north_west"));

        gridLayout->addWidget(button_north_west, 0, 0, 1, 1);

        button_north = new QPushButton(layoutWidget1);
        button_north->setObjectName(QStringLiteral("button_north"));

        gridLayout->addWidget(button_north, 0, 1, 1, 1);

        button_north_east = new QPushButton(layoutWidget1);
        button_north_east->setObjectName(QStringLiteral("button_north_east"));

        gridLayout->addWidget(button_north_east, 0, 2, 1, 1);

        button_west = new QPushButton(layoutWidget1);
        button_west->setObjectName(QStringLiteral("button_west"));

        gridLayout->addWidget(button_west, 1, 0, 1, 1);

        button_east = new QPushButton(layoutWidget1);
        button_east->setObjectName(QStringLiteral("button_east"));

        gridLayout->addWidget(button_east, 1, 2, 1, 1);

        button_south_west = new QPushButton(layoutWidget1);
        button_south_west->setObjectName(QStringLiteral("button_south_west"));

        gridLayout->addWidget(button_south_west, 2, 0, 1, 1);

        button_south = new QPushButton(layoutWidget1);
        button_south->setObjectName(QStringLiteral("button_south"));

        gridLayout->addWidget(button_south, 2, 1, 1, 1);

        button_south_east = new QPushButton(layoutWidget1);
        button_south_east->setObjectName(QStringLiteral("button_south_east"));

        gridLayout->addWidget(button_south_east, 2, 2, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 250, 121, 16));
        radioButton_arc = new QRadioButton(SideWidget);
        radioButton_arc->setObjectName(QStringLiteral("radioButton_arc"));
        radioButton_arc->setGeometry(QRect(110, 440, 82, 17));
        radioButton_patch = new QRadioButton(SideWidget);
        radioButton_patch->setObjectName(QStringLiteral("radioButton_patch"));
        radioButton_patch->setGeometry(QRect(10, 440, 82, 17));
        radioButton_patch->setChecked(true);
        layoutWidget2 = new QWidget(SideWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 470, 271, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        arcLeftButton = new QPushButton(layoutWidget2);
        arcLeftButton->setObjectName(QStringLiteral("arcLeftButton"));

        horizontalLayout->addWidget(arcLeftButton);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_10);

        arcRightButton = new QPushButton(layoutWidget2);
        arcRightButton->setObjectName(QStringLiteral("arcRightButton"));

        horizontalLayout->addWidget(arcRightButton);

        comboBox = new QComboBox(SideWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(60, 530, 181, 22));
        label_11 = new QLabel(SideWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 560, 16, 16));
        label_12 = new QLabel(SideWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(110, 560, 16, 16));
        label_15 = new QLabel(SideWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(210, 560, 16, 16));
        spinBox_x = new QDoubleSpinBox(SideWidget);
        spinBox_x->setObjectName(QStringLiteral("spinBox_x"));
        spinBox_x->setGeometry(QRect(40, 560, 62, 22));
        spinBox_x->setMinimum(-99);
        spinBox_y = new QDoubleSpinBox(SideWidget);
        spinBox_y->setObjectName(QStringLiteral("spinBox_y"));
        spinBox_y->setGeometry(QRect(130, 560, 62, 22));
        spinBox_y->setMinimum(-99);
        spinBox_z = new QDoubleSpinBox(SideWidget);
        spinBox_z->setObjectName(QStringLiteral("spinBox_z"));
        spinBox_z->setGeometry(QRect(220, 560, 62, 22));
        spinBox_z->setMinimum(-99);
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
        label_13->setText(QApplication::translate("SideWidget", "ShaderType", Q_NULLPTR));
        label_14->setText(QApplication::translate("SideWidget", "Material", Q_NULLPTR));
        button_north_west->setText(QApplication::translate("SideWidget", "North-West", Q_NULLPTR));
        button_north->setText(QApplication::translate("SideWidget", "North", Q_NULLPTR));
        button_north_east->setText(QApplication::translate("SideWidget", "North-East", Q_NULLPTR));
        button_west->setText(QApplication::translate("SideWidget", "West", Q_NULLPTR));
        button_east->setText(QApplication::translate("SideWidget", "East", Q_NULLPTR));
        button_south_west->setText(QApplication::translate("SideWidget", "South-West", Q_NULLPTR));
        button_south->setText(QApplication::translate("SideWidget", "South", Q_NULLPTR));
        button_south_east->setText(QApplication::translate("SideWidget", "South-East", Q_NULLPTR));
        label_8->setText(QApplication::translate("SideWidget", "Add", Q_NULLPTR));
        label_9->setText(QApplication::translate("SideWidget", "Next patch attributes:", Q_NULLPTR));
        radioButton_arc->setText(QApplication::translate("SideWidget", "ShowArc", Q_NULLPTR));
        radioButton_patch->setText(QApplication::translate("SideWidget", "ShowPatch", Q_NULLPTR));
        arcLeftButton->setText(QApplication::translate("SideWidget", "Left", Q_NULLPTR));
        label_10->setText(QApplication::translate("SideWidget", "Add", Q_NULLPTR));
        arcRightButton->setText(QApplication::translate("SideWidget", "Right", Q_NULLPTR));
        label_11->setText(QApplication::translate("SideWidget", "X:", Q_NULLPTR));
        label_12->setText(QApplication::translate("SideWidget", "Y:", Q_NULLPTR));
        label_15->setText(QApplication::translate("SideWidget", "Z:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SideWidget: public Ui_SideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEWIDGET_H
