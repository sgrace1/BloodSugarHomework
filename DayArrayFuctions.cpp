//Spencer Grace
#include<iostream>
#include"DayArrayFuctions.h"
#include<stdlib.h>


double arrayDay::daySum(double tarray[], double weeksArray[7], int day)
{

	int takenDayBegin = day;									//finds where to begin counting			
	int allPrevDays = 0;									//needed to know where in the array to start the math
	int allPostDays = 0;									//used for 0th day i.e day 1
	int index = 0;
	int dayIndex = weeksArray[day];									//used for looping


	while (index < takenDayBegin)									//this function finds all the previous days in the loop by adding them all up
	{
		if (day == 0)
		{
			allPrevDays = 0;
			break;
		}
		allPrevDays = allPrevDays + weeksArray[index];
		index++;
	}
	allPostDays = weeksArray[index + 1];
	if (day == 0)
	{
		allPostDays = weeksArray[1];
	}

	if (allPostDays < 0) 
	{
		allPostDays = 0;
	}


	double sum = 0;
	int count = 0;
	while (tarray[count] > 0 && allPrevDays > 0)						//finds sum by itorating though all valid parts of the fullarray and finding the sum for that speciifc part
	{

		if (count >= allPrevDays)
		{
			for (dayIndex; dayIndex > 0; dayIndex--)
			{
				sum = sum + tarray[count];
				count++;
			}
		}
		count++;
		
	}

	while (allPrevDays == 0)							//for 0th case it just itorats a set number of time from the front
	{
		int temp = weeksArray[0];
		for (int i = 0; i < temp; i++) 
		{
			int tarraytemp = tarray[i];
			sum = sum + tarraytemp;
		}
		allPrevDays = 1;
	}




	return sum;

}

double arrayDay::dayMin(double tarray[], double weeksArray[7], int day)
{
	int takenDayBegin = day;									//finds where to begin counting		
	int allPrevDays = 0;									//needed to know where in the array to start the math
	int allPostDays = 0;								//used for 0th day i.e day 1
	int index = 0;									
	int dayIndex = weeksArray[day];


	while (index < takenDayBegin)					//same process as above for finding looping values
	{
		if (day == 0)
		{
			allPrevDays = 0;
			break;
		}
		allPrevDays = allPrevDays + weeksArray[index];
		index++;
	}
	allPostDays = weeksArray[index + 1];
	if (day == 0)
	{
		allPostDays = weeksArray[1];
	}

	if (allPostDays < 0)
	{
		allPostDays = 0;
	}



	double min = tarray[allPrevDays];			//using the values found from the math above the minimum is found
	int count = 0;
	while (tarray[count] > 0 && allPrevDays > 0)
	{
		if (count >= allPrevDays)
		{
			for (dayIndex; dayIndex > 0; dayIndex--)
			{
				if (tarray[count] < min)			//checks if the value is smaller then the min variable. If it is it is reassigned as the smallest variable
				{
					min = tarray[count];
				}
				count++;
			}
			
		}
		count++;
	}

	while (allPrevDays == 0)				//0th case exception
	{
		int temp = weeksArray[0];
		for (int i = 0; i < temp; i++)
		{
			if (tarray[i] < min)
			{
				min = tarray[i];
			}
		}
		allPrevDays = 1;
	}

	return min;
}

double arrayDay::dayMax(double tarray[], double weeksArray[7], int day)
{
	int takenDayBegin = day;									//finds where to begin counting		
	int allPrevDays = 0;									//needed to know where in the array to start the math
	int allPostDays = 0;								//used for 0th day i.e day 1
	int index = 0;
	int dayIndex = weeksArray[day];


	while (index < takenDayBegin)
	{
		if (day == 0)
		{
			allPrevDays = 0;
			break;
		}
		allPrevDays = allPrevDays + weeksArray[index];
		index++;
	}
	allPostDays = weeksArray[index + 1];
	if (day == 0)
	{
		allPostDays = weeksArray[1];
	}

	if (allPostDays < 0)
	{
		allPostDays = 0;
	}



	double max = tarray[allPrevDays];
	int count = 0;
	while (tarray[count] > 0 && allPrevDays > 0)						//using the values found from the math above the max is found
	{
		if (count >= allPrevDays)
		{
			for (dayIndex; dayIndex > 0; dayIndex--)
			{
				if (tarray[count] > max)				//checks if the value is smaller then the max variable. If it is it is reassigned as the largest variable
				{
					max = tarray[count];
				}
				count++;
			}
		}
		count++;

	}
		while (allPrevDays == 0)				//0th case exception
		{
			int temp = weeksArray[0];
			for (int i = 0; i < temp; i++)
			{
				if (tarray[i] > max)
				{
					max = tarray[i];
				}
			}
			allPrevDays = 1;
		}

	
	return max;
}

int arrayDay::dayCount(double weeksArray[7], int day)
{
	int count = weeksArray[day];						//returns the number of items at a specific point
	return count;
}


