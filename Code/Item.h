#include "String.h"


class Item 
{
    public:

        Item();

        Item(const String& _name, const String& _descript);

        String GetName() const;
        
        String GetDescription() const;

        bool IsEquipped() const;
        void Equip();
        void UnEquip();
        


    private:
        String name;
        String descript;
        bool equipped;   
};
