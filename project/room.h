#ifndef ROOM_H
#define ROOM_H


class Room{
public:
    Room(unsigned int id, bool available);
    unsigned int get_id() const;
    void set_id(unsigned int id);
    bool is_available() const;
    void set_available(bool available);

private:
    unsigned int id_;
    bool available_;

};

#endif // ROOM_H
