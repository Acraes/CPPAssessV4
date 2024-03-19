
#include "String.h"


class Spell 
{

public:
    




};










class Player
{
    public:
        Player();
        Player(const String& _name);
        ~Player();
        
        String GetName() const;

        bool FindSpell(const String& spell) const;

    private:
        String name;
        static const int maxSpells = 3;
        String spellList[maxSpells];

};















