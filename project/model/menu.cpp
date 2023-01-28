#include "menu.h"
#include "compare.h"
#include "search.h"
#include "cafeaddvisitor.h"

Menu::Menu(){}

Menu::~Menu(){}

CafeItem& Menu::operator[](size_t i){
    return *(items_[i]);
}

const CafeItem& Menu::operator[](size_t i) const{
    return *(items_[i]);
}

void Menu::add(CafeItem* value){
    if(value) items_.push_back(value);
}

void Menu::remove(CafeItem* value){
    size_t index = items_.find(0, get_size(), value);
    items_.erase(index);
}

void Menu::remove(size_t index){
    items_.erase(index);
}

void Menu::clear(){
    items_.clear();
}

size_t Menu::get_size() const{
    return items_.get_size();
}

void Menu::sort(){
    CompareNameMenu pred;
    items_.sort_by(0, get_size(), pred);
}

void Menu::sort_by_price(){
    ComparePrice pred;
    items_.sort_by(0, get_size(), pred);
}

Menu Menu::search_by_name(const std::string& name) const{
    SearchNameMenu pred(name);
    return search(pred);
}

Menu Menu::search_by_price(double price) const{
    SearchPrice pred(price);
    return search(pred);
}

Menu Menu::only_food() const{
    Menu tmp;
    for(size_t i = 0; i < get_size(); i++){
        CafeAddVisitor visitor;
        items_[i]->accept(visitor);
        tmp.add(visitor.get_food());
    }
    return tmp;
}

void Menu::sort_by_gluten_free(){
    Menu tmp = only_food();
    Menu tmp2 = tmp.gluten_free(true);
    Menu tmp3 = tmp.gluten_free(false);
    tmp = only_drink();
    tmp2.items_.append(tmp3.items_);
    tmp2.items_.append(tmp.items_);
    items_ = tmp2.items_;
}

Menu Menu::gluten_free(bool val) const{
    SearchGlutenFree pred(val);
    return search(pred);
}

Menu Menu::only_drink() const{
    Menu tmp;
    for(size_t i = 0; i < get_size(); i++){
        CafeAddVisitor visitor;
        items_[i]->accept(visitor);
        tmp.add(visitor.get_drink());
    }
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Menu& v){
    for(size_t i = 0; i < v.get_size(); i++){
        os << i+1 << " item is " << *v.items_[i] << std::endl;
    }
    return os;
}
