#ifndef CAFEWIDGETVISITOR_H
#define CAFEWIDGETVISITOR_H

#include "model/cafevisitor.h"
#include<QWidget>

class CafeWidgetVisitor : public CafeVisitor{
public:
    virtual void visit(Food& food);
    virtual void visit(Drink& drink);
    QWidget* get_widget() const;
private:
    QWidget* widget;
};

#endif // CAFEWIDGETVISITOR_H
