#ifndef VECTOR_H
#define VECTOR_H

#include<stdlib.h>

template <class T>
class Vector{
public:
    Vector();
    Vector(const Vector& v);
    ~Vector();
    Vector& operator=(const Vector& x);

    size_t get_size() const;
    size_t get_capacity() const;
    void reserve(size_t n);
    bool empty() const;

    T& operator[](size_t i);
    const T& operator[](size_t i) const;
    T& at(size_t n);
    const T& at(size_t n) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    void push_back(const T& value);
    void pop_back();
    void erase(size_t index);
    void append(const Vector& v);
    void clear();

    void swap(T& a, T& b);
    size_t find(size_t first, size_t last, const T& value) const;
    template<class Predicate>
    size_t find_first_of(size_t first, size_t last, Predicate pred) const;
    template<class Predicate>
    void sort_by(size_t first, size_t last, Predicate pred);

private:
    T* ptr_;
    size_t size_;
    size_t capacity_;

};

#include "vector.hpp"

#endif // VECTOR_H
