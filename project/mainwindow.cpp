#include "mainwindow.h"
#include "cafeinfovisitor.h"
#include "entinfovisitor.h"

MainWindow::MainWindow(const Menu& menu, const Library& library, QWidget *parent):QWidget(parent),
    menu_(menu), library_(library), menu_search_mode_(-1),
    menuAddWidget(new CafeItemAddWidget), libraryAddWidget(new LibraryAddWidget)
    {
    setWindowTitle("QtCafe");

    QVBoxLayout* mainLayout = new QVBoxLayout;

    QMenuBar* bar = new QMenuBar;
    QMenu* file = new QMenu("File");
    QMenu* help = new QMenu("?");
    bar->addMenu(file);
    bar->addMenu(help);
    file->addAction(new QAction("Nuovo", file));
    file->addAction(new QAction("Apri", file));
    file->addAction(new QAction("Chiudi", file));
    help->addAction(new QAction("Guida", help));
    mainLayout->addWidget(bar);

    QTabWidget* mainTab = new QTabWidget;

    QWidget* menuWidget = new QWidget;
    QVBoxLayout* menuWidgetLayout = new QVBoxLayout;
    menuWidget->setLayout(menuWidgetLayout);

    QHBoxLayout* menuControlsLayout = new QHBoxLayout;
    QGroupBox* menuButtonBox = new QGroupBox("Edit");
    QHBoxLayout* menuButtonLayout = new QHBoxLayout;
    QPushButton* addMenuButton = new QPushButton("Add");
    QPushButton* editMenuButton = new QPushButton("Edit");
    QPushButton* deleteMenuButton = new QPushButton("Delete");
    menuButtonLayout->addWidget(addMenuButton);
    menuButtonLayout->addWidget(editMenuButton);
    menuButtonLayout->addWidget(deleteMenuButton);
    menuButtonBox->setLayout(menuButtonLayout);
    menuControlsLayout->addWidget(menuButtonBox);

    QGroupBox* menuSearchBox = new QGroupBox("Search");
    QHBoxLayout* menuSearchLayout = new QHBoxLayout;
    menuSearch = new QLineEdit;
    QGridLayout* menuSearchOptionLayout = new QGridLayout;
    QCheckBox* menuSearchName = new QCheckBox("Name");
    QCheckBox* menuSearchPrice = new QCheckBox("Price");
    QCheckBox* menuSearchFormat = new QCheckBox("Format");
    QButtonGroup* menuSearchOptionGroup = new QButtonGroup;
    menuSearchOptionGroup->addButton(menuSearchName);
    menuSearchOptionGroup->addButton(menuSearchPrice);
    menuSearchOptionGroup->addButton(menuSearchFormat);
    menuSearchOptionGroup->setExclusive(true);
    menuSearchLayout->addWidget(menuSearch);
    menuSearchOptionLayout->addWidget(menuSearchName, 0, 0, 1, 1);
    menuSearchOptionLayout->addWidget(menuSearchPrice, 1, 0, 1, 1);
    menuSearchOptionLayout->addWidget(menuSearchFormat, 0, 1, 1, 1);
    menuSearchLayout->addLayout(menuSearchOptionLayout);
    menuSearchBox->setLayout(menuSearchLayout);
    menuControlsLayout->addWidget(menuSearchBox);
    menuWidgetLayout->addLayout(menuControlsLayout);

    menuTab = new QTabWidget;
    menuTable = new QTableWidget;
    QStringList headerMenuTable;
    headerMenuTable << "Name" << "Price";
    menuTable->setColumnCount(2);
    menuTable->setHorizontalHeaderLabels(headerMenuTable);
    menuTable->horizontalHeader()->setStyleSheet("font-weight: bold");
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
    foodTable->horizontalHeader()->setStyleSheet("font-weight: bold");
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
    drinkTable->horizontalHeader()->setStyleSheet("font-weight: bold");
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

    QHBoxLayout* libraryControlsLayout = new QHBoxLayout;
    QGroupBox* libraryButtonBox = new QGroupBox("Edit");
    QHBoxLayout* libraryButtonLayout = new QHBoxLayout;
    QPushButton* addLibraryButton = new QPushButton("Add");
    QPushButton* editLibraryButton = new QPushButton("Edit");
    QPushButton* deleteLibraryButton = new QPushButton("Delete");
    libraryButtonLayout->addWidget(addLibraryButton);
    libraryButtonLayout->addWidget(editLibraryButton);
    libraryButtonLayout->addWidget(deleteLibraryButton);
    libraryButtonBox->setLayout(libraryButtonLayout);
    libraryControlsLayout->addWidget(libraryButtonBox);

    QGroupBox* librarySearchBox = new QGroupBox("Search");
    QHBoxLayout* librarySearchLayout = new QHBoxLayout;
    librarySearch = new QLineEdit;
    QGridLayout* librarySearchOptionLayout = new QGridLayout;
    QCheckBox* librarySearchName = new QCheckBox("Name");
    QCheckBox* librarySearchQuantity = new QCheckBox("Quantity");
    QCheckBox* librarySearchDescription = new QCheckBox("Description");
    QButtonGroup* librarySearchOptionGroup = new QButtonGroup;
    librarySearchOptionGroup->addButton(librarySearchName);
    librarySearchOptionGroup->addButton(librarySearchQuantity);
    librarySearchOptionGroup->addButton(librarySearchDescription);
    librarySearchOptionGroup->setExclusive(true);
    librarySearchLayout->addWidget(librarySearch);
    librarySearchOptionLayout->addWidget(librarySearchName, 0, 0, 1, 1);
    librarySearchOptionLayout->addWidget(librarySearchQuantity, 1, 0, 1, 1);
    librarySearchOptionLayout->addWidget(librarySearchDescription, 0, 1, 1, 1);
    librarySearchLayout->addLayout(librarySearchOptionLayout);
    librarySearchBox->setLayout(librarySearchLayout);
    libraryControlsLayout->addWidget(librarySearchBox);
    libraryWidgetLayout->addLayout(libraryControlsLayout);

    libraryTab = new QTabWidget;
    libraryTable = new QTableWidget;
    QStringList headerLibraryTable;
    headerLibraryTable << "Name" << "Quantity" << "Description";
    libraryTable->setColumnCount(3);
    libraryTable->setHorizontalHeaderLabels(headerLibraryTable);
    libraryTable->horizontalHeader()->setStyleSheet("font-weight: bold");
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

    mangaTable = new QTableWidget;
    QStringList headerMangaTable;
    headerMangaTable << "Name" << "Quantity" << "Author" << "Volume" << "Pages" << "Target";
    mangaTable->setColumnCount(6);
    mangaTable->setHorizontalHeaderLabels(headerMangaTable);
    mangaTable->horizontalHeader()->setStyleSheet("font-weight: bold");
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

    dvdTable = new QTableWidget;
    QStringList headerDvdTable;
    headerDvdTable << "Name" << "Quantity" << "Production" << "Length";
    dvdTable->setColumnCount(4);
    dvdTable->setHorizontalHeaderLabels(headerDvdTable);
    dvdTable->horizontalHeader()->setStyleSheet("font-weight: bold");
    dvdTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    dvdTable->verticalHeader()->hide();
    dvdTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    dvdTable->setSelectionMode(QAbstractItemView::SingleSelection);
    dvdTable->setAlternatingRowColors(true);
    dvdTable->setSortingEnabled(false);
    dvdTable->resizeRowsToContents();
    dvdTable->horizontalHeader()->setSectionsClickable(true);
    dvdTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    dvdTable->setFocusPolicy(Qt::NoFocus);

    fill_dvdTable(library_);
    libraryTab->addTab(dvdTable, "Dvd");

    videogameTable = new QTableWidget;
    QStringList headerVideogameTable;
    headerVideogameTable << "Name" << "Quantity" << "Company" << "Pegi";
    videogameTable->setColumnCount(4);
    videogameTable->setHorizontalHeaderLabels(headerVideogameTable);
    videogameTable->horizontalHeader()->setStyleSheet("font-weight: bold");
    videogameTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    videogameTable->verticalHeader()->hide();
    videogameTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    videogameTable->setSelectionMode(QAbstractItemView::SingleSelection);
    videogameTable->setAlternatingRowColors(true);
    videogameTable->setSortingEnabled(false);
    videogameTable->resizeRowsToContents();
    videogameTable->horizontalHeader()->setSectionsClickable(true);
    videogameTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    videogameTable->setFocusPolicy(Qt::NoFocus);

    fill_videogameTable(library_);
    libraryTab->addTab(videogameTable, "Videogame");

    mainTab->addTab(libraryWidget, "Library");
    libraryWidgetLayout->addWidget(libraryTab);
    mainLayout->addWidget(mainTab);
    setLayout(mainLayout);

    connect(addMenuButton, &QPushButton::clicked, this, &MainWindow::add_menu);
    connect(menuAddWidget, &CafeItemAddWidget::add_to_menu, this, &MainWindow::add_cafe_item);
    connect(editMenuButton, &QPushButton::clicked, this, &MainWindow::modify_menu);
    connect(deleteMenuButton, &QPushButton::clicked, this, &MainWindow::menu_cancel);
    connect(menuSearchName, &QCheckBox::stateChanged, this, &MainWindow::set_menu_search_name);
    connect(menuSearchPrice, &QCheckBox::stateChanged, this, &MainWindow::set_menu_search_price);
    connect(menuSearchFormat, &QCheckBox::stateChanged, this, &MainWindow::set_menu_search_format);
    connect(menuSearch, &QLineEdit::textChanged, this , &MainWindow::menu_search);
    connect(menuTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::menu_sort);
    connect(foodTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::menu_sort);
    connect(drinkTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::menu_sort);
    connect(menuTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_menu_info);
    connect(foodTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_menu_info);
    connect(drinkTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_menu_info);

    connect(addLibraryButton, &QPushButton::clicked, this, &MainWindow::add_library);
    connect(libraryAddWidget, &LibraryAddWidget::add_to_library, this, &MainWindow::add_ent_item);
    connect(editLibraryButton, &QPushButton::clicked, this, &MainWindow::modify_library);
    connect(deleteLibraryButton, &QPushButton::clicked, this, &MainWindow::library_cancel);
    connect(librarySearchName, &QCheckBox::stateChanged, this, &MainWindow::set_library_search_name);
    connect(librarySearchDescription, &QCheckBox::stateChanged, this, &MainWindow::set_library_search_description);
    connect(librarySearchQuantity, &QCheckBox::stateChanged, this, &MainWindow::set_library_search_quantity);
    connect(librarySearch, &QLineEdit::textChanged, this , &MainWindow::library_search);
    connect(libraryTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::library_sort);
    connect(mangaTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::library_sort);
    connect(dvdTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::library_sort);
    connect(videogameTable->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow::library_sort);
    connect(libraryTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_library_info);
    connect(mangaTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_library_info);
    connect(dvdTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_library_info);
    connect(videogameTable, &QTableWidget::cellDoubleClicked, this, &MainWindow::show_library_info);
}

