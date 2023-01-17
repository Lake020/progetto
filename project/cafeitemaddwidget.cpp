#include "cafeitemaddwidget.h"

CafeItemAddWidget::CafeItemAddWidget(QWidget *parent): QWidget{parent}{
    setWindowTitle("Add");
    setFixedSize(QSize(400,240));
    layout = new QVBoxLayout;
    formLayout = new QFormLayout;
    type = new QComboBox;
    type->addItem("Food");
    type->addItem("Drink");
    formLayout->addRow(tr("Type: "), type);
    name = new QLineEdit;
    name->setMaxLength(100);
    formLayout->addRow(tr("&Name: "), name);
    browseImage = new QPushButton("Browse...");
    imageLayout = new QHBoxLayout;
    image = new QLineEdit;
    image->setMaxLength(250);
    imageLayout->addWidget(image);
    imageLayout->addWidget(browseImage);
    formLayout->addRow(tr("Image: "), imageLayout);
    price = new QDoubleSpinBox;
    price->setAlignment(Qt::AlignRight);
    price->setMaximum(100);
    price->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    formLayout->addRow(tr("Price: "), price);
    FoodExtraInfo();
    buttonLayout = new QHBoxLayout;
    addButton = new QPushButton("Add");
    cancelButton = new QPushButton("Cancel");
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(formLayout);
    layout->addLayout(buttonLayout);
    setLayout(layout);
    connect(type, &QComboBox::currentTextChanged, this, &CafeItemAddWidget::extra_info);
    connect(browseImage, &QPushButton::clicked, this, &CafeItemAddWidget::browse_image);
    connect(addButton, &QPushButton::clicked, this, &CafeItemAddWidget::add_item);
    connect(cancelButton, &QPushButton::clicked, [=]() {
        // pulisco il form
        type->setCurrentIndex(0);
        name->clear();
        image->clear();
        price->setValue(0);
        extra->setCurrentIndex(0);
        this->hide();
    });
}

void CafeItemAddWidget::FoodExtraInfo(){
    extra = new QComboBox;
    extra->addItem("Yes");
    extra->addItem("No");
    if(formLayout->rowCount() > 4) formLayout->removeRow(4);
    formLayout->addRow(tr("Gluten Free: "), extra);
}

void CafeItemAddWidget::DrinkExtraInfo(){
    extra = new QComboBox;
    extra->addItem("Small");
    extra->addItem("Medium");
    extra->addItem("Big");
    if(formLayout->rowCount() > 4) formLayout->removeRow(4);
    formLayout->addRow(tr("Format : "), extra);
}

void CafeItemAddWidget::extra_info(){
    if(type->currentIndex() == 0) FoodExtraInfo();
    else DrinkExtraInfo();
}

void CafeItemAddWidget::browse_image(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
    image->setText(fileName);
}

void CafeItemAddWidget::add_item(){
    std::string nameItem = name->text().toStdString();
    std::string imageItem = image->text().toStdString();
    double priceItem = price->value();
    if(type->currentIndex() == 0){
        bool glutenItem = extra->currentText() == "Yes" ? true : false;
        Food* food = new Food(nameItem, imageItem, priceItem, glutenItem);
        type->setCurrentIndex(0);
        name->clear();
        image->clear();
        price->setValue(0);
        extra->setCurrentIndex(0);
        this->hide();
        emit add_to_menu(food);
    }
    else{
        enum size formatItem;
        switch(extra->currentIndex()){
        case 0: formatItem = small; break;
        case 1: formatItem = medium; break;
        case 2: formatItem = big; break;
        default: formatItem = medium; break;
        }
        Drink* drink = new Drink(nameItem, imageItem, priceItem, formatItem);
        type->setCurrentIndex(0);
        name->clear();
        image->clear();
        price->setValue(0);
        extra->setCurrentIndex(0);
        this->hide();
        emit add_to_menu(drink);
    }
}

void CafeItemAddWidget::closeEvent (QCloseEvent *event){
    type->setCurrentIndex(0);
    name->clear();
    image->clear();
    price->setValue(0);
    extra->setCurrentIndex(0);
}
