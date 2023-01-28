#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector.h"
#include <stdexcept>
#include <iostream>
#include <random>

/*
template<class T>
Vector<T>::iterator::iterator(): p_(nullptr), past_the_end_(false), pre_the_start_(false) {}

template<class T>
Vector<T>::iterator::iterator(T* p, bool pte, bool pts): p_(p), past_the_end_(pte), pre_the_start_(pts) {}

template<class T>
class Vector<T>::iterator& Vector<T>::iterator::operator++(){
    if(p_) p_ = p_ + sizeof(T);
    return *this;
}

template<class T>
class Vector<T>::iterator Vector<T>::iterator::operator++(int){
    iterator tmp(*this);

}

template<class T>
Vector<T>::const_iterator::const_iterator(): p_(nullptr), past_the_end_(false), pre_the_start_(false) {}

template<class T>
Vector<T>::const_iterator::const_iterator(const T* p, bool pte, bool pts): p_(p), past_the_end_(pte), pre_the_start_(pts) {}

template<class T>
class Vector<T>::const_iterator& Vector<T>::const_iterator::operator++(){
    if(p_) p_ = p_ + sizeof(T);
    return *this;
}
*/


template<class T>
Vector<T>::Vector(): ptr_(new T[1]), size_(0), capacity_(1){}

template<class T>
Vector<T>::Vector(const Vector& v): ptr_(new T[v.capacity_]), size_(v.size_), capacity_(v.capacity_){
    for(size_t i = 0; i < size_; i++) ptr_[i] = v[i];
}

template<class T>
Vector<T>::~Vector(){
    if(ptr_) delete[] ptr_;
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector& v){
    if(this != &v){
        delete[] ptr_;
        size_ = capacity_ = v.size_;
        if(v.size_ == 0){
            ptr_ = nullptr;
        }else{
            ptr_ = new T[v.size_];
            for(size_t i = 0; i < size_ ; i++) ptr_[i] = v[i];
        }
    }
    return *this;
}

/*
template<class T>
iterator Vector<T>::begin(){
    return iterator(ptr_);
}

template<class T>
const_iterator Vector<T>::begin() const{
    return const_iterator(ptr_);
}

template<class T>
iterator Vector<T>::end(){
    return iterator(ptr_[get_size()-1]);
}

template<class T>
const_iterator Vector<T>::end() const{
    return const_iterator(ptr_[get_size() - 1]);
}

*/

template<class T>
size_t Vector<T>::get_size() const{
    return size_;
}

template<class T>
size_t Vector<T>::get_capacity() const{
    return capacity_;
}

template<class T>
bool Vector<T>::empty() const{
    if(size_ == 0) return true;
    return false;
}

template<class T>
void Vector<T>::reserve(size_t n){
    if(n <= capacity_) return;
    T* tmp = new T[n];
    for(unsigned int i = 0; i < size_; i++) tmp[i] = ptr_[i];
    delete[] ptr_;
    ptr_ = tmp;
    capacity_ = n;
}

template<class T>
T& Vector<T>::operator[](size_t i){
    return ptr_[i];
}

template<class T>
const T& Vector<T>::operator[](size_t i) const{
    return ptr_[i];
}

template<class T>
T& Vector<T>::at(size_t i){
    if(i >= size_) throw std::out_of_range("Out of range");
    return ptr_[i];
}

template<class T>
const T& Vector<T>::at(size_t i) const{
    if(i >= size_) throw std::out_of_range("Out of range");
    return ptr_[i];
}

template<class T>
T& Vector<T>::front(){
    return ptr_[0];
}

template<class T>
const T& Vector<T>::front() const{
    return ptr_[0];
}

template<class T>
T& Vector<T>::back(){
    return ptr_[size_ - 1];
}

template<class T>
const T& Vector<T>::back() const{
    return ptr_[size_ - 1];
}

template<class T>
void Vector<T>::push_back(const T& value){
    if(size_ == capacity_) reserve(2 * capacity_);
    ptr_[size_++] = value;
}

template<class T>
void Vector<T>::pop_back(){
    if(!empty()) --size_;
}

template<class T>
void Vector<T>::erase(size_t i){
    if(i < size_){
        for(size_t j = i; j < size_ - 1; j++){
            swap(ptr_[j], ptr_[j+1]);
        }
        pop_back();
    }
}

template<class T>
void Vector<T>::append(const Vector& v){
    if(v.get_size() != 0){
        T* aux = new T[get_size() + v.get_size()];
        for(size_t i = 0; i < get_size(); i++) aux[i] = ptr_[i];
        for(size_t i = 0; i < v.get_size(); i++) aux[get_size() + i] = v[i];
        size_ += v.get_size();
        capacity_ = size_;
        delete[] ptr_;
        ptr_ = aux;
    }
}

template<class T>
void Vector<T>::clear(){
    if(!empty()){
        delete[] ptr_;
        ptr_ = new T[1];
        size_ = 0;
        capacity_ = 1;
    }
}
template<class T>
size_t Vector<T>::find(size_t first, size_t last, const T& value) const{
    for(size_t i = first; i <= last; i++){
        if(ptr_[i] == value) return i;
    }
    return last;
}


template<class T>
template<class Predicate>
size_t Vector<T>::find_first_of(size_t first, size_t last, Predicate pred) const{
    for(size_t i = first; i < last; i++){
        if(pred(ptr_[i])) return i;
    }
    return last;
}

template<class T>
void Vector<T>::swap(T& a, T& b){
    T tmp(a);
    a = b;
    b = tmp;
}

template<class T>
template<class Predicate> void Vector<T>::sort_by(size_t first, size_t last, Predicate pred){

    // /*
    size_t i, j, min_idx;
    // One by one move boundary of
    // unsorted subarray
    for (i = first; i < last-1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < last; j++)
        if (pred(ptr_[j], ptr_[min_idx]))
            min_idx = j;

        // Swap the found minimum element
        // with the first element
        if(min_idx!=i)
            swap(ptr_[min_idx], ptr_[i]);
    }
    // */

     /*
    if(first < last){
        size_t q = partion(first, last, pred);
        sort_by(first, q-1, pred);
        sort_by(q + 1, last, pred);
    }
     */
}

/*
template<class T>
template<class Predicate> size_t Vector<T>::partion(size_t first, size_t last, Predicate pred){

    std::random_device r;
    std::uniform_int_distribution<int> distrib(first, last);
    size_t randpiv = distrib(r);
    swap(ptr_[last], ptr_[randpiv]);


    T pivot = ptr_[last];
    int i = first - 1;
    for(size_t j = first; j <= last-1; j++){
        if(pred(ptr_[j], pivot)){
            i++;
            swap(ptr_[j], ptr_[i]);
        }
    }
    swap(ptr_[i+1], ptr_[last]);
    return i+1;

}
*/
#endif
