#include "series.h"

Series::Series(std::string name, std::string image, std::string description, unsigned int quantity,
               std::string production, unsigned int length, unsigned int episodes):
    Dvd(name, image, description, quantity, production, length), episodes_(episodes){}

unsigned int Series::get_episodes() const{
    return episodes_;
}

void Series::set_episodes(unsigned int episodes){
    episodes_ = episodes;
}

void Series::accept(EntVisitor& visitor){
    visitor.visit(*this);
}