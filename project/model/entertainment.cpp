#include "entertainment.h"

Entertainment::Entertainment(std::string name, std::string image, std::string description, unsigned int quantity):
name_(name), image_(image), description_(description), quantity_(quantity){}

Entertainment::~Entertainment(){}

std::string Entertainment::get_name() const{
    return name_;
}

void Entertainment::set_name(std::string name){
    name_ = name;
}

std::string Entertainment::get_image() const{
    return image_;
}

void Entertainment::set_image(std::string image){
    image_ = image;
}

std::string Entertainment::get_description() const{
    return description_;
}

void Entertainment::set_description(std::string description){
    description_ = description;
}

unsigned int Entertainment::get_quantity() const{
    return quantity_;
}

void Entertainment::set_quantity(unsigned int quantity){
    quantity_ = quantity;
}

std::ostream& operator<<(std::ostream& os, const Entertainment& v){
    return os << "title: " << v.name_ << " image: " << v.image_ 
              << " description: " << v.description_ << " quantity: " << v.quantity_;
}
