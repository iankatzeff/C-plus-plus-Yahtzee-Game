#ifndef YAHTZEE_HPP
#define YAHTZEE_HPP
void quicksort(int array[], int size);
int one(int array[], int size);
int two(int array[], int size);
int three(int array[], int size);
int four(int array[], int size);
int five(int array[], int size);
int six(int array[], int size);
int threeofakind(int array[], int size);
int fourofakind(int array[], int size);
int fullhouse(int array[], int size);
int smallstraight(int array[], int size);
int largestraight(int array[], int size);
int yahtzee(int array[], int size);
int chance(int array[], int size);

#endif

//Prototype for char-based selection which is experimenting errors
/*std::std::cout << "\nDo you want to roll again? ";
		std::cin.ignore();
		getline(std::cin, reroll);
		while (reroll[0] != 'Y' && reroll[0] != 'y' && reroll[0] != 'N' && reroll[0] != 'n')
		{
			std::cout << "Please enter Y for yes or N for no. ";
			getline(std::cin, reroll);
		}
		if (reroll[0] == 'Y' or reroll[0] == 'y')
		{
			std::cout << "Which numbers do you want to reroll?\n";
			for (int i = 0; i < dice; i++)
			{
				std::cout << "Reroll: " << combination[i] << "? ";
				std::cin >> whichone[i];
				while (reroll[0] != 'Y' && reroll[0] != 'y' && reroll[0] != 'N' && reroll[0] != 'n')
				{
					std::cout << "Please enter Y for yes or N for no. ";
					getline(std::cin, whichone[i]);
				}
			}
			for (int i = 0; i < dice; i++)
			{
				if (reroll[0] == 'Y' or reroll[0] == 'y')
				{
					combination[i] = rand() % 6 + 1;
				}
				std::cout << combination[i] << " ";
			}
			std::cout << "\nDo you want to roll again? ";
			std::getline(std::cin, reroll);
			while (reroll[0] != 'Y' && reroll[0] != 'y' && reroll[0] != 'N' && reroll[0] != 'n')
			{
				std::cout << "Please enter Y for yes or N for no. ";
				std::getline(std::cin, reroll);
			}
			if (reroll[0] == 'Y' or reroll[0] == 'y')
			{
				std::cout << "Which numbers do you want to reroll?\n";
				for (int i = 0; i < dice; i++)
				{
					std::cout << "Reroll: " << combination[i] << "? ";
					std::cin >> whichone[i];
					while (reroll[0] != 'Y' && reroll[0] != 'y' && reroll[0] != 'N' && reroll[0] != 'n')
					{
						std::cout << "Please enter Y for yes or N for no. ";
						getline(std::cin, whichone[i]);
					}
				}
				for (int i = 0; i < dice; i++)
				{
					if (whichone[0][i] == 'Y' or whichone[0][i] == 'y')
					{
						combination[i] = rand() % 6 + 1;
					}
					std::cout << combination[i] << " ";
				}
			}
		}
		}*/
