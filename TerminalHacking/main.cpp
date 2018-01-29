// main.cpp: Defines the entry point for the console application.
//
#include "stdafx.h"
#include "WordList.h"
#include <windows.h>
#include <ctype.h>

const int wordLength = 5;
const int numberOfWords = 1;

int main()
{
	// Seed the random number generator with the current time,
	// to ensure different results each time the program is run
	srand(static_cast<unsigned int>(time(nullptr)));

	// Initialise word list
	WordList words(wordLength);

	// Choose secret word
	std::string secret = words.getRandomWord();

	// Create a set to hold the list of options
	std::set<std::string> options;

	// Put the secret word in the set
	options.insert(secret);

	// Fill the set with more words
	// Using a set for options guarantees that the elements are all different
	while (options.size() < numberOfWords)
	{
		std::string word = words.getRandomWord();
		options.insert(word);
	}

	// Display all words
	for each (std::string word in options)
	{
		std::cout << word << std::endl;
	}

	// TODO: implement the rest of the game


	
	
	std::string userInput;

	bool running = true;
	int attempts = 4;
	int notInList = 0;

	while (running)
	{
		std::cin >> userInput;

		//converts users input to uppercase
		for (int i = 0; i < userInput.size(); i++) 
		{
			userInput.at(i) = toupper(userInput.at(i));
		}

		//checks if user has chosen a word from the list.
		

		if (userInput == secret)
		{
			std::cout << "Password Accepted.";
		}

		else if (userInput != secret)
		{
			for each (std::string word in options)
			{
				if (userInput != word)
				{
					notInList += 1;
				}

				if (notInList == 15)
				{
					std::cout << "Invalid Word...";
					notInList = 0;
				}
			}
		}


		else if (attempts >= 0 && userInput != secret)
		{
			attempts -= 1;

			int wordLikeness = 0;

			for (char userCharacter : userInput)
			{
				for (char secretCharacter : secret)
				{
					if (userCharacter == secretCharacter)
					{
						wordLikeness += 1;
					}
				}
			}

			std::cout << "Entry denied. " << "Likeness=" << wordLikeness;
		}

		else
		{
			std::cout << "Terminal Locked. Password was: " << secret << ". Exiting...";

			Sleep(3000);

			return 0;
		}
	}

	return 0;
}