void MainWindow::add_library(){
    libraryAddWidget->show();
}

void MainWindow::add_ent_item(Entertainment* item){
    library_.add(item);
    update_library_tables();
}

void MainWindow::library_cancel(){
    if(static_cast<QTableWidget*>(libraryTab->currentWidget())->currentRow() >= 0){
        QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Delete");
        warning.setText("<b>You are deleting an item.</b>");
        warning.setInformativeText("Are you sure you want to delete it?\nYou can't undo this action later.");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        warning.setDefaultButton(QMessageBox::No);
        int ret = warning.exec();
        switch(ret){
        case QMessageBox::Yes :
            if(libraryTab->currentIndex() == 0){
                size_t index = libraryTable->currentRow();
                library_.remove(index);
            }else if(libraryTab->currentIndex() == 1){
                size_t index = mangaTable->currentRow();
                library_.remove(&(library_.only_manga()[index]));
            }else if(libraryTab->currentIndex() == 2){
                size_t index = dvdTable->currentRow();
                library_.remove(&(library_.only_dvd()[index]));
            }else if(libraryTab->currentIndex() == 3){
                size_t index = videogameTable->currentRow();
                library_.remove(&(library_.only_videogame()[index]));
            }
            update_library_tables();
            break;
        case QMessageBox::No : break;
        default: break;
        }
    }
}

