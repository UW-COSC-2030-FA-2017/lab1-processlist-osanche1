// Omar Sanchez
// 9/11/2017
// COSC 2030
// 
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main() {
	string filename;
	double firstnum;
	double secondnum;
	double secondtolast = 0;
	double verylast = 0;
	double number = 0;
	string name;
	int counter = 0;
	int counter2 = 0;
	
	cout << "Please enter a valid file name: "; //Asking user for filename.
	cin >> filename; //storing filename
	ifstream myfile; 
	myfile.open(filename); //opening the file
	if (myfile.is_open()) { //checking to see if the file is open 
		while (!myfile.eof()) { //while loop that will continue until we reach the end of the file
			myfile >> number; //ask TA
			if (!(myfile.fail())) { //if the character is a number
				if (counter == 0) { 
					firstnum = number; // set the first number
				}
				if (counter == 1) {
					secondnum = number; //set the second number
				}
				counter = counter + 1; //add to the counter everytime we experience a number
			}
			else { // If its not a number we want to get rid of it.
				myfile.clear();
					myfile.ignore();
			}
		}
		myfile.seekg(0, ios::beg); //set us up at the beggining of the file.
		while (!myfile.eof()) {
			myfile >> number;
			if (!(myfile.fail())) {
				counter2 = counter2 + 1; // add 1 everytime we encounter a number
			}
			if (counter2 == counter - 1) { // setting the second to last number.
				secondtolast = number;
			}
			if (counter2 == counter) { // setting the last number
				verylast = number;
			}
		}
	}
	else {
		cout << "That is not a valid file name."; //what you'll see if the name you enter isn't actually a file. 
	}

	cout << "The number of numbers in this file is " << counter << endl; //Print out all of our info.
	cout << "The first number is " << firstnum << " and the second number is " << secondnum << "." << endl;
	cout << "The second to last number is " << secondtolast << " and the last number is " << verylast << "." << endl;


}