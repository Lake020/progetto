#ifndef CAFEEDITVISITOR_H
#define CAFEEDITVISITOR_H

#include "cafevisitor.h"
#include "food.h"
#include "drink.h"
#include<QString>

class CafeEditVisitor:public CafeVisitor{
public:
    virtual void visit(Food& food);
    virtual void visit(Drink& drink);
    QString get_type() const;
private:
    QString type;
};

#endif // CAFEEDITVISITOR_H
