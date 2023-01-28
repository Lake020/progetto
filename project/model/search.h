#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include "cafeitem.h"
#include "food.h"
#include "drink.h"
#include "entertainment.h"
#include "manga.h"
#include "dvd.h"
#include "series.h"
#include "videogame.h"

bool search_string(const std::string& s1, const std::string& s2);

class SearchNameMenu{
public:
    SearchNameMenu(const std::string& s);
    bool operator()(CafeItem*& v) const;
private:
    std::string s1;
};

class SearchPrice{
public:
    SearchPrice(double price);
    bool operator()(CafeItem*& v) const;
private:
    double price_;
};

class SearchGlutenFree{
public:
    SearchGlutenFree(bool val = true);
    bool operator()(CafeItem*& v) const;
private:
    bool value;
};

class SearchNameLibrary{
public:
    SearchNameLibrary(const std::string& s);
    bool operator()(Entertainment*& v) const;
private:
    std::string s1;
};

class SearchQuantity{
public:
    SearchQuantity(unsigned int quantity);
    bool operator()(Entertainment*& v) const;
private:
    unsigned int quantity_;
};

class SearchDescription{
public:
    SearchDescription(const std::string& s);
    bool operator()(Entertainment*& v) const;
private:
    std::string s1;
};

#endif
