#include "cafeitemeditwidget.h"

CafeItemEditWidget::CafeItemEditWidget(CafeItem* item, QWidget *parent):QWidget{parent}, item_{item}{
    setWindowTitle("Edit");
    setFixedSize(QSize(400,240));
    layout = new QVBoxLayout;
    formLayout = new QFormLayout;
    if(dynamic_cast<Food*>(item_)) type = new QLabel("Food");
    else if(dynamic_cast<Drink*>(item_)) type = new QLabel("Drink");
    formLayout->addRow(tr("Type: "), type);
    name = new QLineEdit(QString::fromStdString(item_->get_name()));
    name->setMaxLength(100);
    formLayout->addRow(tr("&Name: "), name);
    browseImage = new QPushButton("Browse...");
    imageLayout = new QHBoxLayout;
    image = new QLineEdit(QString::fromStdString(item_->get_image()));
    image->setMaxLength(250);
    imageLayout->addWidget(image);
    imageLayout->addWidget(browseImage);
    formLayout->addRow(tr("Image: "), imageLayout);
    price = new QDoubleSpinBox;
    price->setAlignment(Qt::AlignRight);
    price->setMaximum(100);
    price->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
    price->setValue(item_->get_price());
    formLayout->addRow(tr("Price: "), price);
    extra = new QComboBox;
    if(type->text() == "Food"){
        extra->addItem("Yes");
        extra->addItem("No");
        extra->setCurrentIndex(static_cast<Food*>(item_)->is_gluten_free()? 0: 1);
        formLayout->addRow(tr("Gluten Free: "), extra);
    }else if(type->text() == "Drink"){
        extra->addItem("Small");
        extra->addItem("Medium");
        extra->addItem("Big");
        switch(static_cast<Drink*>(item_)->get_format()){
        case small: extra->setCurrentIndex(0); break;
        case medium: extra->setCurrentIndex(1); break;
        case big: extra->setCurrentIndex(2); break;
        }
        formLayout->addRow(tr("Format : "), extra);
    }
    buttonLayout = new QHBoxLayout;
    editButton = new QPushButton("Edit");
    cancelButton = new QPushButton("Cancel");
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(formLayout);
    layout->addLayout(buttonLayout);
    setLayout(layout);
    connect(browseImage, &QPushButton::clicked, this, &CafeItemEditWidget::browse_image);
    connect(editButton, &QPushButton::clicked, this, &CafeItemEditWidget::edit_item);
    connect(cancelButton, &QPushButton::clicked, this, &CafeItemEditWidget::hide);
}

void CafeItemEditWidget::edit_item(){
    item_->set_name(name->text().toStdString());
    item_->set_image(image->text().toStdString());
    item_->set_price(price->value());
    if(dynamic_cast<Food*>(item_)){
        static_cast<Food*>(item_)->set_gluten_free(extra->currentText() == "Yes" ? true : false);
    }else if(dynamic_cast<Drink*>(item_)){
        enum size itemFormat;
        switch(extra->currentIndex()){
        case 0: itemFormat = small; break;
        case 1: itemFormat = medium; break;
        case 2: itemFormat = big; break;
        }
        static_cast<Drink*>(item_)->set_format(itemFormat);
    }
    emit edited();
    this->hide();

}

void CafeItemEditWidget::browse_image(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
    QDir dir = QCoreApplication::applicationDirPath();
    fileName = dir.relativeFilePath(fileName);
    image->setText(fileName);
}
