#include <iostream>
#include <string>
#include <vector>
#include "yahtzee.hpp"


int main()
{
	srand(time(0));
	const int dice = 5;
	std::vector <int> alreadydone;
	int combination[dice];
	static int turns = 0;
	int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0, yatzy = 0;
	int threek = 0, fourk = 0, fullh = 0, sstraight = 0, lstraight = 0, chancee = 0;
	int reroll = 1;
	int numericalbonus = 0;
	static int points;
	int choice;
	bool taken = 0;
	int whichone[dice];
	std::cout << "Welcome to Yahtzee! Hope you have fun!\nPress 0 for no and any other number for yes.\n\n";
	do
	{
		std::cout << "Scorecard:\n"
			<< "-------------------------\n"
			<< "1.  Ones:            " << ones << "\n"
			<< "2.  Twos:            " << twos << "\n"
			<< "3.  Threes:          " << threes << "\n"
			<< "4.  Fours:           " << fours << "\n"
			<< "5.  Fives:           " << fives << "\n"
			<< "6.  Sixes:           " << sixes << "\n"
			<< "-------------------------\n"
			<< "Bonus + 35: " << ones + twos + threes + fours + fives + sixes << "/63\n"
			<< "-------------------------\n"
			<< "7.  Three of a Kind: " << threek << "\n"
			<< "8.  Four of a Kind:  " << fourk << "\n"
			<< "9.  Full House:      " << fullh << "\n"
			<< "10. Small Straight:  " << sstraight << "\n"
			<< "11. Large Straight:  " << lstraight << "\n"
			<< "12. Yahtzee:         " << yatzy << "\n"
			<< "13. Chance:          " << chancee << "\n"
			<< "-------------------------\n"
			<< "Total Points: " << points << std::endl;
		for (int i = 0; i < dice; i++)
		{
			whichone[i] = 1;
			combination[i] = 1;
		}
		std::cout << "-------------------------------------------------\nCombo: ";
		for (int i = 0; i < dice; i++)
		{
			combination[i] = rand() % 6 + 1;
			std::cout << combination[i] << " ";
		}
		std::cout << "\nDo you want to roll again? ";
		std::cin >> reroll;
		if (reroll != 0 and reroll != 1)
		{
			reroll = 1;
		}
		if (reroll == 1)
		{
			std::cout << "Which numbers do you want to reroll?\n";
			for (int i = 0; i < dice; i++)
			{
				std::cout << "Reroll: " << combination[i] << "? ";
				std::cin >> whichone[i];
				if (whichone[i] != 0 and whichone[i] != 1)
				{
					whichone[i] = 1;
				}
			}
			for (int i = 0; i < dice; i++)
			{
				if (whichone[i] == 1)
				{
					combination[i] = rand() % 6 + 1;
				}
				std::cout << combination[i] << " ";
			}
			std::cout << "\nDo you want to roll again? ";
			std::cin >> reroll;
			if (reroll != 0 and reroll != 1)
			{
				reroll = 1;
			}
			if (reroll == 1)
			{
				std::cout << "Which numbers do you want to reroll?\n";
				for (int i = 0; i < dice; i++)
				{
					std::cout << "Reroll: " << combination[i] << "? ";
					std::cin >> whichone[i];
					if (whichone[i] != 0 and whichone[i] != 1)
					{
						whichone[i] = 1;
					}
				}
				for (int i = 0; i < dice; i++)
				{
					if (whichone[i] == 1)
					{
						combination[i] = rand() % 6 + 1;
					}
					
				}
			}
		}
		for (int i = 0; i < dice; i++)
		{
			std::cout << combination[i] << " ";
		}

		std::cout << "\nWhich choice are you making? ";
		std::cin >> choice;
		while (choice < 0 or choice > 13)
		{
			std::cout << "Enter a number between 0-13: ";
			std::cin >> choice;
		}
		
		do // Making sure the play isn't already taken or outside of bounds
		{
			int alreadytaken = 0;
			
			for (int blob : alreadydone)
			{

				if (((choice == blob) and (yatzy != 50 or yahtzee(combination, dice) != 50)) or (choice < 1 or choice > 13))
				{
					alreadytaken++;
				}

			}
			if (alreadytaken > 0)
			{
				std::cout << "Choice not available. Pick a different number: ";
				std::cin >> choice;
				taken = 1;
			}
			else
			{
				taken = 0;
			}
		} while (taken);
		switch (choice) // Where all the different possible points happen
		{
		case 1:
			
			alreadydone.push_back(1);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				ones = 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;	
			}
			else
			{
				turns++;
				points = points + one(combination, dice);
				ones = one(combination, dice);
				std::cout << "-------------------------------------------------\nOnes: Plus "
					<< one(combination, dice) << "\nScore: " << points << std::endl;
			}
			break;
		case 2:
			
			alreadydone.push_back(2);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				twos = 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;
			}
			else
			{
				turns++;
				points = points + two(combination, dice);
				twos = two(combination, dice);
				std::cout << "-------------------------------------------------\nTwos: Plus "
					<< two(combination, dice) << "\nScore: " << points << std::endl;	
			}
			break;
		case 3:
			
			alreadydone.push_back(3);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				threes = 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;
			}
			else
			{
				turns++;
				points = points + three(combination, dice);
				threes = three(combination, dice);
				std::cout << "-------------------------------------------------\nThrees: Plus "
					<< three(combination, dice) << "\nScore: " << points << std::endl;	
			}
			break;
		case 4:
			
			alreadydone.push_back(4);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				fours = 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;
			}
			else
			{
				turns++;
				points = points + four(combination, dice);
				fours = four(combination, dice);
				std::cout << "-------------------------------------------------\nFours: Plus "
					<< four(combination, dice) << "\nScore: " << points << std::endl;	
			}
			break;
		case 5:
			
			alreadydone.push_back(5);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				fives = 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;
			}
			else
			{
				turns++;
				points = points + five(combination, dice);
				fives = five(combination, dice);
				std::cout << "-------------------------------------------------\nFives: Plus "
					<< five(combination, dice) << "\nScore: " << points << std::endl;
			
			}
			break;
		case 6:
			
			alreadydone.push_back(6);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				sixes = 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;
			}
			else
			{
				turns++;
				points = points + six(combination, dice);
				sixes = six(combination, dice);
				std::cout << "-------------------------------------------------\nSixes: Plus "
					<< six(combination, dice) << "\nScore: " << points << std::endl;
			}
			break;
		case 7:
			
			alreadydone.push_back(7);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				threek = 50;
				points = points + 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;
			}
			else
			{
				turns++;
				points = points + threeofakind(combination, dice);
				threek = threeofakind(combination, dice);
				std::cout << "-------------------------------------------------\nThree of a Kind: Plus "
					<< threeofakind(combination, dice) << "\nScore: " << points << std::endl;
			}
			break;
		case 8:
			
			alreadydone.push_back(8);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				fourk = 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;
				
			}
			else
			{
				turns++;
				points = points + fourofakind(combination, dice);
				fourk  = fourofakind(combination, dice);
				std::cout << "-------------------------------------------------\nFour of a Kind: Plus "
					<< fourofakind(combination, dice) << "\nScore: " << points << std::endl;
				
			}
			break;
		case 9:
			
			alreadydone.push_back(9);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				fullh = 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;
				
			}
			else
			{
				turns++;
				points = points + fullhouse(combination, dice);
				fullh = fullhouse(combination, dice);
				std::cout << "-------------------------------------------------\nFull House: Plus "
					<< fullhouse(combination, dice) << "\nScore: " << points << std::endl;
				
			}
			break;
		case 10:
			
			alreadydone.push_back(10);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				sstraight = 50;
				points = points + 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;
				
			}
			else
			{
				turns++;
				points = points + smallstraight(combination, dice);
				sstraight = smallstraight(combination, dice);
				std::cout << "-------------------------------------------------\nSmall Straight: Plus "
					<< smallstraight(combination, dice) << "\nScore: " << points << std::endl;
				
			}
			break;
		case 11:
			
			
			alreadydone.push_back(11);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				lstraight = 50;
				points = points + 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus " 
					<< yatzy << "\nScore: " << points << std::endl;
			
			}
			else
			{
				turns++;
				points = points + largestraight(combination, dice);
				lstraight = largestraight(combination, dice);
				std::cout << "-------------------------------------------------\nLarge Straight: Plus " 
					<< largestraight(combination, dice) << "\nScore: " << points << std::endl;
				
			}
			break;
		case 12:
			alreadydone.push_back(12);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus "
					<< yatzy << "\nScore: " << points << std::endl;

			}
			else
			{
				turns++;
				points = points + yahtzee(combination, dice);
				yatzy = yahtzee(combination, dice);
				std::cout << "-------------------------------------------------\nYAHTZEE! Plus "
				<< yahtzee(combination, dice) << "\nScore: " << points << std::endl;
			}
			break;
		case 13:
			
			alreadydone.push_back(13);
			if (yatzy >= 50 and yahtzee(combination, dice) == 50)
			{
				points = points + 50;
				chancee = 50;
				std::cout << "-------------------------------------------------\nANOTHER YAHTZEE! Plus " 
					<< yatzy << "\nScore: " << points << std::endl;
				
			}
			else
			{
				turns++;
				points = points + chance(combination, dice);
				chancee = chance(combination, dice);
				std::cout << "-------------------------------------------------\nChance: Plus " 
					<< chance(combination, dice) << "\nScore: " << points << std::endl;
			}
			break;
		}
		if ((ones + twos + threes + fours + fives + sixes) >= 63 and numericalbonus == 0)
		{
			std::cout << points << " + 35\n";
			points = points + 35;
			numericalbonus++;
		}
		
	} while (turns < 13);
	
	std::cout << "\n-----------------------------------------------\nThat's a wrap!\nFinal score: " << points;
	return 0;
}