void MainWindow::modify_library(){
    if(libraryTab->currentIndex() == 0 && libraryTable->currentRow() >= 0){
        size_t index = libraryTable->currentRow();
        libraryEditWidget = new LibraryEditWidget(&library_[index]);
        connect(libraryEditWidget, &LibraryEditWidget::edited, this, &MainWindow::library_edited);
        libraryEditWidget->show();
    }else if(libraryTab->currentIndex() == 1 && mangaTable->currentRow() >= 0){
        size_t index = mangaTable->currentRow();
        libraryEditWidget = new LibraryEditWidget(&(library_.only_manga()[index]));
        connect(libraryEditWidget, &LibraryEditWidget::edited, this, &MainWindow::library_edited);
        libraryEditWidget->show();
    }else if(libraryTab->currentIndex() == 2 && dvdTable->currentRow() >= 0){
        size_t index = dvdTable->currentRow();
        libraryEditWidget = new LibraryEditWidget(&(library_.only_dvd()[index]));
        connect(libraryEditWidget, &LibraryEditWidget::edited, this, &MainWindow::library_edited);
        libraryEditWidget->show();
    }else if(libraryTab->currentIndex() == 3 && videogameTable->currentRow() >= 0){
        size_t index = videogameTable->currentRow();
        libraryEditWidget = new LibraryEditWidget(&(library_.only_videogame()[index]));
        connect(libraryEditWidget, &LibraryEditWidget::edited, this, &MainWindow::library_edited);
        libraryEditWidget->show();
    }
}

