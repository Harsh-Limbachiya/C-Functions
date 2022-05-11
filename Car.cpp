/* ------------------------------------------------------
//Workshop 2 part 1
//Name     : Harsh Vishnu Limbachiya
//Email    : hvlimbachiya@myseneca.ca
//studentId: 157295197
//Filename : Car.cpp
//date     : 27-01-2022
//-----------------------------------------------------------*/
//
///*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include "Car.h"
#include "cStrTools.h"
using namespace std;

namespace sdds
{
	Car* myCars = nullptr;
	int allocationSize = 0;
	int numOfCars = 0;
	int carArraySize = 0;
	//Prints the message for programm
	void VBPLE_Title()
	{
		cout << "Vehicle Border Passing Log Entry" << endl;
		cout << "Enter the data in the following format:" << endl;
		cout << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl;
		cout << "Exit the program by entering the following:" << endl;
		cout << "X,<ENTER>" << endl;
	}
	//Allocation 
	void initialize(int allocSize)
	{
		allocationSize = numOfCars = allocSize;
		numOfCars = 0;
		myCars = new Car[allocSize];

	}
	//deallocation 
	void deallocate(Car& C)
	{
		if (C.makeAndModel != nullptr)
		{
			delete[] C.makeAndModel;
		}
	}
	//read function to read input from console
	bool read(Car& C)
	{
		bool flag = 0;
		char time[10];
		char makeModel[60];
		read(makeModel, 60, ',');
		if (strCmp(makeModel, "X"))
		{
			flag = 1;
			//deallocate(C);
			C.makeAndModel = new char[strLen(makeModel) + 1];
			strCpy(C.makeAndModel, makeModel);
			read(C.licensePlate, 8, ',');
			read(time, 6);
			C.time = stoi(time);
		}
		return flag;
	}
	//print function to print result
	void print(const Car& C)
	{
		cout << C.time << ": " << C.makeAndModel << "," << C.licensePlate << endl;
	}
	//record function 
	void record(const Car& C)
	{
		if (numOfCars == carArraySize)
		{
			int i = 0;
			Car* tempArr = new Car[carArraySize + allocationSize];
			for (i = 0; (i = carArraySize) ; i++)
			{
				strCpy(tempArr[i].licensePlate, myCars[i].licensePlate);
				tempArr[i].time = myCars[i].time;
				tempArr[i].makeAndModel = myCars[i].makeAndModel;
			}
			carArraySize += allocationSize;
			delete[] myCars;
			myCars = tempArr;
			tempArr = nullptr;
		}
		//myCarList[numCars++] = C;
		strCpy(myCars[numOfCars].licensePlate, C.licensePlate);
		myCars[numOfCars].time = C.time;
		myCars[numOfCars].makeAndModel = C.makeAndModel;
		numOfCars++;
	}
	//endofDay function 
	void endOfDay()
	{
		int i = 0;
		for (i = 0; i < numOfCars; i++)
		{
			print(myCars[i]);
			deallocate(myCars[i]);
		}
		delete[] myCars;
	}

}

