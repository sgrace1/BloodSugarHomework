//Spencer Grace
//COSC 2030

#include<iostream>
#include"WeekArrayFunctions.h"

using namespace std;

double arrayWeek::weekSum(double tarray[])
{
	double sum = 0;
	int count = 0;
	while (tarray[count] > 0)				//iterates through main array and keeps adding itself to the next array value
	{
		sum = sum + tarray[count];
		count++;
	}
	return sum;
}

double arrayWeek::weekMin(double tarray[])
{
	double min = tarray[0];
	int count = 0;
	while (tarray[count] > 0)
	{
		if (tarray[count] < min)					//compares the min to the next value in an array. if its smaller it reassigns itself to it
		{
			min = tarray[count];
		}
		count++;
	}
	return min;
}

double arrayWeek::weekMax(double tarray[])
{
	double max = tarray[0];
	int count = 0;
	while (tarray[count] > 0)					//compares the max to the next value in an array. if its larger it reassigns itself to it
	{
		if (tarray[count] > max)
		{
			max = tarray[count];
		}
		count++;
	}
	return max;
}

int arrayWeek::weekCount(double tarray[])
{
	int count = 0;
	while (tarray[count] > 0)					//does an easy count of all numbers in the array
	{
		count++;
	}
	return count;
}
