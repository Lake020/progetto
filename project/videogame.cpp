#include "videogame.h"

Videogame::Videogame(std::string name, std::string image, std::string description, unsigned int quantity,
          std::string company, unsigned int pegi):
    Entertainment(name, image, description, quantity), company_(company), pegi_(pegi){}

std::string Videogame::get_company() const{
    return company_;
}

void Videogame::set_company(std::string company){
    company_ = company;
}

unsigned int Videogame::get_pegi() const{
    return pegi_;
}

void Videogame::set_pegi(unsigned int pegi){
    if(pegi<=18) pegi_ = pegi;
    else pegi_ = 18;
}

void Videogame::accept(EntVisitor& visitor){
    visitor.visit(*this);
}
