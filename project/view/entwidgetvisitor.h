#ifndef ENTWIDGETVISITOR_H
#define ENTWIDGETVISITOR_H

#include "model/entvisitor.h"
#include<QWidget>

class EntWidgetVisitor : public EntVisitor{
public:
    virtual void visit(Manga& manga);
    virtual void visit(Dvd& dvd);
    virtual void visit(Series& series);
    virtual void visit(Videogame& game);
    QWidget* get_widget() const;
private:
    QWidget* widget;
};

#endif // ENTWIDGETVISITOR_H
