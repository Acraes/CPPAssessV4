#include <iostream>
#include "String.h"


String::String()
{
	//Default
    data = new char[1];
    data[0] = '\0';
    size = 0;



}

String::String(const char* _str)
{
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
}

String::String(const String& _other) 
{
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
    delete[] data;


}

size_t String::Length() const
{
    
    
    return size;


}

char& String::CharacterAt(size_t _index)
{
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
    char* temp = new char[size + _str.size + 1];

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

    return *this;
}


String& String::Prepend(const String& _str)
{
    char* temp = new char[size + _str.size + 1];

    for (size_t i = 0; i < _str.size; ++i)
    {
        temp[i] = _str.data[i];
        //temp[i] = data[i];
    }


    for (size_t i = 0; i < size; ++i)
    {
        temp[_str.size + i] = data[i];
    }

    temp[size + _str.size] = '\0';

    delete[] data;
    data = temp;
    size =+ _str.size;
    //size += _str.size;

    return *this;
}

const char* String::CStr() const
{
    return data;
}

String& String::ToLower()
{
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


String& String::ReadFromConsole()
{
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
    std::cout << data;
    return *this;
}



bool String::operator==(const String& _other) 
{
    return EqualTo(_other);
}

bool String::operator!=(const String& _other) {
    return !EqualTo(_other);
}

String& String::operator=(const String& _str) {
    if (this != &_str) {
        delete[] data;
        size = _str.size;
        data = new char[size + 1];
        for (size_t i = 0; i < size; ++i) {
            data[i] = _str.data[i];
        }
        data[size] = '\0';
    }
    return *this;
}

char& String::operator[](size_t _index) {
    return CharacterAt(_index);
}

const char& String::operator[](size_t _index) const {
    return CharacterAt(_index);
}
