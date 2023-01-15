#ifndef ENTADDVISITOR_H
#define ENTADDVISITOR_H

#include "entvisitor.h"

class EntAddVisitor: public EntVisitor{
public:
    virtual void visit(Manga& manga);
    virtual void visit(Dvd& dvd);
    virtual void visit(Series& series);
    virtual void visit(Videogame& videogame);
    Manga* get_manga() const;
    Dvd* get_dvd() const;
    Series* get_series() const;
    Videogame* get_videogame() const;
private:
    Manga* manga_;
    Dvd* dvd_;
    Series* series_;
    Videogame* videogame_;
};


#endif