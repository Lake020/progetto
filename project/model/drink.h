#ifndef DRINK_H
#define DRINK_H

#include "cafeitem.h"

enum size {unique, small, medium, big};

class Drink: public CafeItem{
public:
    Drink(std::string name, std::string image, double price, enum size format = unique);
    enum size get_format() const;
    void set_format(enum size format);
    virtual void accept(CafeVisitor& visitor);
private:
    enum size format_;
};

#endif // DRINK_H
