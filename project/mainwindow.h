#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menu.h"
#include "cafeitemaddwidget.h"
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
    MainWindow(const Menu& menu, QWidget *parent = nullptr);
public slots:
    void search();
    void sort(int index);
    void add_menu();
    void modify_menu();
    void add_cafe_item(CafeItem* item);
    void cancel();
    void set_search_name(int);
    void set_search_price(int);
    void set_search_format(int);
private:
    Menu menu_;
    int search_mode_;
    CafeItemAddWidget* addWidget;

    QLineEdit* searchBox;

    QTabWidget* tableTab;
    QTableWidget* table1;
    void fill_table1(QTableWidget* table, const Menu& menu);
    void fill_table2(QTableWidget* table, const Menu& menu);
    void fill_table3(QTableWidget* table, const Menu& menu);
    QTableWidget* table2;
    QTableWidget* table3;

};
#endif // MAINWINDOW_H
