
#include "String.h"


class Spell
{
public:
    Spell(const String& _name) : name(_name)
    {

    }

private:
    String name;


};

class Item 
{
    public:
        Item(const String& _name, const String& _descript) : name(_name), descript(_descript), equipped(false)
        {

        }

        String GetName() const 
        { 
            return name;     
        }
        
        String GetDescription() const
        {
            return descript;
        }

        bool IsEquipped() const
        {
            return equipped;
        }

        void Equip()
        {
            equipped = true;
        }

        void UnEquip()
        {
            equipped = false;
        }


    private:
        String name;
        String descript;
        bool equipped;   
};



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


private:
    String name;
    static const int maxSpells = 3;
    String spellList[maxSpells];
    int numSpells;

};

 

















