#include "String.h"


class Item 
{
    public:

        Item();

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
