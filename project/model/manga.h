#ifndef MANGA_H
#define MANGA_H

#include "entertainment.h"

enum target {shounen, seinen, shojo, josei, none};
typedef enum target Target;

class Manga: public Entertainment{
    friend std::ostream& operator<<(std::ostream& os, const Manga& v);
public:
    Manga(std::string name, std::string image, std::string description, unsigned int quantity,
          std::string author, unsigned int pages, unsigned int volume, Target target);
    std::string get_author() const;
    void set_author(std::string author);
    unsigned int get_pages() const;
    void set_pages(unsigned int pages);
    unsigned int get_volume() const;
    void set_volume(unsigned int volume);
    Target get_target() const;
    void set_target(Target target);
    virtual void accept(EntVisitor& visitor);
private:
    std::string author_;
    unsigned int pages_;
    unsigned int volume_;
    Target target_;
};

std::ostream& operator<<(std::ostream& os, const Manga& v);

#endif // MANGA_H
