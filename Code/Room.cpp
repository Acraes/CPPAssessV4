#include "Room.h"


Room::Room(const String& _name, const String& _descript) : name(_name), descript(_descript)
{

}

void Room::addExit(const String& dir, Room* room)
{
    exits[dir] = room;
}

Room* Room::getExit(const String& dir) const
{
    auto iteration = exits.find(dir);
    if (iteration != exits.end())
    {
        return iteration -> second;
    }
    return nullptr;

}




