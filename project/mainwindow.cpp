#include "mainwindow.h"
#include "cafeinfovisitor.h"
#include "entinfovisitor.h"

MainWindow::MainWindow(const Menu& menu, const Library& library, QWidget *parent):QWidget(parent), menu_(menu), library_(library), search_mode_(0), addWidget(new CafeItemAddWidget){
    setWindowTitle("QtCafe");

    QVBoxLayout* mainLayout = new QVBoxLayout;

    QMenuBar* menuBar = new QMenuBar;
    QMenu* file = new QMenu("File");
    QMenu* help = new QMenu("?");
    menuBar->addMenu(file);
    menuBar->addMenu(help);
    file->addAction(new QAction("Nuovo", file));
    file->addAction(new QAction("Apri", file));
    file->addAction(new QAction("Chiudi", file));
    help->addAction(new QAction("Guida", help));
    mainLayout->addWidget(menuBar);

    QTabWidget* mainTab = new QTabWidget;

    QWidget* menuWidget = new QWidget;
    QVBoxLayout* menuWidgetLayout = new QVBoxLayout;
    menuWidget->setLayout(menuWidgetLayout);

    QHBoxLayout* menuLayout = new QHBoxLayout;
    QGroupBox* buttonGroupBox = new QGroupBox("Edit");
    QHBoxLayout* controlsLayout = new QHBoxLayout;
    QPushButton* addItem = new QPushButton("Add");
    QPushButton* modifyItem = new QPushButton("Edit");
    QPushButton* deleteItem = new QPushButton("Delete");
    controlsLayout->addWidget(addItem);
    controlsLayout->addWidget(modifyItem);
    controlsLayout->addWidget(deleteItem);
    buttonGroupBox->setLayout(controlsLayout);
    menuLayout->addWidget(buttonGroupBox);

    QGroupBox* searchGroupBox = new QGroupBox("Search");
    QHBoxLayout* searchLayout = new QHBoxLayout;
    searchBox = new QLineEdit;
    QGridLayout* searchOptionLayout = new QGridLayout;
    QCheckBox* searchName = new QCheckBox("Name");
    QCheckBox* searchPrice = new QCheckBox("Price");
    QCheckBox* searchFormat = new QCheckBox("Format");
    QButtonGroup* searchOptionButtonGroup = new QButtonGroup;
    searchOptionButtonGroup->addButton(searchName);
    searchOptionButtonGroup->addButton(searchPrice);
    searchOptionButtonGroup->addButton(searchFormat);
    searchOptionButtonGroup->setExclusive(true);
    searchLayout->addWidget(searchBox);
    searchOptionLayout->addWidget(searchName, 0, 0, 1, 1);
    searchOptionLayout->addWidget(searchPrice, 1, 0, 1, 1);
    searchOptionLayout->addWidget(searchFormat, 0, 1, 1, 1);
    searchLayout->addLayout(searchOptionLayout);
    searchGroupBox->setLayout(searchLayout);
    menuLayout->addWidget(searchGroupBox);
    menuWidgetLayout->addLayout(menuLayout);

    menuTab = new QTabWidget;
    menuTable = new QTableWidget;
    QStringList headerMenuTable;
    headerMenuTable << "Name" << "Price";
    menuTable->setColumnCount(2);
    menuTable->setHorizontalHeaderLabels(headerMenuTable);
    menuTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    menuTable->verticalHeader()->hide();
    menuTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    menuTable->setSelectionMode(QAbstractItemView::SingleSelection);
    menuTable->setAlternatingRowColors(true);
    menuTable->setSortingEnabled(false);
    menuTable->resizeRowsToContents();
    menuTable->horizontalHeader()->setSectionsClickable(true);
    menuTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    menuTable->setFocusPolicy(Qt::NoFocus);

    fill_menuTable(menuTable, menu_);

    menuTab->addTab(menuTable, "All");

    foodTable = new QTableWidget;
    QStringList headerFoodTable;
    headerFoodTable << "Name" << "Price" << "Gluten free";
    foodTable->setColumnCount(3);
    foodTable->setHorizontalHeaderLabels(headerFoodTable);
    foodTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    foodTable->verticalHeader()->hide();
    foodTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    foodTable->setSelectionMode(QAbstractItemView::SingleSelection);
    foodTable->setAlternatingRowColors(true);
    foodTable->setSortingEnabled(false);
    foodTable->resizeRowsToContents();
    foodTable->horizontalHeader()->setSectionsClickable(true);
    foodTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    foodTable->setFocusPolicy(Qt::NoFocus);

    fill_foodTable(foodTable, menu_);
    menuTab->addTab(foodTable, "Food");

    drinkTable = new QTableWidget;
    QStringList headerDrinkTable;
    headerDrinkTable << "Name" << "Price" << "Format";
    drinkTable->setColumnCount(3);
    drinkTable->setHorizontalHeaderLabels(headerDrinkTable);
    drinkTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    drinkTable->verticalHeader()->hide();
    drinkTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    drinkTable->setSelectionMode(QAbstractItemView::SingleSelection);
    drinkTable->setAlternatingRowColors(true);
    drinkTable->setSortingEnabled(false);
    drinkTable->resizeRowsToContents();
    drinkTable->horizontalHeader()->setSectionsClickable(true);
    drinkTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    drinkTable->setFocusPolicy(Qt::NoFocus);

    fill_drinkTable(drinkTable, menu_);

    menuTab->addTab(drinkTable, "Drink");


    mainTab->addTab(menuWidget, "Menu");
    menuWidgetLayout->addWidget(menuTab);

    QWidget* libraryWidget = new QWidget;
    QVBoxLayout* libraryWidgetLayout = new QVBoxLayout;
    libraryWidget->setLayout(libraryWidgetLayout);
    libraryWidgetLayout->addLayout(menuLayout);

    libraryTab = new QTabWidget;
    libraryTable = new QTableWidget;
    QStringList headerLibraryTable;
    headerLibraryTable << "Name" << "Description" << "Quantity";
    libraryTable->setColumnCount(3);
    libraryTable->setHorizontalHeaderLabels(headerLibraryTable);
    libraryTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    libraryTable->verticalHeader()->hide();
    libraryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    libraryTable->setSelectionMode(QAbstractItemView::SingleSelection);
    libraryTable->setAlternatingRowColors(true);
    libraryTable->setSortingEnabled(false);
    libraryTable->resizeRowsToContents();
    libraryTable->horizontalHeader()->setSectionsClickable(true);
    libraryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    libraryTable->setFocusPolicy(Qt::NoFocus);

    fill_libraryTable(library_);
    libraryTab->addTab(libraryTable, "All");
    /*
    mangaTable = new QTableWidget;
    QStringList headerMangaTable;
    headerMangaTable << "Name" << "Quantity" << "Author" << "Volume" << "Pages" << "Target";
    mangaTable->setColumnCount(6);
    mangaTable->setHorizontalHeaderLabels(headerMangaTable);
    mangaTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mangaTable->verticalHeader()->hide();
    mangaTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    mangaTable->setSelectionMode(QAbstractItemView::SingleSelection);
    mangaTable->setAlternatingRowColors(true);
    mangaTable->setSortingEnabled(false);
    mangaTable->resizeRowsToContents();
    mangaTable->horizontalHeader()->setSectionsClickable(true);
    mangaTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mangaTable->setFocusPolicy(Qt::NoFocus);

    fill_mangaTable(library_);
    libraryTab->addTab(mangaTable, "Manga");
    */
    mainTab->addTab(libraryWidget, "Library");
    libraryWidgetLayout->addWidget(libraryTab);

    mainLayout->addWidget(mainTab);
    setLayout(mainLayout);

    connect(addItem, &QPushButton::clicked, this, &MainWindow::add_menu);
    connect(modifyItem, &QPushButton::clicked, this, &MainWindow::modify_menu);
    connect(menuTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::sort);
    connect(foodTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::sort);
    connect(drinkTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::sort);
    connect(searchName, &QCheckBox::stateChanged, this, &MainWindow::set_search_name);
    connect(searchPrice, &QCheckBox::stateChanged, this, &MainWindow::set_search_price);
    connect(searchFormat, &QCheckBox::stateChanged, this, &MainWindow::set_search_format);
    connect(deleteItem, &QPushButton::clicked, this, &MainWindow::cancel);
    connect(searchBox, &QLineEdit::textChanged, this , &MainWindow::search);
    connect(addWidget, &CafeItemAddWidget::add_to_menu, this, &MainWindow::add_cafe_item);
    connect(editWidget, &CafeItemEditWidget::edited, this, &MainWindow::menu_edited);
    connect(menuTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_info);
    connect(foodTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_info);
    connect(drinkTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_info);
}

