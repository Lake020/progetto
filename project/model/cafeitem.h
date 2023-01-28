#ifndef CAFEITEM_H
#define CAFEITEM_H

#include<string>
#include<iostream>

#include "cafevisitor.h"

class CafeItem{
    friend std::ostream& operator<<(std::ostream& os, const CafeItem& v);
public:
    CafeItem(std::string name, std::string image, double price);
    virtual ~CafeItem();
    std::string get_name() const;
    void set_name(std::string name);
    std::string get_image() const;
    void set_image(std::string image);
    virtual double get_price() const;
    void set_price(double price);
    bool operator<=(const CafeItem& x) const;
    virtual void accept(CafeVisitor& visitor) = 0;
private:
    std::string name_;
    std::string image_;
    double price_;
};

std::ostream& operator<<(std::ostream& os, const CafeItem& v);

#endif // CAFEITEM_H
