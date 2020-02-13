/*******************************************************************
 * ** Program: patterns.cpp
 * ** Author: Benjamin Shiffman
 * ** Date: 02/13/2020
 * ** Description: creates diamond shaped patterns under user's parameters
 * ** Input: choice of numbers or letters, number of rows
 * ** Output: diamond pattern of numbers or letters
 * *******************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

/*******************************************************************
 * ** Function: drawPattern()
 * ** Description: iterates through a for loop and two nested for loops to print spaces and either numbers or letters
 * ** Parameters: int rows, bool choice
 * ** Pre-conditions: gets the number of rows and user's choice of pattern
 * ** Post-conditions: diamond pattern is printed
 * *******************************************************************/
void drawPattern(int rows, bool choice){
   	//prints the amount of spaces and characters needed for each row
	for(int i=0; i<rows; i++){
	   	//absolute value function printing spaces
		for(int s=1; s<=abs(i-rows/2); s++){cout << " ";}
		//absolute value function printing numbers or asterisks
		for(int a=1; a<=(-1*abs(2*i-rows+1)+rows); a++){
			if(choice){cout<<a;}
			else{cout<<"*";}
		}
		cout << endl;
	}
}

int main(){
   	int rows;
	bool choice;
	bool cont = true;
	while(cont){
		cout << "Would you like to make a pattern of asterisks (0) or numbers (1)? " << endl;
		cin >> choice;
		if(choice){rows = 9;}
		else{
			cout << "How many rows should it have? (must be a positive odd number) " << endl;
			cin >> rows;
		}
		
		drawPattern(rows,choice);
		cout << "Would you like to continue? (1 for yes) " << endl;
		cin >> cont;
	}
	return 0;
}
