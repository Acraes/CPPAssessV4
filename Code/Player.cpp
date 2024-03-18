#include "Player.h"






Player::Player(const String& name) : name(name) {}

String Player::GetName() const
{
    return name;
}