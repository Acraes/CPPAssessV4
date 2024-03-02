#include <iostream>
#include "String.h"

//#include <string>

// I assume you want me to use the custom class String.h and not <string>

//Wish i could just std::cout << "Hello World!" << endl;
/*
int DisplayString()
{
	String str1;

	str1.Find("Hello World");

	str1.Append("Hello");

	str1.Append(" ");

	str1.Append("World");

	str1.WriteToConsole();

	return 0;
}
*/

int main()
{
	String str1;
	String str2;
	String _InputStr;
	//str1.Find("Hello World");

	//str1.Append("Hello");
	
	//str1.WriteToConsole();

	//str1.WriteToConsole();
	//return 0;
	//std::cout << str1.Length() << std::endl;

	//str1.Append(" ");

	//std::cout << str1.Length() << std::endl;


	//str1.WriteToConsole();
	//return 0;

	str1.Append(" ");

	str1.Append("World");

	//str1.ToLower();
	//str1.ToUpper();

	str1.Prepend("Hello");

	//str1.ToLower();
	//str1.ToUpper();

	str2.Append(" ");

	str2.Append("World");

	str2.Prepend("Different");


	
	if (str1.EqualTo(str2))
	{
		std::cout << "str1 is equal to str2" << std::endl;
	}
	else
	{
		std::cout << "str1 is not equal to str2" << std::endl;
	}

	size_t IndexCheck = 4;
	
	char CharacterCheck = str1.CharacterAt(IndexCheck);

	
	std::cout << " " << std::endl;
	str1.WriteToConsole();


	// Test the Find function
	String substring1("Hello");
	String substring2("Earth");

	size_t index1 = str1.Find(substring1);
	size_t index2 = str1.Find(substring2);

	

	if (index1 != String::notFound) {
		std::cout << "Substring '" << substring1.CStr() << "' found at index: " << index1 << std::endl;
	}
	else {
		std::cout << "Substring '" << substring1.CStr() << "' not found in the string." << std::endl;
	}

	if (index2 != String::notFound) {
		std::cout << "Substring '" << substring2.CStr() << "' found at index: " << index2 << std::endl;
	}
	else {
		std::cout << "Substring '" << substring2.CStr() << "' not found in the string." << std::endl;
	}

	



	_InputStr.ReadFromConsole();

	_InputStr.WriteToConsole();

	return 0;
}


