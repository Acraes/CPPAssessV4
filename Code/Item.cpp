#include "Item.h"



Item::Item() 
{

}

Item::Item(const String& _name, const String& _descript) : name(_name), descript(_descript)
{

}

Item::~Item()
{

}

String Item::GetName() const
{
    return name;
}

String Item::GetDescription() const
{
    return descript;
}