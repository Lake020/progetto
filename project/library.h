#ifndef LIBRARY_H
#define LIBRARY_H

#include "vector.h"
#include "entertainment.h"
#include "manga.h"
#include "dvd.h"
#include "series.h"
#include "videogame.h"

#include<iostream>

class Library{
    friend std::ostream& operator<<(std::ostream& os, const Library& v);
public:
    Library();
    ~Library();

    Entertainment& operator[](size_t i);
    const Entertainment& operator[](size_t i) const;

    void add(Entertainment* value);
    void remove(Entertainment* value);
    void remove(size_t index);
    void clear();

    size_t get_size() const;

    void sort();
    void sort_by_quantity();

    template<class Predicate>
    Library search(Predicate pred) const;
    
    Library search_by_name(const std::string& name) const;
    Library search_by_quantity(unsigned int quantity) const;
    Library search_by_description(const std::string& des) const;

    Library only_manga() const;
    void sort_by_author();
    void sort_by_pages();
    void sort_by_volume();
    void sort_by_target();
    Library search_by_author(const std::string& author) const;
    Library search_by_pages(unsigned int pages) const;
    Library search_by_volume(unsigned int volume) const;
    Library search_by_target(Target target) const;

    Library only_dvd() const;
    void sort_by_production();
    void sort_by_length();
    Library search_by_production(const std::string& production) const;
    Library search_by_length(unsigned int length) const;

    Library only_series() const;
    void sort_by_episodes();
    Library search_by_episodes(unsigned int episodes) const;

    Library only_videogame() const;
    void sort_by_company();
    void sort_by_pegi();
    Library search_by_company(const std::string& company) const;
    Library search_by_pegi(unsigned int pegi) const;

private:
    Vector<Entertainment*> items_;
};

std::ostream& operator<<(std::ostream& os, const Library& v);

template<class Predicate> Library Library::search(Predicate pred) const{
    Library results;
    for(size_t ind = 0; ind < get_size(); ind++){
        ind = items_.find_first_of(ind, get_size(), pred);
        if(ind < get_size()){
            results.add(items_[ind]);
        } 
    }
    return results;
}

#endif // LIBRARY_H
