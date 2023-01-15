#ifndef ENTVISITOR_H
#define ENTVISITOR_H

class Entertainment;
class Manga;
class Dvd;
class Series;
class Videogame;

class EntVisitor{
public:
    virtual ~EntVisitor() = default;
    virtual void visit(Manga& manga) = 0;
    virtual void visit(Dvd& dvd) = 0;
    virtual void visit(Series& series) = 0;
    virtual void visit(Videogame& videogame) = 0;
};

#endif