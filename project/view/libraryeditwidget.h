#ifndef LIBRARYEDITWIDGET_H
#define LIBRARYEDITWIDGET_H

#include "model/entertainment.h"
#include "model/manga.h"
#include "model/dvd.h"
#include "model/series.h"
#include "model/videogame.h"
#include<QCoreApplication>
#include<QWidget>
#include<QString>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QFileDialog>
#include<QFormLayout>
#include<QLineEdit>
#include<QComboBox>
#include<QSpinBox>
#include<QTextEdit>

class LibraryEditWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LibraryEditWidget(Entertainment* item, QWidget *parent = nullptr);
private:
    Entertainment* item_;

    QVBoxLayout* layout;
    QFormLayout*  formLayout;
    QLabel* type;
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
    QPushButton* editButton;
    QPushButton* cancelButton;

    void mangaExtraInfo();
    void dvdExtraInfo();
    void seriesExtraInfo();
    void videogameExtraInfo();

signals:
    void edited();
public slots:
    void browse_image();
    void edit_item();

};

#endif // LIBRARYEDITWIDGET_H
