#ifndef VECTOR_H
#define VECTOR_H

#include<stdlib.h>

template <class T>
class Vector{
public:
    /*
    class iterator{
        friend class Vector<T>;
    public:
        iterator();
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        T& operator*() const;
        T* operator->() const;
        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;
    private:
        T* p_;
        iterator(T* p);
    };

    class const_iterator{
        friend class Vector<T>;
    public:
        const_iterator();
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const const_iterator& it) const;
        bool operator!=(const const_iterator& it) const;
    private:
        const T* p_;
        const_iterator(const T* p);
    };
    */

    Vector();
    Vector(const Vector& v);
    ~Vector();
    Vector& operator=(const Vector& x);
    /*
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    */
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

    /*
    template<class Iterator>
    Iterator find(Iterator first, Iterator last, const T& value) const;
    template<class Iterator, class Predicate>
    Iterator find_if(Iterator first, Iterator last, Predicate pred)) const;
    template<class Iterator, class Predicare>
    Iterator sort_by(Iterator first, Iterator last, Predicate pred) const;
    */

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
    template<class Predicate>
    size_t partion(size_t first, size_t last, Predicate pred);
    /*
    template<class Iterator, class Predicate>
    Iterator partion(Iterator first, Iterator last, Predicate pred);
    */

};

#include "vector.hpp"

#endif // VECTOR_H
