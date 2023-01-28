#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "model/menu.h"
#include "cafeitemaddwidget.h"
#include "cafeitemeditwidget.h"
#include "cafeiteminfowidget.h"
#include "model/library.h"
#include "libraryaddwidget.h"
#include "libraryeditwidget.h"
#include "libraryinfowidget.h"
#include<QWidget>
#include<QCoreApplication>
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
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<QFileDialog>

class MainWindow : public QWidget{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
public slots:
    void create_new_file();
    void open_file();
    void save_file();
    void save_file_as();
    void close_file();

    void add_menu();
    void add_cafe_item(CafeItem* item);
    void modify_menu();
    void menu_edited();
    void menu_cancel();
    void menu_sort(int index);
    void show_menu_info();
    void menu_search();
    void set_menu_search_name(int);
    void set_menu_search_price(int);

    void add_library();
    void add_ent_item(Entertainment* item);
    void modify_library();
    void library_edited();
    void library_cancel();
    void library_sort(int index);
    void show_library_info();
    void library_search();
    void set_library_search_name(int);
    void set_library_search_description(int);
    void set_library_search_quantity(int);

private:
    Menu menu_;
    Library library_;

    QString fileName;
    bool isSaved;

    int menu_search_mode_;
    CafeItemAddWidget* menuAddWidget;
    CafeItemEditWidget* menuEditWidget;
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

    int library_search_mode_;
    LibraryAddWidget* libraryAddWidget;
    LibraryEditWidget* libraryEditWidget;
    LibraryInfoWidget* libraryInfoWidget;
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
