#ifndef COMPARE_H
#define COMPARE_H

#include <string>
#include "cafeitem.h"
#include "entertainment.h"

template<class T>
class ComparePrice{
public:
    bool operator()(const T& v1, const T& v2) const;
};

template<class T>
class CompareName{
public:
    bool operator()(const T& v1, const T& v2) const;
};

template<class T>
class CompareQuantity{
public:
    bool operator()(const T& v1, const T& v2) const;
};

class CompareAuthor{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

class ComparePages{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

class CompareVolume{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

class CompareTarget{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

class CompareProduction{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

class CompareLength{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

class CompareEpisodes{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

class CompareCompany{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

class ComparePegi{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

#include "compare.hpp"
#endif // COMPARE_H
