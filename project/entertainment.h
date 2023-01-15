#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

#include<string>
#include <iostream>

#include "entvisitor.h"

class Entertainment{
    friend std::ostream& operator<<(std::ostream& os, const Entertainment& v);
public:
    Entertainment(std::string name, std::string image, std::string description, unsigned int quantity);
    virtual ~Entertainment();
    std::string get_name() const;
    void set_name(std::string name);
    std::string get_image() const;
    void set_image(std::string image);
    std::string get_description() const;
    void set_description(std::string);
    unsigned int  get_quantity() const;
    void set_quantity(unsigned int quantity);
    virtual void accept(EntVisitor& visitor) = 0;
private:
    std::string name_;
    std::string image_;
    std::string description_;
    unsigned int quantity_;
};

std::ostream& operator<<(std::ostream& os, const Entertainment& v);

#endif // ENTERTAINMENT_H
