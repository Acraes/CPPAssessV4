#include <iostream>
#include "String.h"
#include <fstream>
#include <chrono>
#include <ctime>


///Took a while to figure out how to get the current time to be displayed,  purely for presentation in the Text file, got this from the internet.

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

	String time;

	String str1Test;

	

	std::ofstream testFile("Test.txt");
	

	///MY GOD, finding a way to do this was far harder than i feel it should have been, Once again, only doing this for looks and to be more accurate to the Example given on the C++ 3rd Assessment.
	auto ct = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	char buf[26];
	ctime_s(buf, sizeof(buf), &ct);

	if (testFile.is_open())
	{
		
		testFile << "Date: " << buf << std::endl;



		//testFile.close();
	}


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

	///This didn't really test if the Append and prepend were successful.
	// if (testFile.is_open())
	// {
	// 	testFile << str1.CStr() << " Append and Prepend Successful." << std::endl;

	// 	testFile.close();

	// }

	/*str1Test = "Hello World";

	str1Test.WriteToConsole();*/
	str1Test.Append("Hello World");

	if (str1.EqualTo(str1Test))
	{
		testFile << "Append and Prepend Successfully Operational." << std::endl;
	}
	else
	{
		testFile << "Append and Prepend Failure." << std::endl;
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
		testFile << substr1.CStr() << " Successfully found at: " << index1 << std::endl;
		testFile << "Find() Test: Pass" << std::endl;
	}
	else {
		std::cout << "Substring '" << substr1.CStr() << "' not found in the string." << std::endl;
		testFile << substr1.CStr() << " Wasn't found in string1" << std::endl;
		testFile << "Find() Test: Fail" << std::endl;
	}

	if (index2 != String::notFound) {
		std::cout << "Substring '" << substr2.CStr() << "' found at index: " << index2 << std::endl;
		testFile << substr2.CStr() << " Successfully found at: " << index2 << std::endl;
		testFile << "Find() Test: Fail" << std::endl;
	}
	else {
		std::cout << "Substring '" << substr2.CStr() << "' not found in the string." << std::endl;
		testFile << substr2.CStr() << " Wasn't found in string1";
		testFile << "Find() Test: Pass" << std::endl;
	}
	///This is the result output
#pragma endregion

	std::cout << "Input Key: ";
	///ReadFromConsole taking whatever input is... Inputted into the console and then WriteToConsole writing the value to check it works.
	_InputStr.ReadFromConsole();
	std::cout << "Key Inputted: ";
	_InputStr.WriteToConsole();


	testFile.close();

	return 0;
}


