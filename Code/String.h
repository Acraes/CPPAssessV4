#pragma once
#ifndef CUSTOM_STRING_HEADER
#define CUSTOM_STRING_HEADER
#include <cstdint>
#ifndef SIZE_MAX
#define SIZE_MAX ((size_t)-1)
#endif

class String
{
	///Simple string class, has constructors, destructors, static constants in the first section of public
public:
	String();
	String(const char* _str);

	String(const String& _other);

	~String();
	static const size_t notFound = SIZE_MAX;
	



public:
	///Public member functions 
	/// 
	size_t Length() const;
	char& CharacterAt(size_t _index);
	const char& CharacterAt(size_t _index) const;

	bool EqualTo(const String& _other) const;
	bool operator==(const String& other) const;
	bool operator<(const String& other) const;
	bool operator>(const String& other) const;

	String& Append(const String& _str);
	String& Prepend(const String& _str);

	const char* CStr() const;

	String& ToLower();
	String& ToUpper();

	size_t Find(const String& _str);
	size_t Find(size_t _startIndex, const String& _str);

	String& Replace(const String& _find, const String& _replace);

	String& ReadFromConsole();
	String& WriteToConsole();

private:
	/// Private data members
	char* data;
	size_t size;

	/*int GetLength(const char* _str)
	{

		size = 0;
		while (_str[size] != '\0')
		{
			++size;
		}

		return size;

	}
	int GetLength(const String _str)
	{

		size = 0;
		while (_str.CStr()[size] != '\0')
		{
			++size;
		}

		return size;

	}*/
	//static const size_t notFound = SIZE_MAX;
};

#endif