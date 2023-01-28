#include "cafeaddvisitor.h"

void CafeAddVisitor::visit(Food& food){
    food_ = &food;
    drink_ = nullptr;
}

void CafeAddVisitor::visit(Drink& drink){
    food_ = nullptr;
    drink_ = &drink;
}

Food* CafeAddVisitor::get_food() const {
    return food_;
}

Drink* CafeAddVisitor::get_drink() const {
    return drink_;
}