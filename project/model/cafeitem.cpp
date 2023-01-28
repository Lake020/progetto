#include "cafeitem.h"

CafeItem::CafeItem(std::string name, std::string image, double price):
    name_(name), image_(image), price_(price){}

CafeItem::~CafeItem() {}

std::string CafeItem::get_name() const{
    return name_;
}

void CafeItem::set_name(std::string name){
    name_ = name;
}

std::string CafeItem::get_image() const{
    return image_;
}

void CafeItem::set_image(std::string image){
    image_ = image;
}

double CafeItem::get_price() const{
    return price_;
}

void CafeItem::set_price(double price){
    if(price>0) price_ = price;
    else price_ = 0.;
}

bool CafeItem::operator<=(const CafeItem& x) const{
    return name_ <= x.name_;
}

std::ostream& operator<<(std::ostream& os, const CafeItem& v){
    return os << "name: " << v.name_ << " image: " << v.image_ << " price: " << v.price_;
}