void MainWindow::library_edited(){
    update_library_tables();
}

void MainWindow::show_library_info(){
    if(libraryTab->currentIndex() == 0){
        size_t index = libraryTable->currentRow();
        libraryInfoWidget = new LibraryInfoWidget(&library_[index]);
        libraryInfoWidget->show();
    }else if(libraryTab->currentIndex() == 1){
        size_t index = mangaTable->currentRow();
        libraryInfoWidget = new LibraryInfoWidget(&(library_.only_manga()[index]));
        libraryInfoWidget->show();
    }else if(libraryTab->currentIndex() == 2){
        size_t index = dvdTable->currentRow();
        libraryInfoWidget = new LibraryInfoWidget(&(library_.only_dvd()[index]));
        libraryInfoWidget->show();
    }else if(libraryTab->currentIndex() == 3){
        size_t index = videogameTable->currentRow();
        libraryInfoWidget = new LibraryInfoWidget(&(library_.only_videogame()[index]));
        libraryInfoWidget->show();
    }
}

void MainWindow::library_sort(int index){
    if(index == 0) library_.sort();
    else if(index == 1) library_.sort_by_quantity();
    //else if(index == 2)
      //  switch()
    update_menu_tables();
}

void MainWindow::set_library_search_name(int a){
    if(a == Qt::CheckState::Checked) library_search_mode_ = 0;
}

void MainWindow::set_library_search_quantity(int a){
    if(a == Qt::CheckState::Checked) library_search_mode_ = 1;
}

void MainWindow::set_library_search_description(int a){
    if(a == Qt::CheckState::Checked) library_search_mode_ = 2;
}

