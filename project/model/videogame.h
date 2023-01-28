#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "entertainment.h"

class Videogame: public Entertainment{
public:
    Videogame(std::string name, std::string image, std::string description, unsigned int quantity,
              std::string company, unsigned int pegi);
    std::string get_company() const;
    void set_company(std::string company);
    unsigned int get_pegi() const;
    void set_pegi(unsigned int pegi);
    virtual void accept(EntVisitor& visitor);
private:
    std::string company_;
    unsigned int pegi_;
};

#endif // VIDEOGAME_H
