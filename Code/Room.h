
#include "String.h"
#include <map>

class Room
{
public:


    Room(const String& _name, const String& _descript);



    void addExit(const String& dir, Room* room);
    Room* getExit(const String& dir) const;

    String getName() const;


    String getDescription() const;
    void setDescription(const String& descript);


private:
    String name;
    String descript;
    std::map<String, Room*> exits;
};