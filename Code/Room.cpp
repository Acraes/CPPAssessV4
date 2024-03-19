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

String Room::getDescription() const 
{
    return descript;


}

//Note, forgot that i made the description part in Room.h, goddamn it, didn't even need this.
void Room::setDescription(const String& _descript) 
{
    descript = _descript;
}

