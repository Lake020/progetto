#include "compare.h"
#include "cafeinfovisitor.h"
#include "entinfovisitor.h"

bool CompareAuthor::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_author() <= visitor2.get_author();
    /*
    if(const Manga* p1 = dynamic_cast<const Manga*>(v1)){
        if(const Manga* p2 = dynamic_cast<const Manga*>(v2)){
            return p1->get_author() <= p2->get_author();
        }
    }
    return false;
    */
}

bool ComparePages::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_pages() <= visitor2.get_pages();
    /*
    if(const Manga* p1 = dynamic_cast<const Manga*>(v1)){
        if(const Manga* p2 = dynamic_cast<const Manga*>(v2)){
            return p1->get_pages() <= p2->get_pages();
        }
    }
    return false;
    */
}

bool CompareVolume::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_volume() <= visitor2.get_volume();
    /*
    if(const Manga* p1 = dynamic_cast<const Manga*>(v1)){
        if(const Manga* p2 = dynamic_cast<const Manga*>(v2)){
            return p1->get_volume() <= p2->get_volume();
        }
    }
    return false;
    */
}

bool CompareTarget::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_target() <= visitor2.get_target();
    /*
    if(const Manga* p1 = dynamic_cast<const Manga*>(v1)){
        if(const Manga* p2 = dynamic_cast<const Manga*>(v2)){
            return p1->get_target() <= p2->get_target();
        }
    }
    return false;
    */
}

bool CompareProduction::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_production() <= visitor2.get_production();
    /*
    if(const Dvd* p1 = dynamic_cast<const Dvd*>(v1)){
        if(const Dvd* p2 = dynamic_cast<const Dvd*>(v2)){
            return p1->get_production() <= p2->get_production();
        }
    }
    return false;
    */
}

bool CompareLength::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_length() <= visitor2.get_length();
    /*
    if(const Dvd* p1 = dynamic_cast<const Dvd*>(v1)){
        if(const Dvd* p2 = dynamic_cast<const Dvd*>(v2)){
            return p1->get_length() <= p2->get_length();
        }
    }
    return false;
    */
}

bool CompareEpisodes::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_episodes() <= visitor2.get_episodes();
    /*
    if(const Series* p1 = dynamic_cast<const Series*>(v1)){
        if(const Series* p2 = dynamic_cast<const Series*>(v2)){
            return p1->get_episodes() <= p2->get_episodes();
        }
    }
    return false;
    */
}

bool CompareCompany::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_company() <= visitor2.get_company();
    /*
    if(const Videogame* p1 = dynamic_cast<const Videogame*>(v1)){
        if(const Videogame* p2 = dynamic_cast<const Videogame*>(v2)){
            return p1->get_company() <= p2->get_company();
        }
    }
    return false;
    */
}

bool ComparePegi::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_pegi() <= visitor2.get_pegi();
    /*
    if(const Videogame* p1 = dynamic_cast<const Videogame*>(v1)){
        if(const Videogame* p2 = dynamic_cast<const Videogame*>(v2)){
            return p1->get_pegi() <= p2->get_pegi();
        }
    }
    return false;
    */
}