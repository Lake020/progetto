#ifndef CAFEADDVISITOR_H
#define CAFEADDVISITOR_H

#include "cafevisitor.h"

class CafeAddVisitor : public CafeVisitor{
public:
    virtual void visit(Food& food);
    virtual void visit(Drink& food);
    Food* get_food() const;
    Drink* get_drink() const;
private:
    Food* food_;
    Drink* drink_;
};

#endif
