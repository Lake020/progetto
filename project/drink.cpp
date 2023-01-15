#include "drink.h"

Drink::Drink(std::string name, std::string image, double price, enum size format):
    CafeItem(name, image, price), format_(format){}

enum size Drink::get_format() const{
    return format_;
}

void Drink::set_format(enum size format){
    if(format>2 || format<0) format_ = medium;
    else format_ = format;
}

void Drink::accept(CafeVisitor& visitor){
    visitor.visit(*this);
}
