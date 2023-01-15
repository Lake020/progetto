#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "menu.h"
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
    void search_by_name();
private:
    Menu menu_;

    QLineEdit* searchBox;

    QTabWidget* tableTab;
    QTableWidget* table1;
    QTableWidget* table2;
    QTableWidget* table3;
};
#endif // MAINWINDOW_H
