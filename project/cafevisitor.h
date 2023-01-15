#ifndef CAFEVISITOR_H
#define CAFEVISITOR_H

class CafeItem;
class Food;
class Drink;

class CafeVisitor{
public:
    virtual ~CafeVisitor() = default;
    virtual void visit(Food& food) = 0;
    virtual void visit(Drink& drink) = 0;
};

#endif