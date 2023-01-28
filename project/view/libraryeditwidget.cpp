#include "libraryeditwidget.h"

LibraryEditWidget::LibraryEditWidget(Entertainment* item, QWidget *parent): QWidget{parent}, item_{item}{
    setWindowTitle("Edit");
    //setFixedSize(QSize(400,240));
    layout = new QVBoxLayout;
    formLayout = new QFormLayout;
    if(dynamic_cast<Manga*>(item_)) type = new QLabel("Manga");
    else if(dynamic_cast<Series*>(item_)) type = new QLabel("Series");
    else if(dynamic_cast<Dvd*>(item_)) type = new QLabel("Dvd");
    else if(dynamic_cast<Videogame*>(item_)) type = new QLabel("Videogame");
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
    description = new QTextEdit;
    description->setText(QString::fromStdString(item_->get_description()));
    formLayout->addRow(tr("Desription: "), description);
    quantity = new QSpinBox;
    quantity->setAlignment(Qt::AlignRight);
    quantity->setMaximum(50);
    quantity->setValue(item_->get_quantity());
    formLayout->addRow(tr("Quantity: "), quantity);
    if(type->text() == "Manga") mangaExtraInfo();
    else if(type->text() == "Dvd") dvdExtraInfo();
    else if(type->text() == "Series") seriesExtraInfo();
    else if(type->text() == "Videogame") videogameExtraInfo();
    buttonLayout = new QHBoxLayout;
    editButton = new QPushButton("Edit");
    cancelButton = new QPushButton("Cancel");
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(formLayout);
    layout->addLayout(buttonLayout);
    setLayout(layout);

    connect(browseImage, &QPushButton::clicked, this, &LibraryEditWidget::browse_image);
    connect(editButton, &QPushButton::clicked, this, &LibraryEditWidget::edit_item);
    connect(cancelButton, &QPushButton::clicked, this, &LibraryEditWidget::hide);

}

void LibraryEditWidget::mangaExtraInfo(){
    Manga* manga = static_cast<Manga*>(item_);
    author = new QLineEdit;
    author->setMaxLength(100);
    author->setText(QString::fromStdString(manga->get_author()));
    formLayout->addRow(tr("&Author: "), author);
    volume = new QSpinBox;
    volume->setMaximum(200);
    volume->setValue(manga->get_volume());
    formLayout->addRow(tr("Volume: "), volume);
    pages = new QSpinBox;
    pages->setMaximum(1000);
    pages->setValue(manga->get_pages());
    formLayout->addRow(tr("Pages: "), pages);
    target = new QComboBox;
    target->addItem("Shounen");
    target->addItem("Seinen");
    target->addItem("Shojo");
    target->addItem("Josei");
    target->addItem("None");
    switch(manga->get_target()){
    case shounen: target->setCurrentIndex(0); break;
    case seinen: target->setCurrentIndex(1); break;
    case shojo: target->setCurrentIndex(2); break;
    case josei: target->setCurrentIndex(3); break;
    case none: target->setCurrentIndex(4); break;
    }
    formLayout->addRow(tr("Target: "), target);
}

void LibraryEditWidget::dvdExtraInfo(){
    Dvd* dvd = static_cast<Dvd*>(item_);
    production = new QLineEdit;
    production->setMaxLength(100);
    production->setText(QString::fromStdString(dvd->get_production()));
    formLayout->addRow(tr("&Production: "), production);
    length = new QSpinBox;
    length->setMaximum(210);
    length->setValue(dvd->get_length());
    formLayout->addRow(tr("Length: "), length);
}

void LibraryEditWidget::seriesExtraInfo(){
    dvdExtraInfo();
    Series* serie = static_cast<Series*>(item_);
    episodes = new QSpinBox;
    episodes->setMaximum(2000);
    episodes->setValue(serie->get_episodes());
    formLayout->addRow(tr("Episodes"), episodes);
}

void LibraryEditWidget::videogameExtraInfo(){
    Videogame* game = static_cast<Videogame*>(item_);
    company = new QLineEdit;
    company->setMaxLength(100);
    company->setText(QString::fromStdString(game->get_company()));
    formLayout->addRow(tr("&Company: "), company);
    pegi = new QSpinBox;
    pegi->setRange(3, 18);
    pegi->setValue(game->get_pegi());
    formLayout->addRow(tr("Pegi: "), pegi);
}

void LibraryEditWidget::edit_item(){
    item_->set_name(name->text().toStdString());
    item_->set_image(image->text().toStdString());
    item_->set_description(description->toPlainText().toStdString());
    item_->set_quantity(quantity->value());
    if(Manga* manga = dynamic_cast<Manga*>(item_)){
        manga->set_author(author->text().toStdString());
        manga->set_pages(pages->value());
        manga->set_volume(volume->value());
        switch(target->currentIndex()){
        case shounen: manga->set_target(shounen); break;
        case seinen: manga->set_target(seinen); break;
        case shojo: manga->set_target(shojo); break;
        case josei: manga->set_target(josei); break;
        case none: manga->set_target(none); break;
        }
    }else if(Series* series = dynamic_cast<Series*>(item_)){
        series->set_producrion(production->text().toStdString());
        series->set_length(length->value());
        series->set_episodes(episodes->value());
    }else if(Dvd* dvd = dynamic_cast<Dvd*>(item_)){
        dvd->set_producrion(production->text().toStdString());
        dvd->set_length(length->value());
    }else if(Videogame* game = dynamic_cast<Videogame*>(item_)){
        game->set_company(company->text().toStdString());
        game->set_pegi(pegi->value());
    }
    emit edited();
    this->hide();

}

void LibraryEditWidget::browse_image(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));
    image->setText(fileName);
}
