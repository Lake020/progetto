#include "entinfovisitor.h"

void EntInfoVisitor::visit(Manga& manga){
    author_ = manga.get_author();
    pages_ = manga.get_pages();
    volume_ = manga.get_volume();
    target_ = manga.get_target();
}

void EntInfoVisitor::visit(Dvd& dvd){
    production_ = dvd.get_production();
    length_ = dvd.get_length();
}

void EntInfoVisitor::visit(Series& series){
    production_ = series.get_production();
    length_ = series.get_length();
    episodes_ = series.get_episodes();
}

void EntInfoVisitor::visit(Videogame& videogame){
    company_ = videogame.get_company();
    pegi_= videogame.get_pegi();
}

std::string EntInfoVisitor::get_author() const{
    return author_;
}

unsigned int EntInfoVisitor::get_pages() const{
    return pages_;
}

unsigned int EntInfoVisitor::get_volume() const{
    return volume_;
}

Target EntInfoVisitor::get_target() const{
    return target_;
}

std::string EntInfoVisitor::get_production() const{
    return production_;
}

unsigned int EntInfoVisitor::get_length() const{
    return length_;
}

unsigned int EntInfoVisitor::get_episodes() const{
    return episodes_;
}

std::string EntInfoVisitor::get_company() const{
    return company_;
}

unsigned int EntInfoVisitor::get_pegi() const{
    return pegi_;
}