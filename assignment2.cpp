/*******************************************************************
 * ** Program: assignment2.cpp
 * ** Author: Benjamin Shiffman
 * ** Date: 02/02/2020
 * ** Description: contains various error-testing functions
 * ** Input: string for get_int()
 * ** Output: error testing
 * *******************************************************************/


#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

/*******************************************************************
 * ** Function: check_range()
 * ** Description: checks if number is in provided range
 * ** Parameters: int lower, int upper, int num
 * ** Pre-conditions: takes in bounds and number
 * ** Post-conditions: returns true if num inside bounds
 * *******************************************************************/
bool check_range(int lower, int upper, int num){
	if(lower<=num && num<=upper){
		return true;
	}
	return false;
}

/*******************************************************************
 * ** Function: is_capital()
 * ** Description: checks if character is a capital letter
 * ** Parameters: char letter
 * ** Pre-conditions: takes in character
 * ** Post-conditions: returns true if character is a capital
 * *******************************************************************/
bool is_capital(char letter){
	int asciiVal = (int)letter;
	if(asciiVal>=65 && asciiVal<=90){
		return true;
	}
	return false;
}

/*******************************************************************
 * ** Function: is_even()
 * ** Description: checks if an integer is even
 * ** Parameters: int num
 * ** Pre-conditions: takes in an integer
 * ** Post-conditions: returns true if integer is even
 * *******************************************************************/
bool is_even(int num){
	if(num%2==0){
		return true;
	}
	return false;
}

/*******************************************************************
 * ** Function: is_odd()
 * ** Description: checks if an integer is odd
 * ** Parameters: int num
 * ** Pre-conditions: takes in an integer
 * ** Post-conditions: returns true if integer is odd
 * *******************************************************************/
bool is_odd(int num){
	if(num%2==1){
		return true;
	}
	return false;
}

/*******************************************************************
 * ** Function: equality_test()
 * ** Description: compares two integers
 * ** Parameters: int num1, int num2
 * ** Pre-conditions: takes in two integers
 * ** Post-conditions: returns -1, 1, and 0 for less than, greater than, and equal to operator truths
 * *******************************************************************/
int equality_test(int num1, int num2){
	if(num1<num2){
		return -1;
	}
	else if(num1>num2){
		return 1;
	}
	else{
		return 0;
	}
}

/*******************************************************************
 * ** Function: float_is_equal()
 * ** Description: checks if floats are equal with a level of precision
 * ** Parameters: float num1, float num2, float precision
 * ** Pre-conditions: takes in numbers and precision level
 * ** Post-conditions: returns true if difference between numbers is precise enough
 * *******************************************************************/
bool float_is_equal(float num1, float num2, float precision){
	if(abs(num1-num2)<=precision){
		return true;
	}
	return false;
}

/*******************************************************************
 * ** Function: is_int()
 * ** Description: checks if a string is an integer
 * ** Parameters: string num
 * ** Pre-conditions: takes in a string
 * ** Post-conditions: returns true if string contains only digits 0-9
 * *******************************************************************/
bool is_int(string num){
	for(int i=0; i<num.length(); i++){
		int asciiVal = (int)num[i];
		if(asciiVal<48 || asciiVal>57){
			return false;
		}
	}
	return true;
}

/*******************************************************************
 * ** Function: numbers_present()
 * ** Description: checks if a string contains numbers
 * ** Parameters: string str
 * ** Pre-conditions: takes in a string
 * ** Post-conditions: returns true if string contains numbers
 * *******************************************************************/
bool numbers_present(string str){
   	for(int i=0; i<str.length(); i++){
		int asciiVal = (int)str[i];
		if(asciiVal>=48 && asciiVal<=57){
			return true;
		}
	}
	return false;
}

/*******************************************************************
 * ** Function: letters_present()
 * ** Description: checks if a string contains letters
 * ** Parameters: string str
 * ** Pre-conditions: takes in a string
 * ** Post-conditions: returns true if string contains numbers
 * *******************************************************************/
bool letters_present(string str){
	for(int i=0; i<str.length(); i++){
		int asciiVal = (int)str[i];
		if((asciiVal>=65 && asciiVal<=90)||(asciiVal>=97 && asciiVal<=122)){
			return true;
		}
	}
	return false;
}

/*******************************************************************
 * ** Function: contains_substring()
 * ** Description: checks if a string contains another string
 * ** Parameters: string sentence, string substring
 * ** Pre-conditions: takes in a sentence and a possible substring
 * ** Post-conditions: returns true if sentence contains the substring
 * *******************************************************************/
bool contains_substring(string sentence, string substring){
	for(int i=0; i<(sentence.length()-substring.length()+1); i++){
	   	bool match = true;
	   	for(int j=0; j<substring.length(); j++){
			if(sentence[i+j]!=substring[j]){
				match = false;
				break;
			}
		}
		if(match){
			return true;
		}
	}
	return false;
}

/*******************************************************************
 * ** Function: word_count()
 * ** Description: counts the words in a sentence
 * ** Parameters: string sentence
 * ** Pre-conditions: takes in a sentence
 * ** Post-conditions: returns one more than the number of spaces
 * *******************************************************************/
int word_count(string sentence){
	int spaces = 0;
	for(int i=0; i<sentence.length(); i++){
		if(sentence[i]==' '){
			spaces++;
		}
	}
	return spaces+1;
}

