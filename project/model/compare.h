#ifndef COMPARE_H
#define COMPARE_H

#include <string>
#include "cafeitem.h"
#include "entertainment.h"

class CompareNameMenu{
public:
    bool operator()(CafeItem*& v1, CafeItem*& v2) const;
};

class ComparePrice{
public:
    bool operator()(CafeItem*& v1, CafeItem*& v2) const;
};

class CompareNameLibrary{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
};

class CompareQuantity{
public:
    bool operator()(Entertainment*& v1, Entertainment*& v2) const;
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

#endif // COMPARE_H
