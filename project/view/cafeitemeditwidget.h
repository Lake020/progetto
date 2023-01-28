#ifndef CAFEITEMEDITWIDGET_H
#define CAFEITEMEDITWIDGET_H

#include "model/cafeitem.h"
#include "model/food.h"
#include "model/drink.h"
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
#include<QDoubleSpinBox>

class CafeItemEditWidget : public QWidget{
    Q_OBJECT
public:
    explicit CafeItemEditWidget(CafeItem* item, QWidget* parent = nullptr);
private:
    CafeItem* item_;

    QVBoxLayout* layout;
    QFormLayout*  formLayout;
    QLabel* type;
    QLineEdit* name;
    QHBoxLayout* imageLayout;
    QLineEdit* image;
    QPushButton* browseImage;
    QDoubleSpinBox* price;
    QComboBox* extra;
    QHBoxLayout* buttonLayout;
    QPushButton* editButton;
    QPushButton* cancelButton;
signals:
    void edited();
public slots:
    void browse_image();
    void edit_item();

};

#endif // CAFEITEMEDITWIDGET_H
