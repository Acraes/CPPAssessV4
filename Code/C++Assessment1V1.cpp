#include <iostream>
#include "String.h"
#include <fstream>
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
//Just main 
int main()
{
	
	String str1;
	String str2;
	String _InputStr;

	std::ofstream TestFile("Test.txt");
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
#pragma region
/// Append, to write a small bit of string at the back of the string. Since there isn't anything at this point it will just add them in.
	//str1.Append(" ");
	///Here it will add World behind the space, leaving " World"
	//str1.Append("World");

	//str1.ToLower();
	//str1.ToUpper();
	///Prepend then inputs a small section into the string like Append but instead at the front. With this making it "Hello World"
	/*str1.Append("Hello");
	str1.Append(" ");
	str1.Append("World");*/



	str1.Append(" ");
	str1.Append("World");
	str1.Prepend("Hello");


	if (TestFile.is_open())
	{
		TestFile << str1.CStr() << " Append and Prepend Successful." << std::endl;

		TestFile.close();

	}



	str1.WriteToConsole();
	std::cout << "" << std::endl;




#pragma endregion
	//str1.ToLower();
	//str1.ToUpper();

#pragma region
///Same thing mentioned above but on the second string
	std::cout << "Comparison: " << std::endl;
	str2.Append(" ");

	str2.Append("World");

	str2.Prepend("Different");
#pragma endregion

	/// Checking if String 1 and String 2 are the same, we know it isn't but this verifies it.
	if (str1.EqualTo(str2))
	{
		std::cout << "str1 is equal to str2" << std::endl;
	}
	else
	{
		std::cout << "str1 is not equal to str2" << std::endl;
	}
#pragma region 
	///this section is to check what character is at the Index listed. In this case 4, so "o". 0 = H, 1 = e, 2 = l e.t.c.
	std::cout << "CharacterAt Check: " << std::endl;
	size_t IndexCheck = 9;

	char CharacterCheck = str1.CharacterAt(IndexCheck);

	

	std::cout << " " << std::endl;
	str1.WriteToConsole();
#pragma endregion

#pragma region
	/// This section of code was to test the "Find()".
	String substr1("Hello");
	String substr2("Earth");

	size_t index1 = str1.Find(substr1);
	size_t index2 = str1.Find(substr2);

	///Made some strings and indexes to scan the original str1 for the line of text
	std::cout << "SubString inside String check: " << std::endl;
	if (index1 != String::notFound) {
		std::cout << "Substring '" << substr1.CStr() << "' found at index: " << index1 << std::endl;
		TestFile << substr1.CStr() << " Successfully found at: " << index1 << std::endl;
		TestFile << "Find() Test: Pass" << std::endl;
	}
	else {
		std::cout << "Substring '" << substr1.CStr() << "' not found in the string." << std::endl;
		TestFile << substr1.CStr() << " Wasn't found in string1" << std::endl;
		TestFile << "Find() Test: Fail" << std::endl;
	}

	if (index2 != String::notFound) {
		std::cout << "Substring '" << substr2.CStr() << "' found at index: " << index2 << std::endl;
		TestFile << substr2.CStr() << " Successfully found at: " << index2 << std::endl;
		TestFile << "Find() Test: Fail" << std::endl;
	}
	else {
		std::cout << "Substring '" << substr2.CStr() << "' not found in the string." << std::endl;
		TestFile << substr2.CStr() << " Wasn't found in string1";
		TestFile << "Find() Test: Pass" << std::endl;
	}
	///This is the result output
#pragma endregion

	std::cout << "Input Key: ";
	///ReadFromConsole taking whatever input is... Inputted into the console and then WriteToConsole writing the value to check it works.
	_InputStr.ReadFromConsole();
	std::cout << "Key Inputted: ";
	_InputStr.WriteToConsole();


	TestFile.close();

	return 0;
}


