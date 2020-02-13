/*
 * Program: assignment1.cpp
 * Author: Benjamin Shiffman
 * Date: 1/19/2020
 * Description: calculates gross income and taxes for salesperson
 * Input: salary, months worked, cost of car, cars sold, misconducts, tax year, state
 * Output: gross income, tax, remaining income
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	float monthlySalary;
	unsigned int months;
	float cost;
	unsigned int cars;
	unsigned int misconducts;
	unsigned int year;
	char state;
	float yearlySalary;
	float grossIncome;
	float annualSalary;
	float deduction;
	float profit;
	float avgPrice;
	float taxes;

	cout << "What is your monthly salary?" << endl;
	cin >> monthlySalary;

	cout << "How many months do you work in a year?" << endl;
	cin >> months;
	if (months > 12){cout << "Error: invalid input." << endl;}

	cout << "What is the cost of the car?" << endl;
	cin >> cost;

	cout << "How many cars did you sell?" << endl;
	cin >> cars;

	cout << "How many misconducts were observed?" << endl;
	cin >> misconducts;

	cout << "Which tax year is it, 2017 or 2018?" << endl;
	cin >> year;
	if (year != 2017 && year != 2018){cout << "Error: invalid input." << endl;}

	cout << "Which state are you in, A, B, or C?" << endl;
	cin >> state;
	if (state != 'A' && state != 'B' && state != 'C'){cout << "Error: invalid input." << endl;}

	annualSalary = monthlySalary * months;
	srand(time(NULL));
	avgPrice = cost*(1.05 + (rand()%6)/100);
	profit = cars * avgPrice;
	deduction = 0;
	if (misconducts > 0){deduction = 100*pow(2,misconducts-1);}
	grossIncome = annualSalary + 0.02*profit - deduction;
	cout << "Gross Income: $" << grossIncome << endl;

	if (year == 2017)
	{
		if (state == 'A'){taxes = 0.06*grossIncome;}
		else if (state == 'B')
		{
			if (grossIncome < 2000){taxes = 0;}
			else if (grossIncome >= 2000 && grossIncome <= 10000){taxes = 100;}
			else if (grossIncome > 10000){taxes = 0.1*grossIncome + 100;}
		}
		else if (state == 'C')
		{
			if (grossIncome <= 3500){taxes = 0.05*grossIncome;}
			else if (grossIncome > 3500 && grossIncome <= 9000){taxes = 0.07*grossIncome + 175;}
			else if (grossIncome > 9000 && grossIncome <= 125000){taxes = 0.09*grossIncome + 560;}
			else if (grossIncome > 125000){taxes = 0.099*grossIncome + 11000;}
		}
	}
	else if (year == 2018)
	{
		if (state == 'A'){taxes = 0.08*grossIncome;}
		else if (state == 'B')
		{
			if (grossIncome < 2500){taxes = 0;}
			else if (grossIncome >= 2500 && grossIncome <= 10000){taxes = 115;}
			else if (grossIncome > 10000){taxes = 0.105*grossIncome + 115;}
		}
		else if (state == 'C')
		{
			if (grossIncome <= 3450){taxes = 0.05*grossIncome;}
			else if (grossIncome > 3450 && grossIncome <= 8700){taxes = 0.07*grossIncome + 172.5;}
			else if (grossIncome > 8700 && grossIncome <= 125000){taxes = 0.09*grossIncome + 450;}	
			else if (grossIncome > 125000){taxes = 0.099*grossIncome + 11007;}
		}
	}
	

	cout << "Taxes: $" << taxes << endl;
	cout << "Remaining: $" << (grossIncome-taxes) << endl;

	return 0;
}
