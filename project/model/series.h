#ifndef SERIES_H
#define SERIES_H

#include "dvd.h"

class Series: public Dvd{
public:
    Series(std::string name, std::string image, std::string description, unsigned int quantity,
           std::string production, unsigned int length, unsigned int episodes);
    unsigned int get_episodes() const;
    void set_episodes(unsigned int episodes);
    virtual void accept(EntVisitor& visitor);
private:
    unsigned int episodes_;
};

#endif // SERIES_H
