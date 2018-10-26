
//Spencer Grace
//COSC 2030
#include <iostream>
#include <algorithm> 
#include"DayArrayFuctions.h"
#include"WeekArrayFunctions.h"


using std::scientific;
using std::cout;
using std::cin;
using std::endl;



int main()
{


	
	bool complete = false;

	char userState;				//used to take user input
	double fullArray[100];				//used for universal array for all numbers inputed
	double week1Array[7];				//first weeks array, keeps track of how many numbers belong to what part of the univeral array
	double week2Array[7];				//second array
	int max_size = 99;				//used to dynamically change the array size
	int week = 1;
	int tempday = 1;
	int state = 0;
	int day = 0;

	int index = 0;
	int weekindex = 0;
	int weekContInd = 0;				//used for allocation

	double* listPointer;				//used to point to the full array for dynamic allocation
	double* weekPointer;				//used to point to the correct week

	arrayDay dayArray;
	arrayWeek weekArray;



	listPointer = fullArray;				//initial allocation
	weekPointer = week1Array;

	while (complete == false)
	{
	
		if (day == 14)				//breaks out of the loop
		{

			break;
		}

		double data = 0;

		for (day = 0; day <= 14; day++)				//for all 13 days plus a extra for breaking out of the loop
		{
			if (day == 14) 
			{
				complete = true;
				break;
			}

			bool pressed = false;
			while (pressed == false)				//tests if a keyletter is typed, moves to next day
			{
				
				
				
				cout << "Please enter your Data for Day " << tempday  <<", Week " << week << ":"<< endl;
				cin >> data;
				if (data > 0) 				//checks if input is greater than 0, i.e valid
				{
					listPointer[index] = data;				//adds data
					if (index == max_size) 
					{
						double* newArr = new double[max_size + 100];				//this function dynamically increases the array size if it gets to that point
						for (int index = max_size; index >= 0; index-- ) 
						{
							newArr[index] = fullArray[index];

						}


						listPointer = newArr;									//points to new array
						max_size = max_size + 100;									
					}

					
					weekContInd++;
					index++;
					
					}
		
				cout << "Type 'N' if you would like to move to next day, Type 'D' for a summary from the current day, Type 'W' for a summary of the entire week so far, Type any other character to add another value" <<endl; 
				cin >> userState;
				if (userState == 'n' || userState == 'N')									//tests for next input
				{
					weekPointer[weekindex] = weekContInd;
					weekContInd = 0;
					pressed = true;
					weekindex++;
					tempday++;

					if (weekindex == 7)
					{
						weekPointer = week2Array;
						week = 2;
						tempday = 1;
						state = 1;
					}



				}
				else if (userState == 'd' || userState == 'D')									//tests for day summary input
				{
					
					weekPointer[weekindex] = weekContInd;
					cout << "-----------" << "SUMMARY FOR DAY: " << tempday << "-----------"<< endl;
					cout << "SUM OF DAY " << tempday << ": " << dayArray.daySum(listPointer, weekPointer, (tempday - 1)) << endl;
					cout << "MAX OF DAY " << tempday << ": " << dayArray.dayMax(listPointer, weekPointer, (tempday - 1)) << endl;
					cout << "MIN OF DAY " << tempday << ": " << dayArray.dayMin(listPointer, weekPointer, (tempday - 1)) << endl;
					cout << "COUNT OF DAY " << tempday << ": " << dayArray.dayCount(weekPointer, (tempday - 1)) << endl;
				}
				else if (userState == 'W' || userState == 'w') 								//tests for week summary input
				{
					if (state == 1) 
					{
						cout << "-----------" << "SUMMARY FOR WEEKS: " << week - state << " - " << week << "-----------" << endl;
						cout << "SUM OF WEEKS " << week - state << " - " << week <<": " << weekArray.weekSum(listPointer) << endl;
						cout << "MAX OF WEEKS " << week - state << " - " << week <<": " << weekArray.weekMax(listPointer) << endl;
						cout << "MIN OF WEEKS " << week - state << " - " << week<<": " << weekArray.weekMin(listPointer) << endl;
						cout << "COUNT OF WEEKS " << week - state << " - " << week <<": " << weekArray.weekCount(listPointer) << endl;
					}
					else
					{

						cout << "-----------" << "SUMMARY FOR WEEK: " << week << "-----------" << endl;
						cout << "SUM OF WEEK " << week << ": " << weekArray.weekSum(listPointer) << endl;
						cout << "MAX OF WEEK " << week << ": " << weekArray.weekMax(listPointer) << endl;
						cout << "MIN OF WEEK " << week << ": " << weekArray.weekMin(listPointer) << endl;
						cout << "COUNT OF WEEK " << week << ": " << weekArray.weekCount(listPointer) << endl;
					}
				}

			}



				
		}

		

	}
	
}






/*
void arrayFix(double oldarr[], int index, int max_size, double* ptr)
{

	if (index == max_size)
	{
		double* newArr = new double[max_size + 10];
		for (int index = max_size; index <= 0; index--)
		{
			newArr[index] = oldarr[index];

		}
		ptr = newArr;
		delete[] oldarr;
	}

	return;
}

*/
/*

bool complete = false;
char nState;

while (complete == false)
{
int day = 0;
double data = 0;

for (day = 0; day <= 13; day++)
{
bool pressed = false;
while (pressed == false)
{

cout << "Insert your Data for day " << day + 1 << ". Please enter " << endl;
cin >> data;
cout << "are you done?";
cin >> nState;
if (nState == 'n' || nState == 'N')
{
pressed = true;

}
}

}


*/


/*

int* newArr = new int[new_size];
std::copy(oldArr, oldArr + std::min(old_size, new_size), newArr);
delete[] oldArr;
oldArr = newArr;

*/