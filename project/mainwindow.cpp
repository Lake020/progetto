#include "mainwindow.h"
#include "cafeinfovisitor.h"

MainWindow::MainWindow(const Menu& menu, QWidget *parent):QWidget(parent), menu_(menu){
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

    QWidget* scheda1 = new QWidget;
    QVBoxLayout* scheda1Layout = new QVBoxLayout;
    scheda1->setLayout(scheda1Layout);

    QHBoxLayout* menuLayout = new QHBoxLayout;
    QGroupBox* buttonGroupBox = new QGroupBox("Edit");
    QHBoxLayout* controlsLayout = new QHBoxLayout;
    QPushButton* addItem = new QPushButton("Aggiungi");
    QPushButton* modifyItem = new QPushButton("Modifica");
    QPushButton* deleteItem = new QPushButton("Cancella");
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
    scheda1Layout->addLayout(menuLayout);

    tableTab = new QTabWidget;
    table1 = new QTableWidget;
    QStringList headerTable1;
    headerTable1 << "Nome" << "Prezzo";
    table1->setColumnCount(2);
    table1->setHorizontalHeaderLabels(headerTable1);
    table1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table1->verticalHeader()->hide();
    table1->setSelectionBehavior(QAbstractItemView::SelectRows);
    table1->setSelectionMode(QAbstractItemView::SingleSelection);
    table1->setAlternatingRowColors(true);
    table1->setSortingEnabled(false);
    table1->resizeRowsToContents();
    table1->horizontalHeader()->setSectionsClickable(false);
    table1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table1->setFocusPolicy(Qt::NoFocus);
    table1->setRowCount(0);

    for(size_t i = 0; i < menu_.get_size(); i++){
        table1->insertRow(table1->rowCount());
        QString name = QString::fromStdString(menu_[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        table1->setItem(i, 0, itemName);
        QString price = QString::number(menu_[i].get_price());
        QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
        itemPrice->setTextAlignment(Qt::AlignCenter);
        table1->setItem(i, 1, itemPrice);
    }

    tableTab->addTab(table1, "Tutto");

    table2 = new QTableWidget;
    QStringList headerTable2;
    headerTable2 << "Nome" << "Prezzo" << "Senza glutine";
    table2->setColumnCount(3);
    table2->setHorizontalHeaderLabels(headerTable2);
    table2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table2->verticalHeader()->hide();
    table2->setSelectionBehavior(QAbstractItemView::SelectRows);
    table2->setSelectionMode(QAbstractItemView::SingleSelection);
    table2->setAlternatingRowColors(true);
    table2->setSortingEnabled(false);
    table2->resizeRowsToContents();
    table2->horizontalHeader()->setSectionsClickable(false);
    table2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table2->setFocusPolicy(Qt::NoFocus);
    table2->setRowCount(0);

    Menu cibo = menu_.only_food();
    for(size_t i = 0; i < cibo.get_size(); i++){
        CafeInfoVisitor visitor;
        cibo[i].accept(visitor);
        table2->insertRow(table2->rowCount());
        QString name = QString::fromStdString(cibo[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        table2->setItem(i, 0, itemName);
        QString price = QString::number(cibo[i].get_price());
        QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
        itemPrice->setTextAlignment(Qt::AlignCenter);
        table2->setItem(i, 1, itemPrice);
        QString gluten = QString(visitor.is_gluten_free() ? "Yes" : "No");
        QTableWidgetItem* itemGluten = new QTableWidgetItem(gluten);
        itemGluten->setTextAlignment(Qt::AlignCenter);
        table2->setItem(i, 2, itemGluten);
    }
    tableTab->addTab(table2, "Cibo");

    table3 = new QTableWidget;
    QStringList headerTable3;
    headerTable3 << "Nome" << "Prezzo" << "Formato";
    table3->setColumnCount(3);
    table3->setHorizontalHeaderLabels(headerTable3);
    table3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table3->verticalHeader()->hide();
    table3->setSelectionBehavior(QAbstractItemView::SelectRows);
    table3->setSelectionMode(QAbstractItemView::SingleSelection);
    table3->setAlternatingRowColors(true);
    table3->setSortingEnabled(false);
    table3->resizeRowsToContents();
    table3->horizontalHeader()->setSectionsClickable(false);
    table3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table3->setFocusPolicy(Qt::NoFocus);
    table3->setRowCount(0);

    Menu bevande = menu_.only_drink();
    for(size_t i = 0; i < bevande.get_size(); i++){
        CafeInfoVisitor visitor;
        bevande[i].accept(visitor);
        table3->insertRow(table3->rowCount());
        QString name = QString::fromStdString(bevande[i].get_name());
        QTableWidgetItem* itemName = new QTableWidgetItem(name);
        itemName->setTextAlignment(Qt::AlignCenter);
        table3->setItem(i, 0, itemName);
        QString price = QString::number(bevande[i].get_price());
        QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
        itemPrice->setTextAlignment(Qt::AlignCenter);
        table3->setItem(i, 1, itemPrice);
        QString format = "";
        if(visitor.get_format() == 0) format = "Small";
        else if(visitor.get_format() == 1) format = "Medium";
        else if(visitor.get_format() == 2) format = "Big";
        QTableWidgetItem* itemFormat = new QTableWidgetItem(format);
        itemFormat->setTextAlignment(Qt::AlignCenter);
        table3->setItem(i, 2, itemFormat);
    }
    tableTab->addTab(table3, "Bevande");


    mainTab->addTab(scheda1, "Menu");
    scheda1Layout->addWidget(tableTab);

    mainLayout->addWidget(mainTab);
    setLayout(mainLayout);


    connect(searchBox, &QLineEdit::textChanged, this , &MainWindow::search_by_name);
}

void MainWindow::search_by_name(){
    QString name = searchBox->displayText();
    if(tableTab->currentIndex() == 0){
        Menu searched = menu_.search_by_name(name.toStdString());
        table1->clearContents();
        table1->setRowCount(0);
        for(size_t i = 0; i < searched.get_size(); i++){
            table1->insertRow(table1->rowCount());
            QString name = QString::fromStdString(searched[i].get_name());
            QTableWidgetItem* itemName = new QTableWidgetItem(name);
            itemName->setTextAlignment(Qt::AlignCenter);
            table1->setItem(i, 0, itemName);
            QString price = QString::number(searched[i].get_price());
            QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
            itemPrice->setTextAlignment(Qt::AlignCenter);
            table1->setItem(i, 1, itemPrice);
        }
        table1->show();
    }else if(tableTab->currentIndex() == 1){
        Menu searched = menu_.only_food().search_by_name(name.toStdString());
        table2->clearContents();
        table2->setRowCount(0);
        for(size_t i = 0; i < searched.get_size(); i++){
            CafeInfoVisitor visitor;
            searched[i].accept(visitor);
            table2->insertRow(table2->rowCount());
            QString name = QString::fromStdString(searched[i].get_name());
            QTableWidgetItem* itemName = new QTableWidgetItem(name);
            itemName->setTextAlignment(Qt::AlignCenter);
            table2->setItem(i, 0, itemName);
            QString price = QString::number(searched[i].get_price());
            QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
            itemPrice->setTextAlignment(Qt::AlignCenter);
            table2->setItem(i, 1, itemPrice);
            QString gluten = QString(visitor.is_gluten_free() ? "Yes" : "No");
            QTableWidgetItem* itemGluten = new QTableWidgetItem(gluten);
            itemGluten->setTextAlignment(Qt::AlignCenter);
            table2->setItem(i, 2, itemGluten);
        }
    }else{
        Menu searched = menu_.only_drink().search_by_name(name.toStdString());
        table3->clearContents();
        table3->setRowCount(0);
        for(size_t i = 0; i < searched.get_size(); i++){
            CafeInfoVisitor visitor;
            searched[i].accept(visitor);
            table3->insertRow(table3->rowCount());
            QString name = QString::fromStdString(searched[i].get_name());
            QTableWidgetItem* itemName = new QTableWidgetItem(name);
            itemName->setTextAlignment(Qt::AlignCenter);
            table3->setItem(i, 0, itemName);
            QString price = QString::number(searched[i].get_price());
            QTableWidgetItem* itemPrice = new QTableWidgetItem(price);
            itemPrice->setTextAlignment(Qt::AlignCenter);
            table3->setItem(i, 1, itemPrice);
            QString format = "";
            if(visitor.get_format() == 0) format = "Small";
            else if(visitor.get_format() == 1) format = "Medium";
            else if(visitor.get_format() == 2) format = "Big";
            QTableWidgetItem* itemFormat = new QTableWidgetItem(format);
            itemFormat->setTextAlignment(Qt::AlignCenter);
            table3->setItem(i, 2, itemFormat);
        }
    }
}