void MainWindow::library_search(){
    QString search = librarySearch->displayText();
    if(search == "") update_library_tables();
    else if(library_search_mode_ == 0){
        if(libraryTab->currentIndex() == 0){
            Library searched = library_.search_by_name(search.toStdString());
            fill_libraryTable(searched);
        }else if(libraryTab->currentIndex() == 1){
            Library searched = library_.only_manga().search_by_name(search.toStdString());
            fill_mangaTable(searched);
        }else if(libraryTab->currentIndex() == 2){
            Library searched = library_.only_dvd().search_by_name(search.toStdString());
            fill_dvdTable(searched);
        }else{
            Library searched = library_.only_videogame().search_by_name(search.toStdString());
            fill_videogameTable(searched);
        }
    }else if(library_search_mode_ == 1){
        if(libraryTab->currentIndex() == 0){
            Library searched = library_.search_by_quantity(search.toUInt());
            fill_libraryTable(searched);
        }else if(libraryTab->currentIndex() == 1){
            Library searched = library_.only_manga().search_by_quantity(search.toUInt());
            fill_mangaTable(searched);
        }else if(libraryTab->currentIndex() == 2){
            Library searched = library_.only_dvd().search_by_quantity(search.toUInt());
            fill_dvdTable(searched);
        }else{
            Library searched = library_.only_videogame().search_by_quantity(search.toUInt());
            fill_videogameTable(searched);
        }
    }else if(library_search_mode_ == 2){
        if(libraryTab->currentIndex() == 0){
            Library searched = library_.search_by_description(search.toStdString());
            fill_libraryTable(searched);
        }else if(libraryTab->currentIndex() == 1){
            Library searched = library_.only_manga().search_by_description(search.toStdString());
            fill_mangaTable(searched);
        }else if(libraryTab->currentIndex() == 2){
            Library searched = library_.only_dvd().search_by_description(search.toStdString());
            fill_dvdTable(searched);
        }else{
            Library searched = library_.only_videogame().search_by_description(search.toStdString());
            fill_videogameTable(searched);
        }
    }


}



void MainWindow::add_menu(){
    menuAddWidget->show();
}

void MainWindow::add_cafe_item(CafeItem* item){
    menu_.add(item);
    update_menu_tables();
}

void MainWindow::modify_menu(){

    if(menuTab->currentIndex() == 0 && menuTable->currentRow() >= 0){
        size_t index = menuTable->currentRow();
        menuEditWidget = new CafeItemEditWidget(&menu_[index]);
        connect(menuEditWidget, &CafeItemEditWidget::edited, this, &MainWindow::menu_edited);
        menuEditWidget->show();
    }else if(menuTab->currentIndex() == 1 && foodTable->currentRow() >= 0){
        size_t index = foodTable->currentRow();
        menuEditWidget = new CafeItemEditWidget(&(menu_.only_food()[index]));
        connect(menuEditWidget, &CafeItemEditWidget::edited, this, &MainWindow::menu_edited);
        menuEditWidget->show();
    }else if(menuTab->currentIndex() == 2 && drinkTable->currentRow() >= 0){
        size_t index = drinkTable->currentRow();
        menuEditWidget = new CafeItemEditWidget(&(menu_.only_drink()[index]));
        connect(menuEditWidget, &CafeItemEditWidget::edited, this, &MainWindow::menu_edited);
        menuEditWidget->show();
    }

}

void MainWindow::menu_edited(){
    update_menu_tables();
}

