#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "String.h"
#include "Player.h"
#include "Room.h"


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

void gameOver()
{
	system("CLS");

	String gameOverStr;
	String gameOverStr2;
	gameOverStr.Append("You died.");
	gameOverStr.WriteToConsole();
	std::cout << "" << std::endl;
	gameOverStr2.Append("Game Over.");
	gameOverStr2.WriteToConsole();
	
	
}



//Just main 
int main()
{
	Player player;



	String str1;
	String str2;
	String inputStr;
	String temp;
	String str1Test;
	String inpCmd;
	String nameStr1;
	String nameStr2;

	String continueInput;
	


	String beginStr1;
	String beginStr2;
	String beginStrOption1;
	String beginStrOption2;
	String choiceStr1;

	String room2Str1;
	String room2Str2;
	String room2StrOption1;
	String room2StrOption2;
	String choiceStr2;



	String roomName1;
	String roomName2;
	String roomName3;
	String roomName4;
	String roomName5;



	roomName1.Prepend("First room");
	roomName2.Prepend("Second room");
	roomName3.Prepend("Third room");
	roomName4.Prepend("Fourth room");
	roomName5.Prepend("Fifth room");

	Room* room1 = new Room(roomName1, "Room Description: Starting Room, there isn't anything in the room.");
	Room* room2 = new Room(roomName2, "Room Description: Enemy Room, there is an enemy infront of you.");
	Room* room3 = new Room(roomName3, "Room Description: Reward Room, there is a scroll with the instructions on a spell.");
	Room* room4 = new Room(roomName4, "Room Description: Enemy Room, Another enemy is infront of you.");
	Room* room5 = new Room(roomName5, "Room Description: You've just left the dungeon! Congrats!");



	room1->addExit("north", room2);
	room2->addExit("north", room3);
	room3->addExit("north", room4);
	room4->addExit("north", room5);

	room2->addExit("south", room1);
	room3->addExit("south", room2);
	room4->addExit("south", room3);


	Room* currentRoom = room1;

	while (true)
	{


		if (currentRoom == room1)
		{
			String room1DescriptStr = room1->getDescription();
			room1DescriptStr.WriteToConsole();




			nameStr1.Prepend("What is your Character's name?: ");
			nameStr1.WriteToConsole();
			inpCmd.ReadFromConsole();
			std::cout << "" << std::endl;
			Player player(inpCmd);
			std::cout << "Player's name: " << player.GetName().CStr() << std::endl;

			std::cout << "" << std::endl;
			beginStr1.Append("You've fallen into a dungeon!");
			beginStr1.WriteToConsole();
			std::cout << "" << std::endl;


			beginStr2.Append("What will you do?");
			beginStr2.WriteToConsole();

			std::cout << "" << std::endl;

			beginStrOption1.Append("1: Sit down, do nothing.");
			beginStrOption1.WriteToConsole();
			std::cout << "" << std::endl;
			beginStrOption2.Append("2: Head out of the north room Exit.");
			beginStrOption2.WriteToConsole();

			choiceStr1.ReadFromConsole();
			if (choiceStr1 == "North" || choiceStr1 == "2" || choiceStr1 == "Leave")
			{
					
				Room* nextRoom = currentRoom->getExit("north");
				if (nextRoom != nullptr)
				{
					currentRoom = nextRoom;
					String LeftRoom1;
					LeftRoom1.Append("You have left the first room.");
					LeftRoom1.WriteToConsole();
				}

				else
				{
					std::cout << "Well, messed up." << std::endl;
				}
			}
			if (choiceStr1 == "Sit down" || choiceStr1 == "1")
			{
				String DoingNothing;
				DoingNothing.Append("You sit down doing nothing, Is this really the time?!");
				DoingNothing.WriteToConsole();
				std::cout << "" << std::endl;

				String beginStr1Alternate;
				beginStr1Alternate.Append("Now, Once again, What will you do?: ");
				beginStr1Alternate.WriteToConsole();

				String OnlyChoice1;
				String onlyChoiceInput1;
				OnlyChoice1.Append("1. Leave the room");
				OnlyChoice1.WriteToConsole();

				onlyChoiceInput1.ReadFromConsole();
				if (onlyChoiceInput1 == "1" || onlyChoiceInput1 == "Leave the room")
				{
					Room* nextRoom = currentRoom->getExit("north");
					if (nextRoom != nullptr)
					{
						currentRoom = nextRoom;
						String LeftRoom1;
						LeftRoom1.Append("You have left the first room.");
						LeftRoom1.WriteToConsole();
					}
				}
				else
				{
					std::cout << "God Damnit" << std::endl;
				}
			}
		}

		if (currentRoom == room2)
		{
			String room2Str = room2->getDescription();
			room2Str.WriteToConsole();
			std::cout << "" << std::endl;

			
			room2Str1.Append("A Monster has it's back to you, what will you do?");
			room2Str1.WriteToConsole();
			std::cout << "" << std::endl;

			room2StrOption1.Append("1. Try Sneak around it to enter the next room");
			room2StrOption1.WriteToConsole();
			std::cout << "" << std::endl;
			room2StrOption2.Append("2. Attack the monster");
			room2StrOption2.WriteToConsole();
			std::cout << "" << std::endl;


			choiceStr2.ReadFromConsole();
			if (choiceStr2 == "Sneak around" || choiceStr2 == "1")
			{
				
				String DeathOutcome1;

				DeathOutcome1.Append("The monster hears you walk, turns around and attacks you, you died unable to put up a fight.");
				DeathOutcome1.WriteToConsole();
				continueInput.ReadFromConsole();
				gameOver();
			
				
				break;
				
			}
			if (choiceStr2 == "Attack" || choiceStr2 == "2")
			{
				String strOutcome1;
				strOutcome1.Append("You successfully surprise and kill the monster, it drops 2 items.");
				strOutcome1.WriteToConsole();
				std::cout << "" << std::endl;
				std::cout << "" << std::endl;
				String dropsStr;
				dropsStr.Append("The monster dropped a Magic scroll with the spell 'Fireball' on it, and a great axe");
				dropsStr.WriteToConsole();
				std::cout << "" << std::endl;


				String room2Out1Opt1;
				String room2Out1Opt2;
				room2Out1Opt1.Append("1. Learn the magic spell 'Fireball'");
				room2Out1Opt1.WriteToConsole();
				std::cout << "" << std::endl;
				room2Out1Opt2.Append("2. Equip the Great axe.");
				room2Out1Opt2.WriteToConsole();

				String room2Choice2;
				room2Choice2.ReadFromConsole();
				if (room2Choice2 == "1" || room2Choice2 == "Learn Fireball")
				{
					player.LearnSpell("FireBall");
					if (player.HasSpell("FireBall") == true)
					{
						std::cout << "It working lad" << std::endl;
					}
					else
					{
						std::cout << "Not working >:(" << std::endl;
					}
				}

			}
			
		}







		if (currentRoom == room5)
		{
			String finStr = room5->getDescription();

			finStr.WriteToConsole();
			break;
		}
	}




	/* 	 std::ofstream testFile("Test.txt", std::ios::app);


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
	/* str1Test.Append("Hello World");

	if (str1.EqualTo(str1Test))
	{
		testFile << "Append/Prepend: Pass" << std::endl;
	}
	else
	{
		testFile << "Append/Prepend: Fail" << std::endl;
	}

	str1.WriteToConsole();
	std::cout << "" << std::endl; */




#pragma endregion
	//str1.ToLower();
	//str1.ToUpper();

#pragma region
/*
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
	if (testFile.is_open())
	{
		testFile << "CharacterAt() Test: Pass" << std::endl;
	}


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
		testFile << "'" << substr1.CStr() << "'" << " Successfully found at: " << index1;
		testFile << " || Find() Test: Pass" << std::endl;
	}
	else {
		std::cout << "Substring '" << substr1.CStr() << " not found in the string." << std::endl;
		testFile << "'" << substr1.CStr() << "'" << " Wasn't found in string1";
		testFile << " || Find() Test: Fail" << std::endl;
	}

	if (index2 != String::notFound) {
		std::cout << "Substring '" << substr2.CStr() << "' found at index: " << index2 << std::endl;
		testFile << "'" << substr2.CStr() << "'" << " Successfully found at: " << index2;
		testFile << " || Find() Test: Fail" << std::endl;
	}
	else {
		std::cout << "Substring '" << substr2.CStr() << "' not found in the string." << std::endl;
		testFile << "'" << substr2.CStr() << "'" << " Wasn't found in string2";
		testFile << " || Find() Test: Pass" << std::endl;
	}
	///This is the result output
#pragma endregion

	std::cout << "Input Key: ";
	///ReadFromConsole taking whatever input is... Inputted into the console and then WriteToConsole writing the value to check it works.
	inputStr.ReadFromConsole();
	std::cout << "Key Inputted: ";
	inputStr.WriteToConsole();

	///I am having a bit of hard time figuring out how to even test this, like i can confirm it has been and continues to work via the
	///inputStr.ReadFromConsole();
	/// std::cout << "Key Inputted: ";
	/// inputStr.WriteToConsole();
	/// but i don't know how to "Check" the result and input it into the text file without entirely changing it or complicating it far more than needed.
	/// Just gonna put this here for now, i might not even need to do all this..
	if (testFile.is_open())
	{
		testFile << "ReadFromConsole()/WriteToConsole() Test: Pass" << std::endl;
	}



	testFile << " " << std::endl;
	testFile.close();
 */

	delete room1;
	delete room2;
	delete room3;
	delete room4;
	delete room5;



	return 0;
}


