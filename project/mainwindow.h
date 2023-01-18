#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menu.h"
#include "cafeitemaddwidget.h"
#include "cafeitemeditwidget.h"
#include "cafeiteminfowidget.h"
#include "library.h"
#include "libraryaddwidget.h"
#include<QWidget>
#include<QMenuBar>
#include<QPushButton>
#include<QLineEdit>
#include<QTabWidget>
#include<QTableWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QCheckBox>
#include<QButtonGroup>
#include<QGroupBox>
#include<QStringList>
#include<QHeaderView>

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow(const Menu& menu, const Library& library, QWidget *parent = nullptr);
public slots:
    void menu_sort(int index);
    void add_menu();
    void add_cafe_item(CafeItem* item);
    void modify_menu();
    void menu_edited();
    void menu_cancel();
    void show_menu_info();
    void menu_search();
    void set_menu_search_name(int);
    void set_menu_search_price(int);
    void set_menu_search_format(int);
    void library_cancel();
    void add_library();
    void add_ent_item(Entertainment* item);
private:
    Menu menu_;
    Library library_;

    int search_mode_;
    CafeItemAddWidget* menuAddWidget;
    CafeItemEditWidget* editWidget;
    CafeItemInfoWidget* infoWidget;

    QLineEdit* menuSearch;

    QTabWidget* menuTab;
    QTableWidget* menuTable;
    QTableWidget* foodTable;
    QTableWidget* drinkTable;
    void update_menu_tables();
    void fill_menuTable(QTableWidget* table, const Menu& menu);
    void fill_foodTable(QTableWidget* table, const Menu& menu);
    void fill_drinkTable(QTableWidget* table, const Menu& menu);

    LibraryAddWidget* libraryAddWidget;
    QLineEdit* librarySearch;

    QTabWidget* libraryTab;
    QTableWidget* libraryTable;
    QTableWidget* mangaTable;
    QTableWidget* dvdTable;
    QTableWidget* videogameTable;
    void update_library_tables();
    void fill_libraryTable(const Library& library);
    void fill_mangaTable(const Library& library);
    void fill_dvdTable(const Library& library);
    void fill_videogameTable(const Library& library);

};
#endif // MAINWINDOW_H
