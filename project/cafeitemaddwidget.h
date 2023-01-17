#ifndef CAFEITEMADDWIDGET_H
#define CAFEITEMADDWIDGET_H

#include "food.h"
#include "drink.h"

#include<QWidget>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
#include<QFileDialog>
#include<QFormLayout>
#include<QLineEdit>
#include<QComboBox>
#include<QDoubleSpinBox>

class CafeItemAddWidget : public QWidget{
    Q_OBJECT
public:
    explicit CafeItemAddWidget(QWidget *parent = nullptr);
    void closeEvent (QCloseEvent *event);
private:
    QVBoxLayout* layout;
    QComboBox* type;
    QFormLayout* formLayout;
    QPushButton* browseImage;
    QHBoxLayout* imageLayout;
    QLineEdit* name;
    QComboBox* extra;
    QLineEdit* image;
    QDoubleSpinBox* price;
    QHBoxLayout* buttonLayout;
    QPushButton* addButton;
    QPushButton* cancelButton;
    void FoodExtraInfo();
    void DrinkExtraInfo();
signals:
    void add_to_menu(CafeItem* item);
public slots:
    void extra_info();
    void browse_image();
    void add_item();
};

#endif // CAFEITEMADDWIDGET_H