void MainWindow::show_info(){
    if(menuTab->currentIndex() == 0){
        size_t index = menuTable->currentRow();
        infoWidget = new CafeItemInfoWidget(&menu_[index]);
        infoWidget->show();
    }else if(menuTab->currentIndex() == 1){
        size_t index = foodTable->currentRow();
        infoWidget = new CafeItemInfoWidget(&(menu_.only_food()[index]));
        infoWidget->show();
    }else if(menuTab->currentIndex() == 2){
        size_t index = drinkTable->currentRow();
        infoWidget = new CafeItemInfoWidget(&(menu_.only_drink()[index]));
        infoWidget->show();
    }
}

void MainWindow::add_menu(){
    addWidget->show();
}

void MainWindow::add_cafe_item(CafeItem* item){
    menu_.add(item);
    update_menu_tables();
}

void MainWindow::modify_menu(){

    if(menuTab->currentIndex() == 0){
        size_t index = menuTable->currentRow();
        editWidget = new CafeItemEditWidget(&menu_[index]);
        editWidget->show();
    }else if(menuTab->currentIndex() == 1){
        size_t index = foodTable->currentRow();
        editWidget = new CafeItemEditWidget(&(menu_.only_food()[index]));
        editWidget->show();
    }else if(menuTab->currentIndex() == 2){
        size_t index = drinkTable->currentRow();
        editWidget = new CafeItemEditWidget(&(menu_.only_drink()[index]));
        editWidget->show();
    }
}