/*******************************************************************
 * ** Function: to_upper()
 * ** Description: converts a string to all uppercase
 * ** Parameters: string sentence
 * ** Pre-conditions: takes in a sentence
 * ** Post-conditions: returns sentence in all uppercase
 * *******************************************************************/
string to_upper(string sentence){
	string newString = "";
	for(int i=0; i<sentence.length(); i++){
		int asciiVal = (int)sentence[i];
		if(asciiVal>96 && asciiVal<123){
			newString += (char)(asciiVal-32);
		}
		else{
			newString += sentence[i];
		}
	}
	return newString;
}

/*******************************************************************
 * ** Function: to_lower()
 * ** Description: converts string to all lowercase
 * ** Parameters: string sentence
 * ** Pre-conditions: takes in a sentence
 * ** Post-conditions: returns sentence in all lowercase
 * *******************************************************************/
string to_lower(string sentence){
	string newString = "";
	for(int i=0; i<sentence.length(); i++){
		int asciiVal = (int)sentence[i];
		if(asciiVal>64 && asciiVal<91){
			newString += (char)(asciiVal+32);
		}
		else{
			newString += sentence[i];
		}
	}
	return newString;
}

/*******************************************************************
 * ** Function: get_int()
 * ** Description: gets an integer from a string if it only contains digits
 * ** Parameters: string prompt
 * ** Pre-conditions: takes in a string
 * ** Post-conditions: returns integer if string is an integer or zero if string is not an integer
 * *******************************************************************/
int get_int(string prompt){
	bool promptIsInt = true;
	for(int i=0; i<prompt.length(); i++){
		if((int)prompt[i]<48 or (int)prompt[i]>57){
   			promptIsInt = false;
			return 0;
		}
	}
	if(promptIsInt == true){
		int integer = 0;
		for(int i=0; i<prompt.length(); i++){
			integer = integer*10 + ((int)(prompt[i])-48);
		}
   		return integer;
	}
}

int main(){
   	cout << "\nTesting check_range(1,3,2)...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << check_range(1,3,2);
	(check_range(1,3,2)==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting check_range(1,3,4)...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << check_range(1,3,4);
	(check_range(1,3,4)==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_capital('A')...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << is_capital('A');
	(is_capital('A')==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting is_capital('a')...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << is_capital('a');
	(is_capital('a')==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_even(2)...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << is_even(2);
	(is_even(2)==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting is_even(3)...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << is_even(3);
	(is_even(3)==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_odd(3)...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << is_odd(3);
	(is_odd(3)==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting is_odd(2)...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << is_odd(2);
	(is_odd(2)==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting equality_test(1,2)...\n";
	cout << "Expected: -1";
	cout << "\tAcutal: " << equality_test(1,2);
	(equality_test(1,2)==-1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting equality_test(2,1)...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << equality_test(2,1);
	(equality_test(2,1)==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting equality_test(2,2)...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << equality_test(2,2);
	(equality_test(2,2)==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting float_is_equal(1.5,1.65,0.25)...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << float_is_equal(1.5,1.65,0.25);
	(float_is_equal(1.5,1.65,0.25)==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting float_is_equal(1.5,1.65,0.1)...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << float_is_equal(1.5,1.65,0.1);
	(float_is_equal(1.5,1.65,0.1)==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting is_int(\"34\")...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << is_int("34");
	(is_int("34")==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting is_int(\"abc\")...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << is_int("abc");
	(is_int("abc")==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting numbers_present(\"abc123\")...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << numbers_present("abc123");
	(numbers_present("abc123")==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting numbers_present(\"abcdef\")...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << numbers_present("abcdef");
	(numbers_present("abcdef")==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting letters_present(\"abc123\")...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << letters_present("abc123");
	(letters_present("abc123")==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting letters_present(\"123456\")...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << letters_present("123456");
	(letters_present("123456")==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting contains_substring(\"abcdef\",\"de\")...\n";
	cout << "Expected: 1";
	cout << "\tAcutal: " << contains_substring("abcdef", "de");
	(contains_substring("abcdef", "de")==1)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	cout << "\nTesting contains_substring(\"abcdef\",\"gh\")...\n";
	cout << "Expected: 0";
	cout << "\tAcutal: " << contains_substring("abcdef","gh");
	(contains_substring("abcdef","gh")==0)? cout << "\tPASSED\n" : cout << "\tFAILED\n";

	cout << "\nTesting word_count(\"I like pie\")...\n";
	cout << "Expected: 3";
	cout << "\tAcutal: " << word_count("I like pie");
	(word_count("I like pie")==3)? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	
	cout << "\nTesting to_upper(\"qWeRtY\")...\n";
	cout << "Expected: QWERTY";
	cout << "\tAcutal: " << to_upper("qWeRtY");
	(to_upper("qWeRtY")=="QWERTY")? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	
	cout << "\nTesting to_lower(\"qWeRtY\")...\n";
	cout << "Expected: qwerty";
	cout << "\tAcutal: " << to_lower("qWeRtY");
	(to_lower("qWeRtY")=="qwerty")? cout << "\tPASSED\n" : cout << "\tFAILED\n";
	
	string prompt;
	cout << "Please enter a string to test whether it is a valid integer. If it is not an integer, zero will be returned: " << endl;
	cin >> prompt;
	
	cout << "get_int(prompt) returns " << get_int(prompt) << endl;

	return 0;
}
