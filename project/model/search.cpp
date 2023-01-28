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

SearchAuthor::SearchAuthor(const std::string& s):s1(s){}

bool SearchAuthor::operator()(Entertainment*& v) const{
    EntInfoVisitor visitor;
    v->accept(visitor);
    std::string s2 = visitor.get_author();
    return search_string(s2, s1);
    /*
    if(const Manga* p = dynamic_cast<const Manga*>(v)){
        std::string s2 = p->get_author();
        return search_string(s2, s1);
    }
    return false;
    */
}

SearchPages::SearchPages(unsigned int pages): pages_(pages){}

bool SearchPages::operator()(Entertainment*& v) const{
    EntInfoVisitor visitor;
    v->accept(visitor);
    return visitor.get_pages() <= pages_;
    /*
    if(const Manga* p = dynamic_cast<const Manga*>(v)) return p->get_pages() <= pages_;
    return false;
    */
}

SearchVolume::SearchVolume(unsigned int volume): volume_(volume){}

bool SearchVolume::operator()(Entertainment*& v) const{
    EntInfoVisitor visitor;
    v->accept(visitor);
    return visitor.get_volume() <= volume_;
    /*
    if(const Manga* p = dynamic_cast<const Manga*>(v)) return p->get_volume() <= volume_;
    return false;
    */
}

SearchTarget::SearchTarget(Target target): target_(target){}

bool SearchTarget::operator()(Entertainment*& v) const{
    EntInfoVisitor visitor;
    v->accept(visitor);
    return visitor.get_target() <= target_;
    /*
    if(const Manga* p = dynamic_cast<const Manga*>(v)) return p->get_target() <= target_;
    return false;
    */
}

SearchProduction::SearchProduction(const std::string& s):s1(s){}

bool SearchProduction::operator()(Entertainment*& v) const{ 
    EntInfoVisitor visitor;
    v->accept(visitor);
    std::string s2 = visitor.get_production();
    return search_string(s2, s1);
    /*
    if(const Dvd* p = dynamic_cast<const Dvd*>(v)){
        std::string s2 = p->get_production();
        return search_string(s2, s1);
    }
    return false;
    */
}

SearchLength::SearchLength(unsigned int length): length_(length){}

bool SearchLength::operator()(Entertainment*& v) const{
    EntInfoVisitor visitor;
    v->accept(visitor);
    return visitor.get_length() <= length_;
    /*
    if(const Dvd* p = dynamic_cast<const Dvd*>(v)) return p->get_length() <= length_;
    return false;
    */
}

SearchEpisodes::SearchEpisodes(unsigned int episodes): episodes_(episodes){}

bool SearchEpisodes::operator()(Entertainment*& v) const{
    EntInfoVisitor visitor;
    v->accept(visitor);
    return visitor.get_episodes() <= episodes_;
    /*
    if(const Series* p = dynamic_cast<const Series*>(v)) return p->get_episodes() <= episodes_;
    return false;
    */
}

SearchCompany::SearchCompany(const std::string& s):s1(s){}

bool SearchCompany::operator()(Entertainment*& v) const{
    EntInfoVisitor visitor;
    v->accept(visitor);
    std::string s2 = visitor.get_company();
    return search_string(s2, s1);
    /*
    if(const Videogame* p = dynamic_cast<const Videogame*>(v)){
        std::string s2 = p->get_company();
        return search_string(s2, s1);
    }
    return false;
    */
}

SearchPegi::SearchPegi(unsigned int pegi): pegi_(pegi){}

bool SearchPegi::operator()(Entertainment*& v) const{
    EntInfoVisitor visitor;
    v->accept(visitor);
    return visitor.get_pegi() <= pegi_;
    /*
    if(const Videogame* p = dynamic_cast<const Videogame*>(v)) return p->get_pegi() <= pegi_;
    return false; 
    */
}
