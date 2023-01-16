#ifndef CAFEEDITVISITOR_H
#define CAFEEDITVISITOR_H

#include "cafevisitor.h"
#include "food.h"
#include "drink.h"
#include<QWidget>
#include<QString>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QPushButton>
#include<QFileDialog>
#include<QFormLayout>
#include<QLineEdit>
#include<QComboBox>
#include<QDoubleSpinBox>

class CafeEditVisitor:public CafeVisitor{
public:
    virtual void visit(Food& food);
    virtual void visit(Drink& drink);
    QWidget* get_widget() const;
private:
    QWidget* widget;

    QVBoxLayout* layout;
    QFormLayout*  formLayout;
    QComboBox* type;
    QLineEdit* name;
    QPushButton* browseImage;
    QHBoxLayout* imageLayout;
    QLineEdit* image;
    QDoubleSpinBox* price;
    QComboBox* extra;
    QHBoxLayout* buttonLayout;
    QPushButton* addButton;
    QPushButton* cancelButton;

    void init_widget();
};

#endif // CAFEEDITVISITOR_H
