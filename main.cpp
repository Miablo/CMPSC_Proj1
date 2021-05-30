/**
*File Name: Begin with "assign" and then the assignment number, for example, proj1.cpp, or proj1.h. You must have the extension .cpp or .h

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

*Assisted by and Assisted line numbers:

*Your Name: Mio Diaz
*Your PSU user ID:  mvd5044
*Course title CMPSC465 SU2021 
*Due Time: 11:59PM EST, Sunday, May 30, 2021
*Time of Last Modification: Time, Sunday, May 30, 2021

*Description: Project One utilizes stack to determine if a train can be marshelled from track a to b in the appropriate order
*/

// Headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stack>

using std::cout;
using std::string;
using std::stack;
using std::cin;
using std::endl;

// Function prototypes
void inOrder(int[],int);
int extractNum(string&);

const int MAX = 1000;

//---- STACK ---//
stack<int> 
	station;

//--- FILE STREAM ---//
std::ifstream fin;

// --------------------//
// BEGIN MAIN FUNCTION //
// -------------------//
int main(){
//----VARIABLES----//
bool 
	canMarshal = true;

int 
	coach[MAX];

int 
	N;

int i = 0;

string 
	temp;	

int train;

fin.open("lab1in.txt"); // open file

if(fin.fail()){ // if file doesn't open
	cout << "Error opening file. Try again.\n";
	exit(0);

	} else { // read until end of file
	cout << "File opened successfully. Processing now " << endl;
		// grab line
		getline(fin, temp);

		// find file token which = N
		N = extractNum(temp);
		cout << "This is N :: " << N << endl;

		while(!fin.eof()){
			getline(fin, temp);

			while(i < N){
				train = extractNum(temp);
				station.push(train);
				cout << station.top() << ' ';
				i++;
				if(train == 0){
					cout << endl;
					N = extractNum(temp);

					if(N==0){
						cout << endl;
						cout << N;
						break;
					} else {
							cout << "This is N :: " << N << endl;
							i = 0;
					}
				}
			}

			cout << endl;
			i = 0;

		}
	}

	fin.close(); // close file

	cout << "\n";

	return 0;
}

// Function Definition
// extracts string into its pieces ready for fixin'
// using the space as a compass
string extractField(string& s)
{
	// look for # - first one reading left to right
	int pos = s.find(' '); // first position of first space
	string position = s.substr(0, pos); // create new string
	s = s.substr(pos + 1);
	// split input string at space point
	return position;
}

// function DEFINITION
// converts string val to integer
int extractNum(string& s){

	string str = extractField(s);
	int num = 0;
	std::stringstream val(str);
	val >> num;

	return num;
}
