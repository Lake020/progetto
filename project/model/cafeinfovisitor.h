#ifndef CAFEINFOVISITOR_H
#define CAFEINFOVISITOR_H

#include "cafevisitor.h"
#include "drink.h"
#include "food.h"

class CafeInfoVisitor: public CafeVisitor{
public:
    virtual void visit(Food& food);
    virtual void visit(Drink& drink);
    bool is_gluten_free() const;
    enum size get_format() const;
private:
    bool gluten_free_;
    enum size format_;
};

#endif
