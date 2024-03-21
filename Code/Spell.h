#pragma once
#include "String.h"



class Spell
{
public:
    Spell(const String& _name, const String& _descript);

    String GetName() const;
    String GetDescription() const;
    bool IsLearned() const;
    void Learn();

private:
    String name;
    String descript;
    bool learned;

};