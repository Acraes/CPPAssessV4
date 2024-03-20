#include "Item.h"



Item::Item(const String& _name, const String& _descript) : name(_name), descript(_descript), equipped(false)
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

bool Item::IsEquipped() const
{
    return equipped;
}

void Item::Equip()
{
    equipped = true;
}

void Item::UnEquip()
{
    equipped = false;
}