#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//The main code that runs
int main()
{
	//the variables that the while loops use to see if they should run
	bool gameDone = false;
	bool playAgain = true;
	//this while loop is used for when the player wants to play again or if they are done
	while (gameDone == false)
	{
		//This chunk asks the player if they want to play
		string play;
		cout << "Agent, are you ready to recive the codes? \n (Y/N)" << endl;
		cout << ">";
		cin >> play;
		if (play == "Y")
		{
			//continues the game
			playAgain = true;
		}
		else if (play == "N")
		{
			//ends the game
			playAgain = false;
			gameDone = true;
		}
		else
		{
			//asks the question agin until they answer Y or N
			playAgain = false;
		}
		//the code where all the game is working
		while (playAgain == true)
		{
			//this makes the game run three times each time it is played
			for (int i = 0; i < 3; i++)
			{
				//counter for the player to know what turn they are on
				cout << "You are on turn " << i + 1 << " of 3" << endl;
				enum fields { word, hint, fields };
				//below is a list of the words that get scambled and their hints
				const int wordTotal = 10;
				const string words[wordTotal][fields] =
				{
					{ "oddjob", "goldeneye" },
					{ "mask", "majora's" },
					{ "knife", "stabby stabby" },
					{ "rifle", "point n' shooty" },
					{ "ugly", "the good, the bad, and the" },
					{ "dollars", "a fistful of" },
					{ "whatsituya", "what his first name" },
					{ "smitty-yeger-man-jensen", "#1" },
					{ "moscow", "enemy base" },
					{ "soviet", "a mistake" }
				};
				// this code decides which word will print and makes sure it has the right hint
				int randWord = (rand() % wordTotal);
				string theWord = words[randWord][word];
				string theHint = words[randWord][hint];
				string coded = theWord;
				string guess;
				//this codes scrambels the words
				int length = coded.size();
				for (int j = 0; j < length; ++j)
				{
					int index1 = (rand() % length);
					int index2 = (rand() % length);
					char temp = coded[index1];
					coded[index1] = coded[index2];
					coded[index2] = temp;
				}
				//this asks for the players answer
				cout << "Unscramble the word:" << coded << endl;
				cout << ">";
				//this is ensureing that the player has the option to stop the game
				playAgain = false;
				//this reads what the players guess is
				cin >> guess;
				//this decides what to do based on what the user typed
				while (guess != theWord)
				{
					//this will give the player a hint
					if (guess == "hint")
					{
						cout << theHint << endl;
					}
					// this is for when the player gets it right
					else if (guess == theWord)
					{
						cout << "CORRECT." << endl;
						cout << "Excellent work agent, you've cracked the code." << endl;
					}
					// this is for when the player gets it wrong
					else
					{
						cout << "That is incorrect" << endl;
					}
					//this will ask the player again what they think the word is
					cout << ">";
					cin >> guess;
				}
			}

		}
	}
	//pauses the code so the user can grasp what is happening
	system("pause");
}

