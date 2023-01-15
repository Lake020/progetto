#include "dvd.h"

Dvd::Dvd(std::string name, std::string image, std::string description, unsigned int quantity,
        std::string production, unsigned int length):
    Entertainment(name, image, description, quantity), production_(production), length_(length){}

std::string Dvd::get_production() const{
    return production_;
}

void Dvd::set_producrion(std::string production){
    production_ = production;
}

unsigned int Dvd::get_length() const{
    return length_;
}

void Dvd::set_length(unsigned int length){
    length_ = length;
}

void Dvd::accept(EntVisitor& visitor){
    visitor.visit(*this);
}