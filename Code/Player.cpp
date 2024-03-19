#include "Player.h"





Player::Player()
{

}

Player::Player(const String& name) : name(name)
{

}

Player::~Player()
{

}
String Player::GetName() const
{
    return name;
}



bool Player::FindSpell(const String& spell) const
{
    for (int i = 0; i < maxSpells; ++i)
    {
        if (spellList[i] == spell)
        {
            return true;
        }
    }
    return false;
}