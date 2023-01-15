#ifndef SEARCH_HPP
#define SEARCH_HPP

#include "search.h"
#include <string>

template<class T>
SearchName<T>::SearchName(const std::string& s):s1(s){}

template<class T>
bool SearchName<T>::operator()(const T& v) const{ 
    std::string s2 = v->get_name();
    return search_string(s2, s1);
}

template<class T>
SearchPrice<T>::SearchPrice(double price): price_(price){}

template<class T>
bool SearchPrice<T>::operator()(const T& v) const{
    return v->get_price() <= price_;
}

template<class T>
SearchQuantity<T>::SearchQuantity(unsigned int quantity): quantity_(quantity){}

template<class T>
bool SearchQuantity<T>::operator()(const T& v) const{
    return v->get_quantity() <= quantity_;
}

template<class T>
SearchDescription<T>::SearchDescription(const std::string& s):s1(s){}

template<class T>
bool SearchDescription<T>::operator()(const T& v) const{ 
    std::string s2 = v->get_description();
    return search_string(s2, s1);
}

#endif