void MainWindow::menu_edited(){
    update_menu_tables();
}

void MainWindow::sort(int index){
    //if(index == 0) menu_.sort();
    //else if(index == 1) menu_.sort_by_price();
    //else if(menuTab->currentIndex() == 1) menu_.sort_by_gluten_free();
    //else if(menuTab->currentIndex() == 2) menu_.sort_by_format();
    update_menu_tables();
}

void MainWindow::search(){

    if(search_mode_ == 0){
        QString name = searchBox->displayText();
        if(menuTab->currentIndex() == 0){
            Menu searched = menu_.search_by_name(name.toStdString());
            fill_menuTable(menuTable, searched);
        }else if(menuTab->currentIndex() == 1){
            Menu searched = menu_.only_food().search_by_name(name.toStdString());
            fill_foodTable(foodTable, searched);
        }else{
            Menu searched = menu_.only_drink().search_by_name(name.toStdString());
            fill_drinkTable(drinkTable, searched);
        }
    }else if(search_mode_ == 1){
        QString price = searchBox->displayText();
        if(price == "") price = "99999";
        if(menuTab->currentIndex() == 0){
            Menu searched = menu_.search_by_price(price.toDouble());
            fill_menuTable(menuTable, searched);
        }else if(menuTab->currentIndex() == 1){
            Menu searched = menu_.only_food().search_by_price(price.toDouble());
            fill_foodTable(foodTable, searched);
        }else{
            Menu searched = menu_.only_drink().search_by_price(price.toDouble());
            fill_drinkTable(drinkTable, searched);
        }
    }else if(search_mode_ == 2){
        /*
        QString format_string = searchBox->displayText();
        enum size format;
        if(format_string == "small") format = small;
        else if(format_string == "medium") format = medium;
        else if(format_string == "big") format = big;
        if(menuTab->currentIndex() == 2){
            //Menu searched = menu_.only_drink().search_by_format(format);
            //fill_drinkTable(drinkTable, searched);
        }
        */
    }


}

void MainWindow::set_search_name(int a){
    if(a == Qt::CheckState::Checked) search_mode_ = 0;
}

void MainWindow::set_search_price(int a){
    if(a == Qt::CheckState::Checked) search_mode_ = 1;
}

void MainWindow::set_search_format(int a){
    if(a == Qt::CheckState::Checked) search_mode_ = 2;
}

void MainWindow::cancel(){
    if(menuTab->currentIndex() == 0){
        size_t index = menuTable->currentRow();
        menu_.remove(index);
    }else if(menuTab->currentIndex() == 1){
        size_t index = foodTable->currentRow();
        menu_.remove(&(menu_.only_food()[index]));
    }else if(menuTab->currentIndex() == 2){
        size_t index = drinkTable->currentRow();
        menu_.remove(&(menu_.only_drink()[index]));
    }
    update_menu_tables();
}

void MainWindow::update_menu_tables(){
    fill_menuTable(menuTable, menu_);
    fill_foodTable(foodTable, menu_);
    fill_drinkTable(drinkTable, menu_);
}

void MainWindow::fill_menuTable(QTableWidget* table, const Menu& menu){
    table->clearContents();
    table->setRowCount(0);
    for(size_t i = 0; i < menu.get_size(); i++){
        table->insertRow(table->rowCount());
        QString name = QString::fromStdString(menu[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 0, itemName);
        QString price = QString::number(menu[i].get_price());
        QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
        itemPrice->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 1, itemPrice);
    }
}

