/* ------------------------------------------------------
Workshop 2 part 1
Name     : Harsh Vishnu Limbachiya
Email    : hvlimbachiya@myseneca.ca
studentId: 157295197
Filename : Car.h
date     : 27-01-2022
-----------------------------------------------------------*/

/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments*/

#ifndef CAR_H_
#define CAR_H_
#pragma once

namespace sdds
{
	//struct for type car 
	struct	Car
	{
		char  licensePlate[9]= "";
		char* makeAndModel;
		int time=0;
	};

	//Prints the message for programm
	void VBPLE_Title();
	//memory allocation 
	void initialize(int allocSize);
	//memory deallocation
	void deallocate(Car& C);
	//read the information of the car passing 
	bool read(Car& C);
	//print car in format 
	void print(const Car& C);
	//record cars
	void record(const Car& C);
	//end of the day 
	void endOfDay();
}

#endif // CAR_H_

