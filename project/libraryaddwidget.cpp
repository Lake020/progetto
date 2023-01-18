#include "libraryaddwidget.h"

LibraryAddWidget::LibraryAddWidget(QWidget *parent): QWidget{parent}{
    setWindowTitle("Add");
    layout = new QVBoxLayout;
    formLayout = new QFormLayout;
    type = new QComboBox;
    type->addItem("Manga");
    type->addItem("Dvd");
    type->addItem("Series");
    type->addItem("Videogame");
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
    quantity = new QSpinBox;
    quantity->setAlignment(Qt::AlignRight);
    quantity->setMaximum(50);
    formLayout->addRow(tr("Price: "), quantity);
    description = new QTextEdit;
    formLayout->addRow(tr("Desription"), description);
    author = new QLineEdit;
    author->setMaxLength(100);
    volume = new QSpinBox;
    volume->setMaximum(200);
    pages = new QSpinBox;
    pages->setMaximum(1000);
    target = new QComboBox;
    target->addItem("Shounen");
    target->addItem("Seinen");
    target->addItem("Shojo");
    target->addItem("Josei");
    target->addItem("None");
    production = new QLineEdit;
    production->setMaxLength(100);
    length = new QSpinBox;
    length->setMaximum(210);
    episodes = new QSpinBox;
    episodes->setMaximum(2000);
    company = new QLineEdit;
    company->setMaxLength(100);
    pegi = new QSpinBox;
    pegi->setRange(3, 18);
    mangaExtraInfo();
    buttonLayout = new QHBoxLayout;
    addButton = new QPushButton("Add");
    cancelButton = new QPushButton("Cancel");
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(formLayout);
    layout->addLayout(buttonLayout);
    setLayout(layout);

    connect(type, &QComboBox::currentTextChanged, this, &LibraryAddWidget::extra_info);
    connect(browseImage, &QPushButton::clicked, this, &LibraryAddWidget::browse_image);
    connect(addButton, &QPushButton::clicked, this, &LibraryAddWidget::add_item);
    connect(cancelButton, &QPushButton::clicked, this, &LibraryAddWidget::hide);
}

void LibraryAddWidget::mangaExtraInfo(){
    while(formLayout->rowCount() > 4) formLayout->removeRow(formLayout->rowCount() - 1);
    formLayout->addRow(tr("&Author: "), author);
    formLayout->addRow(tr("Volume: "), volume);
    formLayout->addRow(tr("Pages: "), pages);
    formLayout->addRow(tr("Target: "), target);
}

void LibraryAddWidget::dvdExtraInfo(){
    while(formLayout->rowCount() > 4) formLayout->removeRow(formLayout->rowCount() - 1);
    formLayout->addRow(tr("&Production: "), production);
    formLayout->addRow(tr("Length: "), length);
}

void LibraryAddWidget::seriesExtraInfo(){
    dvdExtraInfo();
    formLayout->addRow(tr("Episodes"), episodes);
}

void LibraryAddWidget::videogameExtraInfo(){
    while(formLayout->rowCount() > 4) formLayout->removeRow(formLayout->rowCount() - 1);
    formLayout->addRow(tr("&Company: "), company);
    formLayout->addRow(tr("Pegi: "), pegi);
}

void LibraryAddWidget::extra_info(){
    switch(type->currentIndex()){
    case 0: mangaExtraInfo(); break;
    case 1: dvdExtraInfo(); break;
    case 2: seriesExtraInfo(); break;
    case 3: videogameExtraInfo(); break;
    }
}

void LibraryAddWidget::browse_image(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
    image->setText(fileName);
}

void LibraryAddWidget::add_item(){
    std::string itemName = name->text().toStdString();
    std::string itemImage = image->text().toStdString();
    std::string itemDescription = description->toPlainText().toStdString();
    double itemQuantity = quantity->value();
    if(type->currentIndex() == 0){
        std::string itemAuthor = author->text().toStdString();
        unsigned int itemVolume = volume->value();
        unsigned int itemPages = pages->value();
        Target itemTarget;
        switch(target->currentIndex()){
        case shounen: itemTarget = shounen; break;
        case seinen: itemTarget = seinen; break;
        case shojo: itemTarget = shojo; break;
        case josei: itemTarget = josei; break;
        case none: itemTarget = none; break;
        }
        Manga* manga = new Manga(itemName, itemImage, itemDescription, itemQuantity, itemAuthor, itemPages, itemVolume, itemTarget);
        this->hide();
        emit add_to_library(manga);
    }
    else if(type->currentIndex() == 1){
        std::string itemProduction = production->text().toStdString();
        unsigned int itemLength = length->value();
        Dvd* dvd = new Dvd(itemName, itemImage, itemDescription, itemQuantity, itemProduction, itemLength);
        this->hide();
        emit add_to_library(dvd);
    }else if(type->currentIndex() == 2){
        std::string itemProduction = production->text().toStdString();
        unsigned int itemLength = length->value();
        unsigned int itemEpisodes = episodes->value();
        Series* serie = new Series(itemName, itemImage, itemDescription, itemQuantity, itemProduction, itemLength, itemEpisodes);
        this->hide();
        emit add_to_library(serie);
    }else{
        std::string itemCompany = company->text().toStdString();
        unsigned int itemPegi = pegi->value();
        Videogame* game = new Videogame(itemName, itemImage, itemDescription, itemQuantity, itemCompany, itemPegi);
        this->hide();
        emit add_to_library(game);;
    }
}
