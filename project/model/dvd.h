#ifndef DVD_H
#define DVD_H

#include "entertainment.h"

class Dvd: public Entertainment{
public:
    Dvd(std::string name, std::string image, std::string description, unsigned int quantity,
        std::string production, unsigned int length);
    std::string get_production() const;
    void set_producrion(std::string production);
    unsigned int get_length() const;
    void set_length(unsigned int length);
    virtual void accept(EntVisitor& visitor);
private:
    std::string production_;
    unsigned int length_;
};

#endif // DVD_H