void MainWindow::fill_foodTable(QTableWidget* table, const Menu& menu){
    table->clearContents();
    table->setRowCount(0);
    Menu cibo = menu.only_food();
    for(size_t i = 0; i < cibo.get_size(); i++){
        CafeInfoVisitor visitor;
        cibo[i].accept(visitor);
        table->insertRow(table->rowCount());
        QString name = QString::fromStdString(cibo[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 0, itemName);
        QString price = QString::number(cibo[i].get_price());
        QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
        itemPrice->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 1, itemPrice);
        QString gluten = QString(visitor.is_gluten_free() ? "Yes" : "No");
        QTableWidgetItem* itemGluten = new QTableWidgetItem(gluten);
        itemGluten->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 2, itemGluten);
    }
}

void MainWindow::fill_drinkTable(QTableWidget* table, const Menu& menu){
    table->clearContents();
    table->setRowCount(0);
    Menu bevande = menu.only_drink();
    for(size_t i = 0; i < bevande.get_size(); i++){
        CafeInfoVisitor visitor;
        bevande[i].accept(visitor);
        table->insertRow(table->rowCount());
        QString name = QString::fromStdString(bevande[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 0, itemName);
        QString price = QString::number(bevande[i].get_price());
        QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
        itemPrice->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 1, itemPrice);
        QString format = "";
        switch(visitor.get_format()){
        case small: format = "Small"; break;
        case medium: format = "Medium"; break;
        case big: format = "Big"; break;
        }
        QTableWidgetItem* itemFormat = new QTableWidgetItem(format);
        itemFormat->setTextAlignment(Qt::AlignCenter);
        table->setItem(i, 2, itemFormat);
    }
}
/*
void MainWindow::update_library_tables(){
    fill_libraryTable(library_);
    fill_mangaTable(library_);
    fill_dvdTable(library_);
    fill_videogameTable(library_);
}
*/
void MainWindow::fill_libraryTable(const Library& library){
    libraryTable->clearContents();
    libraryTable->setRowCount(0);
    for(size_t i = 0; i < library.get_size(); i++){
        libraryTable->insertRow(libraryTable->rowCount());
        QString name = QString::fromStdString(library[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        libraryTable->setItem(i, 0, itemName);
        QString description = QString::fromStdString(library[i].get_description());
        QTableWidgetItem* itemDescription = new QTableWidgetItem(description);
        itemDescription->setTextAlignment(Qt::AlignCenter);
        libraryTable->setItem(i, 1, itemDescription);
        QString quantity = QString::number(library[i].get_quantity());
        QTableWidgetItem* itemQuantity = new QTableWidgetItem(quantity);
        itemQuantity->setTextAlignment(Qt::AlignCenter);
        libraryTable->setItem(i, 2, itemQuantity);
    }
}
/*
void MainWindow::fill_mangaTable(const Library& library){
    mangaTable->clearContents();
    mangaTable->setRowCount(0);
    Library manga = library.only_manga();
    for(size_t i = 0; i < library.get_size(); i++){
        EntInfoVisitor visitor;
        manga[i].accept(visitor);
        mangaTable->insertRow(mangaTable->rowCount());
        QString name = QString::fromStdString(manga[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        mangaTable->setItem(i, 0, itemName);
        QString quantity = QString::number(manga[i].get_quantity());
        QTableWidgetItem* itemQuantity = new QTableWidgetItem(quantity);
        itemQuantity->setTextAlignment(Qt::AlignCenter);
        mangaTable->setItem(i, 1, itemQuantity);
        QString author = QString::fromStdString(visitor.get_author());
        QTableWidgetItem* itemAuthor = new QTableWidgetItem(author);
        itemName->setTextAlignment(Qt::AlignCenter);
        mangaTable->setItem(i, 2, itemAuthor);
        QString volume = QString::number(visitor.get_volume());
        QTableWidgetItem* itemVolume = new QTableWidgetItem(volume);
        itemQuantity->setTextAlignment(Qt::AlignCenter);
        mangaTable->setItem(i, 3, itemVolume);
        QString pages = QString::number(visitor.get_pages());
        QTableWidgetItem* itemPages = new QTableWidgetItem(pages);
        itemQuantity->setTextAlignment(Qt::AlignCenter);
        mangaTable->setItem(i, 4, itemPages);
        QString target = "";
        switch(visitor.get_target()){
        case shounen: target = "Shounen"; break;
        case seinen: target = "Seinen"; break;
        case shojo: target = "Shojo"; break;
        case josei: target = "Josei"; break;
        case none: target = "None"; break;
        }
        QTableWidgetItem* itemTarget = new QTableWidgetItem(target);
        mangaTable->setItem(i, 5, itemTarget);
    }
}

void MainWindow::fill_dvdTable(const Library& library){

}

void MainWindow::fill_videogameTable(const Library& library){

}
*/
