#include "entwidgetvisitor.h"
#include "manga.h"
#include "dvd.h"
#include "series.h"
#include "videogame.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QFrame>
#include<QLabel>
#include<QPixmap>
#include<QFormLayout>

void EntWidgetVisitor::visit(Manga& manga){
    widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
    QVBoxLayout* imageLayout = new QVBoxLayout;
    QFrame* image = new QFrame;
    QLabel* img = new QLabel;
    QPixmap pic = QPixmap(QString::fromStdString(manga.get_image()));
    img->setPixmap(pic.scaledToHeight(200));
    img->setContentsMargins(0,0,0,0);
    imageLayout->addWidget(img);
    image->setLayout(imageLayout);
    layout->addWidget(image);
    QFormLayout* formLayout = new QFormLayout;
    QLabel* name = new QLabel(QString::fromStdString(manga.get_name()));
    formLayout->addRow("Name: ", name);
    QLabel* description = new QLabel(QString::fromStdString(manga.get_description()));
    formLayout->addRow("Description: ", description);
    QLabel* quantity = new QLabel(QString::number(manga.get_quantity()));
    formLayout->addRow("Quantity: ", quantity);
    QLabel* author = new QLabel(QString::fromStdString(manga.get_author()));
    formLayout->addRow("Author: ", author);
    QLabel* volume = new QLabel(QString::number(manga.get_volume()));
    formLayout->addRow("Quantity: ", volume);
    QLabel* pages = new QLabel(QString::number(manga.get_pages()));
    formLayout->addRow("Pages: ", pages);
    QLabel* target;
    switch(manga.get_target()){
    case shounen: target = new QLabel("Shounen"); break;
    case seinen: target = new QLabel("Seinen"); break;
    case shojo: target = new QLabel("Shojo"); break;
    case josei: target = new QLabel("Josei"); break;
    case none: target = new QLabel("None"); break;
    }
    formLayout->addRow("Target: ", target);
    layout->addLayout(formLayout);
    widget->setLayout(layout);

}

void EntWidgetVisitor::visit(Dvd& dvd){
    widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
    QVBoxLayout* imageLayout = new QVBoxLayout;
    QFrame* image = new QFrame;
    QLabel* img = new QLabel;
    QPixmap pic = QPixmap(QString::fromStdString(dvd.get_image()));
    img->setPixmap(pic.scaledToHeight(200));
    img->setContentsMargins(0,0,0,0);
    imageLayout->addWidget(img);
    image->setLayout(imageLayout);
    layout->addWidget(image);
    QFormLayout* formLayout = new QFormLayout;
    QLabel* name = new QLabel(QString::fromStdString(dvd.get_name()));
    formLayout->addRow("Name: ", name);
    QLabel* description = new QLabel(QString::fromStdString(dvd.get_description()));
    formLayout->addRow("Description: ", description);
    QLabel* quantity = new QLabel(QString::number(dvd.get_quantity()));
    formLayout->addRow("Quantity: ", quantity);
    QLabel* production = new QLabel(QString::fromStdString(dvd.get_production()));
    formLayout->addRow("Production: ", production);
    QLabel* length = new QLabel(QString::number(dvd.get_length()));
    formLayout->addRow("Length: ", length);
    layout->addLayout(formLayout);
    widget->setLayout(layout);
}

void EntWidgetVisitor::visit(Series& series){
    widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
    QVBoxLayout* imageLayout = new QVBoxLayout;
    QFrame* image = new QFrame;
    QLabel* img = new QLabel;
    QPixmap pic = QPixmap(QString::fromStdString(series.get_image()));
    img->setPixmap(pic.scaledToHeight(200));
    img->setContentsMargins(0,0,0,0);
    imageLayout->addWidget(img);
    image->setLayout(imageLayout);
    layout->addWidget(image);
    QFormLayout* formLayout = new QFormLayout;
    QLabel* name = new QLabel(QString::fromStdString(series.get_name()));
    formLayout->addRow("Name: ", name);
    QLabel* description = new QLabel(QString::fromStdString(series.get_description()));
    formLayout->addRow("Description: ", description);
    QLabel* quantity = new QLabel(QString::number(series.get_quantity()));
    formLayout->addRow("Quantity: ", quantity);
    QLabel* production = new QLabel(QString::fromStdString(series.get_production()));
    formLayout->addRow("Production: ", production);
    QLabel* length = new QLabel(QString::number(series.get_length()));
    formLayout->addRow("Length: ", length);
    QLabel* episodes = new QLabel(QString::number(series.get_episodes()));
    formLayout->addRow("Episodes: ", episodes);
    layout->addLayout(formLayout);
    widget->setLayout(layout);
}

void EntWidgetVisitor::visit(Videogame& game){
    widget = new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
    QVBoxLayout* imageLayout = new QVBoxLayout;
    QFrame* image = new QFrame;
    QLabel* img = new QLabel;
    QPixmap pic = QPixmap(QString::fromStdString(game.get_image()));
    img->setPixmap(pic.scaledToHeight(200));
    img->setContentsMargins(0,0,0,0);
    imageLayout->addWidget(img);
    image->setLayout(imageLayout);
    layout->addWidget(image);
    QFormLayout* formLayout = new QFormLayout;
    QLabel* name = new QLabel(QString::fromStdString(game.get_name()));
    formLayout->addRow("Name: ", name);
    QLabel* description = new QLabel(QString::fromStdString(game.get_description()));
    formLayout->addRow("Description: ", description);
    QLabel* quantity = new QLabel(QString::number(game.get_quantity()));
    formLayout->addRow("Quantity: ", quantity);
    QLabel* company = new QLabel(QString::fromStdString(game.get_company()));
    formLayout->addRow("Company: ", company);
    QLabel* pegi = new QLabel(QString::number(game.get_pegi()));
    formLayout->addRow("Pegi: ", pegi);
    layout->addLayout(formLayout);
    widget->setLayout(layout);

}

QWidget* EntWidgetVisitor::get_widget() const{
    return widget;
}

