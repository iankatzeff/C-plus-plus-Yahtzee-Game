#include <iostream>
#include "yahtzee.hpp"

int partition(int aray[], int low, int high) {
	int pivot = aray[low];
	int i = low;
	int j = high;

	while (i < j) {
		while (aray[i] <= pivot && i <= high - 1) 
		{
			i++;
		}

		while (aray[j] > pivot && j >= low + 1) 
		{
			j--;
		}
		if (i < j)
		{
			std::swap(aray[i], aray[j]);
		}
	}
	std::swap(aray[low], aray[j]);
	return j;
}

void qs(int aray[], int low, int high) {
	if (low < high) {
		int pIndex = partition(aray, low, high);
		qs(aray, low, pIndex - 1);
		qs(aray, pIndex + 1, high);
	}
}

void quicksort(int array[], int size)
{
	qs(array, 0, size - 1);
}
int one(int array[], int size)
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == 1)
		{
			score++;
		}
	}
	return score;
}
int two(int array[], int size)
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == 2)
		{
			score = score + 2;
		}
	}
	return score;
}
int three(int array[], int size)
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == 3)
		{
			score = score + 3;
		}
	}
	return score;
}
int four(int array[], int size)
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == 4)
		{
			score = score + 4;
		}
	}
	return score;
}
int five(int array[], int size)
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == 5)
		{
			score = score + 5;
		}
	}
	return score;
}
int six(int array[], int size)
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == 6)
		{
			score = score + 6;
		}
	}
	return score;
}
int threeofakind(int aray[], int size)
{
	int score = 0;
	int count = 0;
	quicksort(aray, size);
	if (((aray[0] == aray[1]) + (aray[0] == aray[2]) + (aray[0] == aray[3]) + (aray[0] == aray[4])) >= 2 ||
		((aray[1] == aray[2]) + (aray[1] == aray[3]) + (aray[1] == aray[4])) >= 2 ||
		((aray[2] == aray[3]) + (aray[2] == aray[4])) >= 2)
		{
			for (int i = 0; i < size; i++)
			{
				score += aray[i];
			}
		}
	return score;
}
int fourofakind(int aray[], int size)
{
	int score = 0;
	int count = 0;
	quicksort(aray, size);
	if (((aray[0] == aray[1]) + (aray[0] == aray[2]) + (aray[0] == aray[3]) + (aray[0] == aray[4])) >= 3 ||
		((aray[1] == aray[2]) + (aray[1] == aray[3]) + (aray[1] == aray[4])) >= 3)
		{
			for (int i = 0; i < size; i++)
			{
				score += aray[i];
			}
		}
	return score;
}
int fullhouse(int aray[], int size)
{
	int score = 0;
	quicksort(aray, size);
	if (((aray[0] == aray[1] and aray[1] == aray[2]) && (aray[3] == aray[4])) || ((aray[0] == aray[1] && aray[2] == aray[3]) and (aray[3] == aray[4])))
	{
		score = 25;
	}
	return score;
}
int smallstraight(int aray[], int size)
{
	int score = 0;
	int count = 0;
	quicksort(aray, size);
	for (int i = 0; i < size - 1; i++)
	{
		if (aray[i] == (aray[i + 1] - 1))
		{
			count++;
		}
	}
	for (int i = 0; i < size - 1; i++)
	{
		if ((aray[i] == 4 and aray[i - 1] == 2) or (aray[i] == 5 and aray[i - 1] == 3))
		{
			count--;
		}
	}
	if (count >= 3)
	{
		score = 30;
	}
	return score;
}
int largestraight(int aray[], int size)
{
	int score = 0;
	int count = 0;
	quicksort(aray, size);
	for (int i = 0; i < size - 1; i++)
	{
		if (aray[i] == (aray[i + 1] - 1))
		{
			count++;
		}
	}
	if (count == 4)
	{
		score = 40;
	}
	return score;

}
int yahtzee(int array[], int size)
{
	int score = 0;
	int count = 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			count++;
		}
	}
	if (count == 4)
	{
		score = 50;
	}
	return score;
}
int chance(int array[], int size)
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		score += array[i];
	}
	return score;
}
