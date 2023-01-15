#include "cafeinfovisitor.h"

void CafeInfoVisitor::visit(Food& food){
    gluten_free_ = food.is_gluten_free();
}

void CafeInfoVisitor::visit(Drink& drink){
    format_ = drink.get_format();
}

bool CafeInfoVisitor::is_gluten_free() const{
    return gluten_free_;
}

enum size CafeInfoVisitor::get_format() const{
    return format_;
}