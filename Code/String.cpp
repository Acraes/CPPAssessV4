#include <iostream>
#include "String.h"
///Side note, I use variables with the '_' in a lot of these but basically not at all in the main program document.
///I do this cause the original String.h given had those and i didn't really change it much cause i was lazy.
///OCD kicks in and i decided to just keep it consistent between String.cpp and String.h
///Forgot about this detail when working on the Main Document, at this point, far too late to change unless absolutely necessary. -_-
#pragma String
String::String()
{
    ///Default Constructor
    data = new char[1];
    data[0] = '\0';
    size = 0; /// size set to 0 indicating a empty string.

    ///Initalizes empty string by allocating memory for one character and setting it to the null character.


}

String::String(const char* _str)
{


    ///Calculates the size of the input string by iterating through it until it reaches null.
    ///Memory allocated for the string 'data = new char[size + 1];' and copies it over.
    size = 0;
    while (_str[size] != '\0')
    {
        ++size;
    }

    data = new char[size + 1];
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = _str[i];
    }
    data[size] = '\0';
    ///Escape character set to null to ensure the string is deleted.
}
String::String(const String& _other)
{
    ///Copy Constructor
    ///Constructor creates a new string object by copying the content of another string object.
    ///Characters from the other strings are then copied over and the last character is set to the null character.
    size = _other.size;
    data = new char[size + 1];
    for (size_t i = 0; i < size; ++i)
    {
        data[i] = _other.data[i];
    }
    data[size] = '\0';
}


String::~String()
{
    ///Destructor
    delete[] data;
    ///Frees dynamically allocated memory when an object of the String class goes out of range or is deleted

}
#pragma endString
#pragma Check 
size_t String::Length() const
{
    ///Returns the length of the string, which is stored in the 'size' member variable.

    return size;


}

char& String::CharacterAt(size_t _index)
{
    ///Performs a check to ensure that the index is within bounds before accessing the character.
    ///if the Index is valid, it prints out the character at the specified index '_index' in the string.
    ///If the Index is invalid(Out of range/scope), prints error message and returns a null character.
    if (_index < size)
    {
        std::cout << "Character at Index " << _index << ": " << data[_index] << std::endl;
        return data[_index];
    }
    else
    {
        std::cerr << "This isn't meant to be displayed. Index went out of range." << std::endl;
        static char defaultCharacter = '\0';
        return defaultCharacter;
    }
}

const char& String::CharacterAt(size_t _index) const
{
    /// Overloaded version of CharacterAt function for const objects.
    ///Same as 'CharacterAt' function but doesn't print anything other than the error message and a reference to the character at the specified index for consts'.
    if (_index < size)
    {
        return data[_index];
    }
    else
    {
        std::cerr << "This isn't meant to be displayed. Index went out of range." << std::endl;
        const static char defaultCharacter = '\0';
        return defaultCharacter;
    }
}

bool String::EqualTo(const String& _other) const
{
    ///Appends another string to the current string.
    ///Then updates based on whether or not the new string is the same as the old string.
    ///Returns a true or false value depending on the outcome.

    if (size != _other.size)
    {
        return false;
    }

    for (size_t i = 0; i < size; ++i)
    {
        if (data[i] != _other.data[i])
        {
            return false;
        }
    }
    return true;
}

String& String::Append(const String& _str)
{
    ///Appends another string to the current string.
    ///Copies the characters from the current string and then from the appended string into the new memory.
    ///Updates the size and deallocates the old memory, assigning the new memory to 'data'.



    size_t newLength = size + _str.size;
    char* temp = new char[newLength + 1];

    for (size_t i = 0; i < size; ++i) {
        temp[i] = data[i];
    }

    for (size_t i = 0; i < _str.size; ++i) {
        temp[size + i] = _str.data[i];
    }

    temp[newLength] = '\0';

    delete[] data;
    data = temp;
    size = newLength;

    return *this;

    ///Update, redid it, had a issue where one of my Append/Prepend was changing into "=", more accurately replacing all characters for "=" meaning if i had Space in it, it would be "Hello=====World".
    ///Reason for this seems to be the memory being managed during the Append and Prepend methods, specifically the code above was to properly allocate and copy the characters of the original and the string being appended/prepended.









        //     size_t newLength = size + _str.size;
        // char* temp = new char[newLength + 1];

        // for (size_t i = 0; i < _str.size; ++i)
        // {
        //     temp[size + i] = _str.data[i];
        // }

        // temp[newLength] = '\0';

        // delete[] data;
        // data = temp;
        // size = newLength;

        // return *this;




        /*char* temp = new char[size + _str.size + 1];

        for (size_t i = 0; i < size; ++i)
        {
            temp[i] = data[i];
        }

        for (size_t i = 0; i < _str.size; ++i)
        {
            temp[size + i] = _str.data[i];
        }

        temp[size + _str.size] = '\0';

        delete[] data;

        data = temp;
        size += _str.size;

        return *this;*/
}


