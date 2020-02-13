/*******************************************************************
 * ** Program: fractions.cpp
 * ** Author: Benjamin Shiffman
 * ** Date: 02/13/2020
 * ** Description: reduces fractions to lowest terms
 * ** Input: numerator, denominator
 * ** Output: simplified fraction
 * *******************************************************************/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

bool to_lowest_terms(int *numerator, int *denominator);

/*******************************************************************
 * ** Function: get_int()
 * ** Description: gets an integer from a string
 * ** Parameters: string prompt
 * ** Pre-conditions: takes in a string
 * ** Post-conditions: returns 0 if string is not an int and the integer if string is an int
 * *******************************************************************/
int get_int(string prompt){
	bool promptIsInt = true;
	//loop checks if first value is a negative sign, then returns false if any character isn't a digit 0-9
	for(int i=0; i<prompt.length(); i++){
	   	if(i==0 && prompt[i]=='-'){continue;}
		if((int)prompt[i]<48 or (int)prompt[i]>57){
   			promptIsInt = false;
			return 0;
		}
	}
	if(promptIsInt == true){
		int integer = 0;
		//translates string onto an integer variable
		for(int i=0; i<prompt.length(); i++){
		   	if(i==0 && prompt[i]=='-'){continue;}
		   	integer = integer*10 + ((int)(prompt[i])-48);
		}
		if(prompt[0]=='-'){integer=integer*(-1);}
   		return integer;
	}
}

/*******************************************************************
 * ** Function: is_int()
 * ** Description: checks if a string is an integer or not
 * ** Parameters: string num
 * ** Pre-conditions: takes in a string
 * ** Post-conditions: returns true or false if string is an int or not
 * *******************************************************************/
bool is_int(string num){
   	//checks if the ascii value of each integer is within the range of digits 0-9, skips first digit if it is a negative sign
	for(int i=0; i<num.length(); i++){
		int asciiVal = (int)num[i];
		if(i==0 && num[i]=='-'){continue;}
		if(asciiVal<48 || asciiVal>57){
			return false;
		}
	}
	return true;
}

/*******************************************************************
 * ** Function: getValidNumerator()
 * ** Description: asks user for a value for the numerator and handles all errors
 * ** Parameters: int *numerator
 * ** Pre-conditions: takes in a pointer to numerator declared in main
 * ** Post-conditions: sets numerator to a valid value
 * *******************************************************************/
void getValidNumerator(int *numerator){
   	string temp;
	while(true){
		cout << "Enter a numerator: " << endl;
		cin >> temp;
		if(is_int(temp)){
			*numerator=get_int(temp);
			break;
		} 
		else{cout<<"Invalid input. ";}
	}

}

/*******************************************************************
 * ** Function: getValidDenominator()
 * ** Description: asks user for a value for the denominator and handles all errors
 * ** Parameters: int *numerator, int *denominator
 * ** Pre-conditions: takes in both numerator and denominator pointers
 * ** Post-conditions: sets denominator to valid value
 * *******************************************************************/
void getValidDenominator(int *numerator,int *denominator){
   	string temp;
	while(true){
		cout << "Enter a denominator: " << endl;
		cin >> temp;
		if(is_int(temp)){*denominator=get_int(temp);}
		if(!to_lowest_terms(numerator,denominator)){cout<<"Denominator cannot be zero. ";}
		else{break;}
	}
}

/*******************************************************************
 * ** Function: g_c_d()
 * ** Description: returns the greatest common divisor of a given fraction
 * ** Parameters: int num1, int num2
 * ** Pre-conditions: takes in two integers
 * ** Post-conditions: returns the GCD if found or recursively calls the function to find GCD
 * *******************************************************************/
int g_c_d(int num1, int num2){
   	//uses the Euclidean algorithm to derive GCD
   	cout << num1 << endl;
	cout << num2 << endl;
	if(num1%num2==0){
		return num2;
	}
	else{
		g_c_d(num2, num1%num2);
	}
}

/*******************************************************************
 * ** Function: to_lowest_terms()
 * ** Description: reduces the numerator and denominator to their lowest terms
 * ** Parameters: int *numerator, int *denominator
 * ** Pre-conditions: takes in numerator and denominator pointers
 * ** Post-conditions: divides the values of the numerator and denominator by the GCD
 * *******************************************************************/
bool to_lowest_terms(int *numerator, int *denominator){
   	if(*denominator==0){
		return false;
	}
	else{	
	   	int gcd = g_c_d(*numerator,*denominator);
		*numerator = *numerator/abs(gcd);
		*denominator = *denominator/abs(gcd);
		return true;
	}
}

/*******************************************************************
 * ** Function: main()
 * ** Description: contains num/denom declarations and program loop
 * ** Parameters: none
 * ** Pre-conditions: numerator and denominator are declared
 * ** Post-conditions: prints fraction, asks user if they want to continue
 * *******************************************************************/
int main(){
	int numerator, denominator;
	bool cont = true;
	while(cont){
		getValidNumerator(&numerator);
		getValidDenominator(&numerator,&denominator);

		//if the denominator is negative, switch the signs of both numerator and denominator
		if(denominator<0){
			numerator=-1*(numerator);
			denominator=-1*(denominator); 
		}
		if(numerator%denominator==0){cout << "Lowest terms: " << numerator/denominator << endl;}
		//since signs are switched, this will always print in the correct format
		else{cout << "Lowest terms: " << numerator << "/" << denominator << endl;}
		cout << "Do you want to do another fraction reduction? (1 for yes)" << endl;
		cin >> cont;
	}
	
	return 0;
}
