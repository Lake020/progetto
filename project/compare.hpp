#ifndef COMPARE_HPP
#define COMPARE_HPP
#include "compare.h"

template<class T>
bool ComparePrice<T>::operator()(const T& v1, const T& v2) const{
    return v1->get_price() <= v2->get_price();
}

template<class T>
bool CompareName<T>::operator()(const T& v1, const T& v2) const{
    return v1->get_name() <= v2->get_name();
}

template<class T>
bool CompareQuantity<T>::operator()(const T& v1, const T& v2) const{
    return v1->get_quantity() <= v2->get_quantity();
}

#endif