#include "room.h"

Room::Room(unsigned int id, bool available):
    id_(id), available_(available){}

unsigned int Room::get_id() const{
    return id_;
}

void Room::set_id(unsigned int id){
    id_ = id;
}

bool Room::is_available() const{
    return available_;
}

void Room::set_available(bool available){
    available_ = available;
}