void MainWindow::show_menu_info(){
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

void MainWindow::menu_sort(int index){
    if(index == 0) menu_.sort();
    else if(index == 1) menu_.sort_by_price();
    else if(menuTab->currentIndex() == 1) menu_.sort_by_gluten_free();
    //else if(menuTab->currentIndex() == 2) menu_.sort_by_format();
    update_menu_tables();
}

void MainWindow::menu_search(){

    if(menu_search_mode_ == 0){
        QString name = menuSearch->displayText();
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
    }else if(menu_search_mode_ == 1){
        QString price = menuSearch->displayText();
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
    }else if(menu_search_mode_ == 2){
        /*
        QString format_string = menuSearch->displayText();
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

void MainWindow::set_menu_search_name(int a){
    if(a == Qt::CheckState::Checked) menu_search_mode_ = 0;
}

void MainWindow::set_menu_search_price(int a){
    if(a == Qt::CheckState::Checked) menu_search_mode_ = 1;
}

void MainWindow::set_menu_search_format(int a){
    if(a == Qt::CheckState::Checked) menu_search_mode_ = 2;
}

void MainWindow::menu_cancel(){
    if(static_cast<QTableWidget*>(menuTab->currentWidget())->currentRow() >= 0){
        QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Delete");
        warning.setText("<b>You are deleting an item.</b>");
        warning.setInformativeText("Are you sure you want to delete it?\nYou can't undo this action later.");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        warning.setDefaultButton(QMessageBox::No);
        int ret = warning.exec();
        switch(ret){
        case QMessageBox::Yes :
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
            break;
        case QMessageBox::No : break;
        default: break;
        }
    }
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

void MainWindow::update_library_tables(){
    fill_libraryTable(library_);
    fill_mangaTable(library_);
    fill_dvdTable(library_);
    fill_videogameTable(library_);
}

void MainWindow::fill_libraryTable(const Library& library){
    libraryTable->clearContents();
    libraryTable->setRowCount(0);
    for(size_t i = 0; i < library.get_size(); i++){
        libraryTable->insertRow(libraryTable->rowCount());
        QString name = QString::fromStdString(library[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        libraryTable->setItem(i, 0, itemName);
        QString quantity = QString::number(library[i].get_quantity());
        QTableWidgetItem* itemQuantity = new QTableWidgetItem(quantity);
        itemQuantity->setTextAlignment(Qt::AlignCenter);
        libraryTable->setItem(i, 1, itemQuantity);
        QString description = QString::fromStdString(library[i].get_description());
        QTableWidgetItem* itemDescription = new QTableWidgetItem(description);
        itemDescription->setTextAlignment(Qt::AlignCenter);
        libraryTable->setItem(i, 2, itemDescription);
    }
}

void MainWindow::fill_mangaTable(const Library& library){
    mangaTable->clearContents();
    mangaTable->setRowCount(0);
    Library manga = library.only_manga();
    for(size_t i = 0; i < manga.get_size(); i++){
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
        itemAuthor->setTextAlignment(Qt::AlignCenter);
        mangaTable->setItem(i, 2, itemAuthor);
        QString volume = QString::number(visitor.get_volume());
        QTableWidgetItem* itemVolume = new QTableWidgetItem(volume);
        itemVolume->setTextAlignment(Qt::AlignCenter);
        mangaTable->setItem(i, 3, itemVolume);
        QString pages = QString::number(visitor.get_pages());
        QTableWidgetItem* itemPages = new QTableWidgetItem(pages);
        itemPages->setTextAlignment(Qt::AlignCenter);
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
        itemTarget->setTextAlignment(Qt::AlignCenter);
        mangaTable->setItem(i, 5, itemTarget);
    }
}

void MainWindow::fill_dvdTable(const Library& library){
    dvdTable->clearContents();
    dvdTable->setRowCount(0);
    Library dvd = library.only_dvd();
    for(size_t i = 0; i < dvd.get_size(); i++){
        EntInfoVisitor visitor;
        dvd[i].accept(visitor);
        dvdTable->insertRow(dvdTable->rowCount());
        QString name = QString::fromStdString(dvd[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        dvdTable->setItem(i, 0, itemName);
        QString quantity = QString::number(dvd[i].get_quantity());
        QTableWidgetItem* itemQuantity = new QTableWidgetItem(quantity);
        itemQuantity->setTextAlignment(Qt::AlignCenter);
        dvdTable->setItem(i, 1, itemQuantity);
        QString production = QString::fromStdString(visitor.get_production());
        QTableWidgetItem* itemProducrion = new QTableWidgetItem(production);
        itemProducrion->setTextAlignment(Qt::AlignCenter);
        dvdTable->setItem(i, 2, itemProducrion);
        QString length = QString::number(visitor.get_length());
        QTableWidgetItem* itemLength= new QTableWidgetItem(length);
        itemLength->setTextAlignment(Qt::AlignCenter);
        dvdTable->setItem(i, 3, itemLength);
    }
}

void MainWindow::fill_videogameTable(const Library& library){
    videogameTable->clearContents();
    videogameTable->setRowCount(0);
    Library game = library.only_videogame();
    for(size_t i = 0; i < game.get_size(); i++){
        EntInfoVisitor visitor;
        game[i].accept(visitor);
        videogameTable->insertRow(videogameTable->rowCount());
        QString name = QString::fromStdString(game[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        videogameTable->setItem(i, 0, itemName);
        QString quantity = QString::number(game[i].get_quantity());
        QTableWidgetItem* itemQuantity = new QTableWidgetItem(quantity);
        itemQuantity->setTextAlignment(Qt::AlignCenter);
        videogameTable->setItem(i, 1, itemQuantity);
        QString company = QString::fromStdString(visitor.get_company());
        QTableWidgetItem* itemCompany = new QTableWidgetItem(company);
        itemCompany->setTextAlignment(Qt::AlignCenter);
        videogameTable->setItem(i, 2, itemCompany);
        QString pegi = QString::number(visitor.get_pegi());
        QTableWidgetItem* itemPegi= new QTableWidgetItem(pegi);
        itemPegi->setTextAlignment(Qt::AlignCenter);
        videogameTable->setItem(i, 3, itemPegi);
    }
}

void MainWindow::load_file(){
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home/", tr("Files (*.json)"));
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        QJsonObject ob = doc.object();
        QJsonArray menu = ob["Menu"].toArray();
        QJsonArray library = ob["Library"].toArray();
        for(int i = 0; i < menu.size(); i++){
            QJsonObject obj = menu[i].toObject();
            QString type = obj["type"].toString();
            if(type == "Food"){
                Food* f = new Food(obj["name"].toString().toStdString(),
                                obj["image"].toString().toStdString(),
                                obj["price"].toDouble(),
                                obj["gluten_free"].toBool());
                menu_.add(f);
            }else if(type == "Drink"){
                enum size format;
                switch(obj["format"].toInt()){
                case small: format = small; break;
                case medium: format = medium; break;
                case big: format = big; break;
                }
                Drink* d = new Drink(obj["name"].toString().toStdString(),
                                obj["image"].toString().toStdString(),
                                obj["price"].toDouble(),
                                format);
                menu_.add(d);
            }
        }
        for(int i = 0; i < library.size(); i++){
            QJsonObject obj = library[i].toObject();
            QString type = obj["type"].toString();
            if(type == "Manga"){
                Target target;
                switch(obj["target"].toInt()){
                case shounen: target = shounen; break;
                case seinen: target = seinen; break;
                case shojo: target = shojo; break;
                case josei: target = josei; break;
                case none: target = none; break;
                }
                Manga* m = new Manga(obj["name"].toString().toStdString(),
                                    obj["image"].toString().toStdString(),
                                    obj["description"].toString().toStdString(),
                                    obj["quantity"].toInt(),
                                    obj["author"].toString().toStdString(),
                                    obj["pages"].toInt(),
                                    obj["volume"].toInt(),
                                    target);
                library_.add(m);
            }else if(type == "Dvd"){
                Dvd* d = new Dvd(obj["name"].toString().toStdString(),
                                obj["image"].toString().toStdString(),
                                obj["description"].toString().toStdString(),
                                obj["quantity"].toInt(),
                                obj["production"].toString().toStdString(),
                                obj["length"].toInt());
                library_.add(d);
            }else if(type == "Series"){
                Series* s = new Series(obj["name"].toString().toStdString(),
                                obj["image"].toString().toStdString(),
                                obj["description"].toString().toStdString(),
                                obj["quantity"].toInt(),
                                obj["production"].toString().toStdString(),
                                obj["length"].toInt(),
                                obj["episodes"].toInt());
                library_.add(s);
            }else if(type == "Videogame"){
                Videogame* g = new Videogame(obj["name"].toString().toStdString(),
                                obj["image"].toString().toStdString(),
                                obj["description"].toString().toStdString(),
                                obj["quantity"].toInt(),
                                obj["company"].toString().toStdString(),
                                obj["pegi"].toInt());
                library_.add(g);
            }
        }
        file.close();
    }
}

void MainWindow::save_file(){
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)){
        QJsonArray menu;
        QJsonArray library;
        for(size_t i = 0; i < menu_.get_size(); i++){
            QJsonObject obj;
            if(Food* p = dynamic_cast<Food*>(&menu_[i])){
                obj.insert("type", "Food");
                obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(p->get_name())));
                obj.insert("image", QJsonValue::fromVariant(QString::fromStdString(p->get_image())));
                obj.insert("price", QJsonValue::fromVariant(p->get_price()));
                obj.insert("gluten_free", QJsonValue::fromVariant(p->is_gluten_free()));
            }else if(Drink* p = dynamic_cast<Drink*>(&menu_[i])){
                obj.insert("type", "Drink");
                obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(p->get_name())));
                obj.insert("image", QJsonValue::fromVariant(QString::fromStdString(p->get_image())));
                obj.insert("price", QJsonValue::fromVariant(p->get_price()));
                obj.insert("format", QJsonValue::fromVariant(p->get_format()));
            }
            menu.append(obj);
        }
        for(size_t i = 0; i < library_.get_size(); i++){
            QJsonObject obj;
            if(Manga* p = dynamic_cast<Manga*>(&library_[i])){
                obj.insert("type", "Manga");
                obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(p->get_name())));
                obj.insert("image", QJsonValue::fromVariant(QString::fromStdString(p->get_image())));
                obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(p->get_description())));
                obj.insert("quantity", QJsonValue::fromVariant(p->get_quantity()));
                obj.insert("author", QJsonValue::fromVariant(QString::fromStdString(p->get_author())));
                obj.insert("pages", QJsonValue::fromVariant(p->get_pages()));
                obj.insert("volume", QJsonValue::fromVariant(p->get_volume()));
                obj.insert("target", QJsonValue::fromVariant(p->get_target()));
            }else if(Series* p = dynamic_cast<Series*>(&library_[i])){
                obj.insert("type", "Series");
                obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(p->get_name())));
                obj.insert("image", QJsonValue::fromVariant(QString::fromStdString(p->get_image())));
                obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(p->get_description())));
                obj.insert("quantity", QJsonValue::fromVariant(p->get_quantity()));
                obj.insert("production", QJsonValue::fromVariant(QString::fromStdString(p->get_production())));
                obj.insert("length", QJsonValue::fromVariant(p->get_length()));
                obj.insert("episodes", QJsonValue::fromVariant(p->get_episodes()));
            }else if(Dvd* p = dynamic_cast<Dvd*>(&library_[i])){
                obj.insert("type", "Dvd");
                obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(p->get_name())));
                obj.insert("image", QJsonValue::fromVariant(QString::fromStdString(p->get_image())));
                obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(p->get_description())));
                obj.insert("quantity", QJsonValue::fromVariant(p->get_quantity()));
                obj.insert("production", QJsonValue::fromVariant(QString::fromStdString(p->get_production())));
                obj.insert("length", QJsonValue::fromVariant(p->get_length()));
            }else if(Videogame* p = dynamic_cast<Videogame*>(&library_[i])){
                obj.insert("type", "Videogame");
                obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(p->get_name())));
                obj.insert("image", QJsonValue::fromVariant(QString::fromStdString(p->get_image())));
                obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(p->get_description())));
                obj.insert("quantity", QJsonValue::fromVariant(p->get_quantity()));
                obj.insert("company", QJsonValue::fromVariant(QString::fromStdString(p->get_company())));
                obj.insert("pegi", QJsonValue::fromVariant(p->get_pegi()));
            }
            library.append(obj);
        }
        QJsonObject ob;
        file.close();
    }
}
