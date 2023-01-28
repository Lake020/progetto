#include "cafewidgetvisitor.h"

#include "model/food.h"
#include "model/drink.h"
#include<QVBoxLayout>
#include<QFrame>
#include<QLabel>
#include<QPixmap>
#include<QFormLayout>

void CafeWidgetVisitor::visit(Food& food){
    widget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;
    QVBoxLayout* imageLayout = new QVBoxLayout;
    QFrame* image = new QFrame;
    QLabel* img = new QLabel;
    QPixmap pic = QPixmap(QString::fromStdString(food.get_image()));
    img->setPixmap(pic.scaledToHeight(200));
    img->setContentsMargins(0,0,0,0);
    imageLayout->addWidget(img);
    image->setLayout(imageLayout);
    layout->addWidget(image);
    QFormLayout* formLayout = new QFormLayout;
    QLabel* name = new QLabel(QString::fromStdString(food.get_name()));
    formLayout->addRow("Name: ", name);
    QLabel* price = new QLabel(QString::number(food.get_price()));
    formLayout->addRow("Price: ", price);
    QLabel* gluten = new QLabel(food.is_gluten_free()? "Yes" : "No");
    formLayout->addRow("Gluten free: ", gluten);
    layout->addLayout(formLayout);
    widget->setLayout(layout);
}

void CafeWidgetVisitor::visit(Drink& drink){
    widget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout;
    QVBoxLayout* imageLayout = new QVBoxLayout;
    QFrame* image = new QFrame;
    QLabel* img = new QLabel;
    QPixmap pic = QPixmap(QString::fromStdString(drink.get_image()));
    img->setPixmap(pic.scaledToHeight(200));
    img->setContentsMargins(0,0,0,0);
    imageLayout->addWidget(img);
    image->setLayout(imageLayout);
    layout->addWidget(image);
    QFormLayout* formLayout = new QFormLayout;
    QLabel* name = new QLabel(QString::fromStdString(drink.get_name()));
    formLayout->addRow("Name: ", name);
    QLabel* price = new QLabel(QString::number(drink.get_price()));
    formLayout->addRow("Price: ", price);
    QLabel* format;
    switch(drink.get_format()){
    case small: format = new QLabel("Small"); break;
    case medium: format = new QLabel("Medium"); break;
    case big: format = new QLabel("Big"); break;
    }
    formLayout->addRow("Format: ", format);
    layout->addLayout(formLayout);
    widget->setLayout(layout);
}

QWidget* CafeWidgetVisitor::get_widget() const{
    return widget;
}
