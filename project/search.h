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

template<class T>
class SearchName{
public:
    SearchName(const std::string& s);
    bool operator()(const T& v) const;
private:
    std::string s1;
};

template<class T>
class SearchPrice{
public:
    SearchPrice(double price);
    bool operator()(const T& v) const;
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

template<class T>
class SearchQuantity{
public:
    SearchQuantity(unsigned int quantity);
    bool operator()(const T& v) const;
private:
    unsigned int quantity_;
};

template<class T>
class SearchDescription{
public:
    SearchDescription(const std::string& s);
    bool operator()(const T& v) const;
private:
    std::string s1;
};

class SearchAuthor{
public:
    SearchAuthor(const std::string& s);
    bool operator()(Entertainment*& v) const;
private:
    std::string s1;
};

class SearchPages{
public:
    SearchPages(unsigned int pages);
    bool operator()(Entertainment*& v) const;
private:
    unsigned int pages_;
};

class SearchVolume{
public:
    SearchVolume(unsigned int volume);
    bool operator()(Entertainment*& v) const;
private:
    unsigned int volume_;
};

class SearchTarget{
public:
    SearchTarget(Target target);
    bool operator()(Entertainment*& v) const;
private:
    Target target_;
};

class SearchProduction{
public:
    SearchProduction(const std::string& s);
    bool operator()(Entertainment*& v) const;
private:
    std::string s1;
};

class SearchLength{
public:
    SearchLength(unsigned int length);
    bool operator()(Entertainment*& v) const;
private:
    unsigned int length_;
};

class SearchEpisodes{
public:
    SearchEpisodes(unsigned int episodes);
    bool operator()(Entertainment*& v) const;
private:
    unsigned int episodes_;
};

class SearchCompany{
public:
    SearchCompany(const std::string& s);
    bool operator()(Entertainment*& v) const;
private:
    std::string s1;
};

class SearchPegi{
public:
    SearchPegi(unsigned int pegi);
    bool operator()(Entertainment*& v) const;
private:
    unsigned int pegi_;
};

#include "search.hpp"
#endif