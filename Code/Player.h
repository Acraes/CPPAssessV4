
#include "String.h"
#include "Item.h"

// class Spell
// {
// public:
//     Spell(const String& _name) : name(_name)
//     {

//     }

// private:
//     String name;


// };





class Player
{
public:
    Player();
    Player(const String& _name);
    ~Player();

    String GetName() const;


    void LearnSpell(const String& spellName);
    bool HasSpell(const String& spellName) const;
    bool FindSpell(const String& spell) const;

    void EquipItem(Item& item);
    void UnEquipItem(Item& item);
    bool HasItemEquipped(const Item& item) const;


private:
    String name;
    static const int maxSpells = 3;
    String spellList[maxSpells];
    int numSpells;

};
































