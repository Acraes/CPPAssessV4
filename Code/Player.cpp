#include "Player.h"





Player::Player()
{

}

Player::Player(const String& _name) : name(_name), numSpells(0)
{

}

Player::~Player()
{
    for (int i = 0; i < numSpells; ++i)
    {

    }
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

void Player::LearnSpell(const String& spell)
{
    if (numSpells < maxSpells)
    {
        spellList[numSpells++] = spell;
    }
}

bool Player::HasSpell(const String& spell) const
{
    for (int i = 0; i < numSpells; ++i)
    {
        if (spellList[i] == spell)
        {
            return true;
        }
    }
    return false;
}

