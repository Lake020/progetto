#include "search.h"
#include "cafeinfovisitor.h"
#include "entinfovisitor.h"
#include <algorithm>

bool search_string(const std::string& s, const std::string& t){
    if(s.size() < t.size()) return false;
    bool match = false;
    std::string s1 = s;
    std::string s2 = t;
    std::transform(s1.begin(), s1.end(), s1.begin(),[](unsigned char c){ return std::tolower(c); });
    std::transform(s2.begin(), s2.end(), s2.begin(),[](unsigned char c){ return std::tolower(c); });
    for(size_t i = 0; i < s1.size() && !match; i++){
        match = true;
        for(size_t j = 0; j < s2.size() && match; j++){
            if(s1[i+j] != s2[j]){
                match = false;
            }
        }
    }
    return match;
}

SearchNameMenu::SearchNameMenu(const std::string& s):s1(s){}

bool SearchNameMenu::operator()(CafeItem*& v) const{
    std::string s2 = v->get_name();
    return search_string(s2, s1);
}

SearchPrice::SearchPrice(double price): price_(price){}

bool SearchPrice::operator()(CafeItem*& v) const{
    return v->get_price() <= price_;
}

SearchGlutenFree::SearchGlutenFree(bool val): value(val){}

bool SearchGlutenFree::operator()(CafeItem*& v) const{
    CafeInfoVisitor visitor;
    v->accept(visitor);
    return visitor.is_gluten_free() == value;
}

SearchNameLibrary::SearchNameLibrary(const std::string& s):s1(s){}

bool SearchNameLibrary::operator()(Entertainment*& v) const{
    std::string s2 = v->get_name();
    return search_string(s2, s1);
}

SearchQuantity::SearchQuantity(unsigned int quantity): quantity_(quantity){}

bool SearchQuantity::operator()(Entertainment*& v) const{
    return v->get_quantity() <= quantity_;
}

SearchDescription::SearchDescription(const std::string& s):s1(s){}

bool SearchDescription::operator()(Entertainment*& v) const{
    std::string s2 = v->get_description();
    return search_string(s2, s1);
}
