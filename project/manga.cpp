#include "manga.h"

Manga::Manga(std::string name, std::string image, std::string description, unsigned int quantity,
             std::string author, unsigned int pages, unsigned int volume, Target target):
    Entertainment(name, image, description, quantity), author_(author), pages_(pages), volume_(volume), target_(target) {}

std::string Manga::get_author() const{
    return author_;
}

void Manga::set_author(std::string author){
    author_ = author;
}

unsigned int Manga::get_pages() const{
    return pages_;
}

void Manga::set_pages(unsigned int pages){
    pages_ = pages;
}

unsigned int Manga::get_volume() const{
    return volume_;
}

void Manga::set_volume(unsigned int volume){
    volume_ = volume;
}

Target Manga::get_target() const{
    return target_;
}

void Manga::set_target(Target target){
    target_ = target;
}

void Manga::accept(EntVisitor& visitor){
    visitor.visit(*this);
}

std::ostream& operator<<(std::ostream& os, const Manga& v){
    return os << "title: " << v.get_name() << " image: " << v.get_image() 
              << " description: " << v.get_description() << " quantity: " << v.get_quantity() 
              << " author: " << v.author_ << " pages: " << v.pages_ 
              << " volume: " << v.volume_ << " target: " << v.target_;
}