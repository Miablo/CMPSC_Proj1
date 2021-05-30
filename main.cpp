/**
*File Name: Begin with "assign" and then the assignment number, for example, proj1.cpp, or proj1.h. You must have the extension .cpp or .h
*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)
*Assisted by and Assisted line numbers:
*Your Name: Mio Diaz
*Your PSU user ID:  mvd5044
*Course title CMPSC465 SU2021 
*Due Time: 11:59PM EST, Sunday, May 30, 2021
*Time of Last Modification: 4:04PM, Sunday, May 30, 2021
*Description: Project One utilizes stack to determine if a train can be marshelled from track a to b in the appropriate order
*/

//----Headers---//
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <stack>

//--- namespace --//
using std::cout;
using std::string;
using std::stack;
using std::cin;
using std::endl;

//---- Global Variables ---//
int N, i, coach, num;

//---- STACK ---//
stack<int> station;

// --------------------//
// BEGIN MAIN FUNCTION //
// -------------------//
int main() {
	//--- FILE STREAM ---//
	// read-only //
  freopen("lab1in.txt", "r", stdin);

	// Read file //
  while (1) {
		// grab digit //
    scanf("%d\n", &N);
			// end of input //
      if (N==0) {
				fflush(stdin);
        break;
      }
			// else continue to next num //
      while (1) {
				// empty stack //
        while (!station.empty()) {
          station.pop();
        }
				// check coaches order in station //
        for (num = i = 0; i < N; i++) {
					// next num in line one //
          scanf("%d ", &coach);
					// end block //
          if (coach==0) {
						fflush(stdin);
            break;
          }

          while (N > num && num != coach) {
            if (!station.empty() && station.top() == coach) {
                break;
            }
            station.push(++num);
          }

          if (station.top() == coach) {
           station.pop();
          }

				}
			// end
      if (coach==0) {
					fflush(stdin);
          break;
      }

			// -- Can Marshal -- //
      if (station.empty()) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
  	}
	
  	cout << "\n";
  }
	// end program //
  return 0;
}
// end of main //