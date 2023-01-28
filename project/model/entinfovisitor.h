#ifndef ENTINFOVISITOR_H
#define ENTINFOVISITOR_H

#include "entvisitor.h"
#include "manga.h"
#include "dvd.h"
#include "series.h"
#include "videogame.h"

class EntInfoVisitor: public EntVisitor{
public:
    virtual void visit(Manga& manga);
    virtual void visit(Dvd& dvd);
    virtual void visit(Series& series);
    virtual void visit(Videogame& videogame);
    std::string get_author() const;
    unsigned int get_pages() const;
    unsigned int get_volume() const;
    Target get_target() const;
    std::string get_production() const;
    unsigned int get_length() const;
    unsigned int get_episodes() const;
    std::string get_company() const;
    unsigned int get_pegi() const;
private:
    std::string author_;
    unsigned int pages_;
    unsigned int volume_;
    Target target_;
    std::string production_;
    unsigned int length_;
    unsigned int episodes_;
    std::string company_;
    unsigned int pegi_;
};

#endif
