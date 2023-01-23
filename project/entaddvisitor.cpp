#include "entaddvisitor.h"

#include "manga.h"
#include "dvd.h"
#include "series.h"
#include "videogame.h"

void EntAddVisitor::visit(Manga& manga){
    manga_ = &manga;
    dvd_ = nullptr;
    series_ = nullptr;
    videogame_ = nullptr;
}

void EntAddVisitor::visit(Dvd& dvd){
    dvd_ = &dvd;
    manga_ = nullptr;
    series_ = nullptr;
    videogame_ = nullptr;
}

void EntAddVisitor::visit(Series& series){
    series_ = &series;
    dvd_ = &series;
    manga_ = nullptr;
    videogame_ = nullptr;
}

void EntAddVisitor::visit(Videogame& videogame){
    videogame_ = &videogame;
    dvd_ = nullptr;
    series_ = nullptr;
    manga_ = nullptr;
}

Manga* EntAddVisitor::get_manga() const{
    return manga_;
}

Dvd* EntAddVisitor::get_dvd() const{
    return dvd_;
}

Series* EntAddVisitor::get_series() const{
    return series_;
}

Videogame* EntAddVisitor::get_videogame() const{
    return videogame_;
}