String& String::Prepend(const String& _str)
{
    ///Prepends another string to the current string.
    ///Copies the characters from the appended string and then from the current string into the new memory.
    ///Updates the size and deallocates the old memory, assigning the new memory to 'data'.


    size_t newLength = size + _str.size;
    char* temp = new char[newLength + 1];

    for (size_t i = 0; i < _str.size; ++i) {
        temp[i] = _str.data[i];
    }

    for (size_t i = 0; i < size; ++i) {
        temp[_str.size + i] = data[i];
    }

    temp[newLength] = '\0';

    delete[] data;
    data = temp;
    size = newLength;

    return *this;













    //     size_t newLength = size + _str.size;
    // char* temp = new char[newLength + 1];

    // for (size_t i = 0; i < _str.size; ++i)
    // {
    //     temp[i] = _str.data[i];
    // }

    // for (size_t i = 0; i < size; ++i)
    // {
    //     temp[_str.size + i] = data[i];
    // }

    // temp[newLength] = '\0';

    // delete[] data;
    // data = temp;
    // size = newLength;

    // return *this;



    //char* temp = new char[size + _str.size + 1];

    //for (size_t i = 0; i < _str.size; ++i)
    //{
    //    temp[i] = _str.data[i];
    //    //temp[i] = data[i];
    //}


    //for (size_t i = 0; i < size; ++i)
    //{
    //    temp[_str.size + i] = data[i];
    //}

    //temp[size + _str.size] = '\0';

    //delete[] data;
    //data = temp;
    //size = +_str.size;
    ////size += _str.size;

    //return *this;
}
#pragma endCheck

#pragma Alter 
const char* String::CStr() const
{
    ///Returns a pointer to the internal character array 'data' of the string.
    ///Allows external code to access the string representation of the 'String' object
    return data;
}

String& String::ToLower()
{
    ///Converts all upper case letters into their lowercase versions.
    ///Iterates through each character in the string and checks if it's a uppercase letter, then converts it if so.

    for (size_t i = 0; i < size; ++i)
    {
        if (data[i] >= 'A' && data[i] <= 'Z')
        {
            data[i] += ('a' - 'A');
        }
    }
    return *this;
}

String& String::ToUpper()
{
    ///Converts all lower case letters into their Uppercase versions.
    ///Iterates through each character in the string and checks if it's a lowercase letter, then converts it if so.
    for (size_t i = 0; i < size; ++i)
    {
        if (data[i] >= 'a' && data[i] <= 'z')
        {
            // Convert lowercase letter to uppercase
            data[i] = data[i] - 'a' + 'A';
        }
    }
    return *this;
}


size_t String::Find(const String& _str)
{
    ///Searches for the first occurrence of the substring within the string.
    ///Uses nested loops to compare Characters and when a match is found, returns the index of the starting position of the substring.
    ///If none is found, returns the const 'notFound' from the 'String' class.
    for (size_t i = 0; i <= size - _str.size; ++i)
    {
        bool match = true;
        for (size_t j = 0; j < _str.size; ++j)
        {
            if (data[i + j] != _str.data[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return i;
        }
    }
    return notFound;
}

size_t String::Find(size_t _startIndex, const String& _str)
{
    ///Overloaded version of the 'Find' function.
    ///Checks if _startIndex is within the valid range of the string.
    ///If yes, searches for the substring from teh specified index onward. Pretty much the same as the regular 'Find' function.
    ///Otherwise the same as the 'Find' Function
    if (_startIndex < size)
    {
        for (size_t i = _startIndex; i <= size - _str.size; ++i)
        {
            bool match = true;
            for (size_t j = 0; j < _str.size; ++j)
            {
                if (data[i + j] != _str.data[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return i;
            }
        }
    }
    return notFound;
}
#pragma endAlter

#pragma Console

String& String::ReadFromConsole()
{
    ///Gets the line of input from the console and stores it in 'buffer'.
    ///Existing data in the 'String' Object is deleted and the size is reset to 0.
    ///Calculates the size of the input until the null character.
    ///Null character added at the end and a reference to the modified 'String' object is returned.

    const size_t bufferSize = 256;
    char buffer[bufferSize];
    std::cin.getline(buffer, bufferSize);

    delete[] data;
    size = 0;

    while (buffer[size] != '\0')
    {
        ++size;
    }

    data = new char[size + 1];

    for (size_t i = 0; i < size; ++i)
    {
        data[i] = buffer[i];
    }

    data[size] = '\0';

    return *this;
}



String& String::WriteToConsole()
{
    ///Writes the contents of the 'String' Object to the console.
    std::cout << data;
    return *this;
}

#pragma endConsole


bool String::operator==(const String& other) const
{
    return EqualTo(other);
}

bool String::operator<(const String& other) const
{
    return strcmp(data, other.data) < 0;
}

bool String::operator>(const String& other) const
{
    return strcmp(data, other.data) > 0;
}


///Previously had some code here from when i was working on this a while ago i think, during the period of time when it hadn't been covered and i was looking for how to do this. 
/// (Didn't use ChatGPT or anything like that, just a bunch of code from different sources, with some things changed here and there).
/// Saw it and went, "Huh, that's weird." Deleted it and moved on to comment sections.

///EDIT, Found some code in String.h which the previous code here was for, so i must have found some code from a while ago that would fit it.
///ANYWAY, removed everything here and setup working stuff.