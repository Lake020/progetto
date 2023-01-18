#ifndef LIBRARYADDWIDGET_H
#define LIBRARYADDWIDGET_H

#include "manga.h"
#include "dvd.h"
#include "series.h"
#include "videogame.h"

#include<QWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
#include<QFileDialog>
#include<QFormLayout>
#include<QLineEdit>
#include<QComboBox>
#include<QSpinBox>
#include<QTextEdit>

class LibraryAddWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryAddWidget(QWidget *parent = nullptr);
    //void closeEvent (QCloseEvent *event);
private:
    QVBoxLayout* layout;
    QComboBox* type;
    QFormLayout* formLayout;
    QLineEdit* name;
    QHBoxLayout* imageLayout;
    QLineEdit* image;
    QPushButton* browseImage;
    QTextEdit* description;
    QSpinBox* quantity;
    QLineEdit* author;
    QSpinBox* volume;
    QSpinBox* pages;
    QComboBox* target;
    QLineEdit* production;
    QSpinBox* length;
    QSpinBox* episodes;
    QLineEdit* company;
    QSpinBox* pegi;
    QHBoxLayout* buttonLayout;
    QPushButton* addButton;
    QPushButton* cancelButton;

    void mangaExtraInfo();
    void dvdExtraInfo();
    void seriesExtraInfo();
    void videogameExtraInfo();

signals:
    void add_to_library(Entertainment* item);
public slots:
    void extra_info();
    void browse_image();
    void add_item();
};

#endif // LIBRARYADDWIDGET_H
