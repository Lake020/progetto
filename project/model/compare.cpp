#include "compare.h"
#include "cafeinfovisitor.h"
#include "entinfovisitor.h"

bool CompareNameMenu::operator()(CafeItem*& v1, CafeItem*& v2) const{
    return v1->get_name() <= v2->get_name();
}

bool ComparePrice::operator()(CafeItem*& v1, CafeItem*& v2) const{
    return v1->get_price() <= v2->get_price();
}

bool CompareFormat::operator()(CafeItem*& v1, CafeItem*& v2) const{
    CafeInfoVisitor visitor1;
    CafeInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_format() <= visitor2.get_format();
}

bool CompareNameLibrary::operator()(Entertainment*& v1, Entertainment*& v2) const{
    return v1->get_name() <= v2->get_name();
}

bool CompareQuantity::operator()(Entertainment*& v1, Entertainment*& v2) const{
    return v1->get_quantity() <= v2->get_quantity();
}

bool CompareAuthor::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_author() <= visitor2.get_author();
}

bool ComparePages::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_pages() <= visitor2.get_pages();
}

bool CompareVolume::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_volume() <= visitor2.get_volume();
}

bool CompareTarget::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_target() <= visitor2.get_target();
}

bool CompareProduction::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_production() <= visitor2.get_production();
}

bool CompareLength::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_length() <= visitor2.get_length();
}

bool CompareEpisodes::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_episodes() <= visitor2.get_episodes();
}

bool CompareCompany::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_company() <= visitor2.get_company();
}

bool ComparePegi::operator()(Entertainment*& v1, Entertainment*& v2) const{
    EntInfoVisitor visitor1;
    EntInfoVisitor visitor2;
    v1->accept(visitor1);
    v2->accept(visitor2);
    return visitor1.get_pegi() <= visitor2.get_pegi();
}
