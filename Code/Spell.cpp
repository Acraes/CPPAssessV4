#include "Spell.h"


Spell::Spell(const String& _name, const String& _descript) : name(_name), descript(_descript), learned(false)
{

}



String Spell::GetName() const
{
    return name;
}

String Spell::GetDescription() const
{
    return descript;
}

bool Spell::IsLearned() const
{
    return learned;
}

void Spell::Learn()
{
    learned = true;
}
