#include "cafeeditvisitor.h"



void CafeEditVisitor::visit(Food& food){
    widget = new QWidget;
    init_widget();
    type->setCurrentIndex(0);
    name->setText(QString::fromStdString(food.get_name()));
    image->setText(QString::fromStdString(food.get_image()));
    price->setValue(food.get_price());
    extra->addItem("Yes");
    extra->addItem("No");
    extra->setCurrentIndex(food.is_gluten_free()? 0 : 1);
    formLayout->addRow("Gluten Free: ", extra);
    layout->addLayout(formLayout);
    layout->addLayout(buttonLayout);
    widget->setLayout(layout);
}

void CafeEditVisitor::visit(Drink& drink){
    widget = new QWidget;
    init_widget();
    type->setCurrentIndex(1);
    name->setText(QString::fromStdString(drink.get_name()));
    image->setText(QString::fromStdString(drink.get_image()));
    price->setValue(drink.get_price());
    extra->addItem("Small");
    extra->addItem("Medium");
    extra->addItem("Big");
    if(drink.get_format() == small) extra->setCurrentIndex(0);
    else if(drink.get_format() == medium) extra->setCurrentIndex(1);
    else extra->setCurrentIndex(2);
    formLayout->addRow("Format : ", extra);
    layout->addLayout(formLayout);
    layout->addLayout(buttonLayout);
    widget->setLayout(layout);
}

QWidget* CafeEditVisitor::get_widget() const{
    return widget;
}

void CafeEditVisitor::init_widget(){
    widget->setWindowTitle("Edit");
    widget->setFixedSize(QSize(400,240));
    layout = new QVBoxLayout;
    formLayout = new QFormLayout;
    type = new QComboBox;
    type->addItem("Food");
    type->addItem("Drink");
    formLayout->addRow("Type: ", type);
    name = new QLineEdit;
    name->setMaxLength(100);
    formLayout->addRow("Name: ", name);
    browseImage = new QPushButton("Browse...");
    imageLayout = new QHBoxLayout;
    image = new QLineEdit;
    image->setMaxLength(250);
    imageLayout->addWidget(image);
    imageLayout->addWidget(browseImage);
    formLayout->addRow("Image: ", imageLayout);
    price = new QDoubleSpinBox;
    price->setAlignment(Qt::AlignRight);
    price->setMaximum(100);
    price->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    formLayout->addRow("Price: ", price);
    extra = new QComboBox;
    buttonLayout = new QHBoxLayout;
    addButton = new QPushButton("Edit");
    cancelButton = new QPushButton("Cancel");
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(cancelButton);


}

