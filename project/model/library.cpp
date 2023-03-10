#include "library.h"
#include "compare.h"
#include "search.h"
#include "entaddvisitor.h"

Library::Library(){}

Library::~Library(){}

Entertainment& Library::operator[](size_t i){
    return *(items_[i]);
}

const Entertainment& Library::operator[](size_t i) const{
    return *(items_[i]);
}

size_t Library::get_size() const{
    return items_.get_size();
}

void Library::add(Entertainment* value){
    if(value) items_.push_back(value);
}

void Library::remove(Entertainment* value){
    size_t index = items_.find(0, get_size(), value);
    items_.erase(index);
}

void Library::remove(size_t index){
    items_.erase(index);
}

void Library::clear(){
    items_.clear();
}

void Library::sort(){
    CompareNameLibrary pred;
    items_.sort_by(0, get_size(), pred);
}

void Library::sort_by_quantity(){
    CompareQuantity pred;
    items_.sort_by(0, get_size(), pred);
}


Library Library::search_by_name(const std::string& name) const{
    SearchNameLibrary pred(name);
    return search(pred);
}

Library Library::search_by_quantity(unsigned int quantity) const{
    SearchQuantity pred(quantity);
    return search(pred);
}

Library Library::search_by_description(const std::string& description) const{
    SearchDescription pred(description);
    return search(pred);
}

Library Library::only_manga() const{
    Library tmp;
    for(size_t i = 0; i < get_size(); i++){
        EntAddVisitor visitor;
        items_[i]->accept(visitor);
        tmp.add(visitor.get_manga());
    }
    return tmp;
}

void Library::sort_by_author(){
    CompareAuthor pred;
    items_.sort_by(0, get_size(), pred);
}

void Library::sort_by_pages(){
    ComparePages pred;
    items_.sort_by(0, get_size(), pred);
}

void Library::sort_by_volume(){
    CompareVolume pred;
    items_.sort_by(0, get_size(), pred);
}

void Library::sort_by_target(){
    CompareTarget pred;
    items_.sort_by(0, get_size(), pred);
}

Library Library::only_dvd() const{
    Library tmp;
    for(size_t i = 0; i < get_size(); i++){
        EntAddVisitor visitor;
        items_[i]->accept(visitor);
        tmp.add(visitor.get_dvd());
    }
    return tmp;
}

void Library::sort_by_production(){
    CompareProduction pred;
    items_.sort_by(0, get_size(), pred);
}

void Library::sort_by_length(){
    CompareLength pred;
    items_.sort_by(0, get_size(), pred);
}

Library Library::only_series() const{
    Library tmp;
    for(size_t i = 0; i < get_size(); i++){
        EntAddVisitor visitor;
        items_[i]->accept(visitor);
        tmp.add(visitor.get_series());
    }
    return tmp;
}

void Library::sort_by_episodes(){
    CompareEpisodes pred;
    items_.sort_by(0, get_size(), pred);
}

Library Library::only_videogame() const{
    Library tmp;
    for(size_t i = 0; i < get_size(); i++){
        EntAddVisitor visitor;
        items_[i]->accept(visitor);
        tmp.add(visitor.get_videogame());
    }
    return tmp;
}

void Library::sort_by_company(){
    CompareCompany pred;
    items_.sort_by(0, get_size(), pred);
}

void Library::sort_by_pegi(){
    ComparePegi pred;
    items_.sort_by(0, get_size(), pred);
}
