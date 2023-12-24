/* ---------------------------------------------
    Program 1: Gladiolus
        Prompt for the number of sections and display
        an ASCII gladiolus flower, with the sections centered
        above each other.

    Course: CS 141, Fall 2021. Tues 2pm lab
    System: Windows using Visual Studio Code
    Author: Matthew Danque
    
    Original ASCII graphics gives:
        .~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-.
        -----------------------------------------------------------
            ______                 _____  ____              
         { |        |     |  O       |   |    | |   |   |  |\    | }
         { |        |     |          |   |    | |   |   |  | \   | }
         { |        |_____|  | ____  |   |    | |   |   |  |  \  | }
         { |        |     |  |       |   |    | |   |   |  |   \ | }
         { |______  |     |  |       |   |____| |__/^\__|  |    \| }
        -----------------------------------------------------------
        .~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-.

   ---------------------------------------------
*/

#include <iostream>   // for cin and cout
#include <iomanip>    // for setw. The number in setw(...) is the total of blank spaces including the printed item.
#include <ios>
using namespace std;  // so that we don't need to preface every cin and cout with std::

// Entire program is given inside of main(), which is acceptable since this is the first program.
int main() {

    // Display the menu and get the user choice
    int menuOption = 0;
    cout << "Program 1: Gladiolus            \n"
         << "Choose from among the following options:  \n"
         << "   1. Display original graphic  \n"
         << "   2. Display Gladiolus         \n"
         << "   3. Exit the program          \n"
         << "Your choice -> ";
    cin >> menuOption;
    
    // Handle menu option of 3 to exit
    if( menuOption == 3) {
        exit( 0);
    }
    // Handle menu option of 1 to display custom ASCII graphics
    else if( menuOption == 1) {
        // My own graphic.  You must create your own.
        cout << setw( 8) << " ";
        // Display a line across the top
        for( int i=0; i<70; i++) {
           cout << "~";
        }
        cout << endl;
        // Displaying ASCII graphics for my original image.
        cout << setw( 10) << " " << " .~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~.\n"
             << setw( 10) << " " << "  -------------------------------------------------------------\n"
             << setw( 10) << " " << "      ______                 _____  ____\n"
             << setw( 10) << " " << "   { |        |     |  O       |   |    | |   |   |  |\\    | }\n"
             << setw( 10) << " " << "   { |        |     |          |   |    | |   |   |  | \\   | }\n"
             << setw( 10) << " " << "   { |        |_____|  | ____  |   |    | |   |   |  |  \\  | }\n"
             << setw( 10) << " " << "   { |        |     |  |       |   |    | |   |   |  |   \\ | }\n"
             << setw( 10) << " " << "   { |______  |     |  |       |   |____| |__/^\\__|  |    \\| }\n"
             << setw( 10) << " " << "  -------------------------------------------------------------\n"
             << setw( 10) << " " << " .~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~-~.\n"
             << endl;
        cout << setw( 8) << " ";
        // Display a line across the bottom
        for( int i=0; i<70; i++) {
            cout << "~";
        }
        cout << endl;
    } //end if( menuOption == 1)  // menu option to display custom graphic

    else if( menuOption == 2) {
        // Prompt for and get the number of flower sections.
        int numberOfSections = 0;
        cout << "Number of sections -> ";
        cin >> numberOfSections;
        
        // Place your code starting here
        // ...

        // Flower Sections

        //current amount of flowers 
        int currentFlowerCount = 1;

        while(currentFlowerCount < numberOfSections + 1){//for the number of flower sections

            cout << setfill(' ') << setw(numberOfSections + 3);
            cout << "---" << endl;
            int flowerLines = (currentFlowerCount * 2) - 1;
            int flowerLineCount = 1;
            //to keep track of spacing in the middle of the flowers
            //set to the number of sections - 1. Then decrease or increase by the flowerLineCount.
            int tempVar = numberOfSections;
            //used to track spacing within the flowers
            int whiteSpacing = 3;

            while (flowerLineCount < flowerLines + 1){ // for the number of lines needed for the flower sections

                if (flowerLineCount == currentFlowerCount) { //middle
                  //cout << "middle " << currentFlowerCount;
                  cout << setfill(' ') << setw((numberOfSections - currentFlowerCount) + 1);
                  cout << "(";
                  cout << setfill(' ') << setw(currentFlowerCount + 1);
                  cout << "@"
                       << setfill(' ') << setw(currentFlowerCount + 1);
                  cout << ")" << endl;
                  whiteSpacing -= 2;
                  tempVar++;
                } else if (flowerLineCount < currentFlowerCount){ //higher
                  //cout << "higher " << currentFlowerCount;
                  cout << setfill(' ') << setw(tempVar) << "("
                       << setfill(' ') << setw(whiteSpacing + 1);
                  cout << ")"
                       << endl;
                  whiteSpacing += 2;
                  tempVar--;
                } else if (flowerLineCount > currentFlowerCount){ // lower
                  //cout << "lower " << currentFlowerCount;
                  cout << setfill(' ') << setw(tempVar) << "("
                       << setfill(' ') << setw(whiteSpacing + 1);
                  cout << ")"
                       << endl;
                  whiteSpacing -= 2;
                  tempVar++;
                }
                flowerLineCount++;
            }
            currentFlowerCount++;
            if (numberOfSections + 1 == currentFlowerCount) {
              cout << setfill(' ') << setw(numberOfSections + 3);
              cout << "---" << endl;
            }
        }
        //creation of the stem
        // note to self, use modulus to differentiate the stem sectors
        int stemTracking = 1;
        while (stemTracking < numberOfSections + 1) {

          if ((stemTracking % 2) ==  1) {
            cout << setfill(' ') << setw(numberOfSections + 3);
            cout << " |/" << endl;
            cout << setfill(' ') << setw(numberOfSections + 2);
            cout << " |" << endl;

          } else {
            cout << setfill(' ') << setw(numberOfSections + 2);
            cout << "\\|" << endl;
            cout << setfill(' ') << setw(numberOfSections + 2);
            cout << " |" << endl;

          }
          stemTracking++;
        }
    } //end if( menuOption == 2) // menu option to display building
            
  cout << "Exiting" << endl;
  return 0;
}// end main()
