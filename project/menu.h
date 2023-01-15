#ifndef MENU_H
#define MENU_H

#include "vector.h"
#include "cafeitem.h"
#include "food.h"
#include "drink.h"

#include<iostream>

class Menu{
    friend std::ostream& operator<<(std::ostream& os, const Menu& v);
public:
    Menu();
    ~Menu();

    CafeItem& operator[](size_t i);
    const CafeItem& operator[](size_t i) const;

    void add(CafeItem* value);
    void remove(CafeItem* value);
    void remove(size_t index);
    void clear();

    size_t get_size() const;

    void sort();
    void sort_by_price();

    template<class Predicate>
    Menu search(Predicate pred) const;
    
    Menu search_by_name(const std::string& name) const;
    Menu search_by_price(double price) const;

    Menu only_food() const;
    void sort_by_gluten_free();
    Menu gluten_free(bool val) const;
    
    Menu only_drink() const;
    void sort_by_format();
    Menu search_by_format(enum size format) const;

private:
    Vector<CafeItem*> items_;
};

std::ostream& operator<<(std::ostream& os, const Menu& v);

template<class Predicate> Menu Menu::search(Predicate pred) const{
    Menu results;
    for(size_t ind = 0; ind < get_size(); ind++){
        ind = items_.find_first_of(ind, get_size(), pred);
        if(ind < get_size()){
            results.add(items_[ind]);
        } 
    }
    return results;
}


#endif // MENU_H

