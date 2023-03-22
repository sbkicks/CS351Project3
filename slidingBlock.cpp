//    Author Information

//    Program information

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char** argv){
  if ( argc != 2 ) { // argc should be 2 for correct execution
    // We print argv[0] assuming it is the program name
    cout<<"usage: "<< argv[0] <<" <filename>\n";
    exit(0);
  }
 
  // We assume argv[1] is a filename to open
  ifstream the_file ( argv[1] );
  // Always check to see if file opening succeeded
  if ( !the_file.is_open() ) {
    cout<<"Could not open file: " << argv[1] << "\n";
    exit(0);
  }

  cout << "Welcome to Sliding Block Puzzle\n";
  cout << "Using data from puzzle: " << argv[1] << endl;
  
  bool done = false;
  string line;
  string input;

  // read in input file and set up initial puzzle configuration
  while (std::getline(the_file, line)) {
    std::istringstream iss(line);
    cout << line << endl;    // this is to verify data input and should not be part of final code
  }


  // TODO list:
    // 1.
    // Figure out the format of the data files for intial configurations, learn
    // how to parse the data and get and idea on how to build the neccessary grid and piece objects
    ///////////
    // 2. 
    // Implement the Piece class based on the input from the intial data file
    ///////////
    // 3.
    // Implement the Grid class based on all the piece objects
    ///////////
    // 4.
    // Print out a text representation of the puzzle as specifed in the project writeup
    ///////////
    // 5.
    // Use the Grid class representation of the puzzle to create an algorithm to find
    // the shortest solution.
    ///////////
    // 6. 
    // Print out solution to puzzle
    ///////////
  
  return 0;
}
