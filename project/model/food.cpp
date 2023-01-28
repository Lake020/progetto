#include "food.h"

Food::Food(std::string name, std::string image, double price, bool gluten_free):
    CafeItem(name, image, price), gluten_free_(gluten_free){}

bool Food::is_gluten_free() const{
    return gluten_free_;
}

void Food::set_gluten_free(bool gluten_free){
    gluten_free_ = gluten_free;
}

void Food::accept(CafeVisitor& visitor){
    visitor.visit(*this);
}
