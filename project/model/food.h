#ifndef FOOD_H
#define FOOD_H

#include "cafeitem.h"

class Food: public CafeItem {
public:
    Food(std::string name, std::string image, double price, bool gluten_free = false);
    bool is_gluten_free() const;
    void set_gluten_free(bool gluten_free);
    virtual void accept(CafeVisitor& visitor);
private:
    bool gluten_free_;
};

#endif // FOOD_H
