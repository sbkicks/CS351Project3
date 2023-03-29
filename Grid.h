//  Author Information

//  File Information
#include <vector>
#include <iostream>
#include <sstream>
#include "Piece.h"

using namespace std;

class Grid{
  private:
    int numRows;
    int numCols;
    int numPieces;
    vector<vector<char>> grid;
    vector<Piece*> pieces;

  public:

    Grid() {
      numRows = 0;
      numCols = 0;
      numPieces = 0;
    }

    ~Grid() {
      
    }

    void intializeGrid(int row, int col) {
      numRows = row;
      numCols = col;
      numPieces = 0;

      for (int x = 0; x < row; x++) {
        vector<char> currRow;
        for (int y = 0; y < col; y++)
          currRow.push_back('.');
        grid.push_back(currRow);
      }

    }

    void printGrid() {
      for (int x = 0; x < numCols + 2; x++)    // Prints the top line border of the grid
        cout << "*";
      cout << endl;

      for (int x = 0; x < numRows; x++) {
        cout << "*";    // Left most border
        for (auto c : grid[x])    // Grid items
          cout << c;
        cout << "*" << endl;    // Right most border
      }

      for (int x = 0; x < numCols + 2; x++)    // Prints the bottom line border of the grid
        cout << "*";
    }

    void processPiece(stringstream& s) {
      int row, col, width, height;
      char movable;
      vector<tuple<int, int>> gridSpacesOccupied;

      s >> row;
      s >> col;
      s >> width;
      s >> height;
      s >> movable;

      // We must perform a check to make sure the piece is in a valid position
      // First case checks a top border out of bounds, second checks a bottom out of bounds
      if (row < 1 || (row + (height - 1) > numRows)) {
        cout << "Warning: Piece with starting position of " << row << "," << col << " falls outside of grid" << endl;
        cout << endl;
        return;
      }
      
      // First case checks a left border out of bounds, second a right out of bounds
      if (col < 1 || (col + (width - 1) > numCols)) {
        cout << "Warning: Piece with starting position of " << row << "," << col << " falls outside of grid" << endl;
        cout << endl;
        return;
      }

      // Now we need to check that movement specifier is valid (ie. is h, v, b, or n)
      if (movable != 'h' && movable != 'v' && movable != 'b' && movable != 'n') {
        cout << "Warning: Piece with starting position of " << row << "," << col << " has invalid movement" << endl;
        cout << endl;
        return;
      }

      // Now we need to check and make sure the new piece doesn't overlap with any other pieces
      // we need to create the gridSpacesOccupied vector

      for (int x = row; x < (row + height); x++) {
        for (int y = col; y < (col + width); y++) {
          if (grid[x - 1][y - 1] == '.') {   // meaning that space is open
            // We use minus 1 to account for the fact that row = 1 means index 0
            gridSpacesOccupied.push_back(tuple<int, int>(x - 1, y - 1));
          }
          else {
            cout << "Warning: Piece with starting position of " << row << "," << col << " overlaps with other piece" << endl;
            cout << endl;
            return;
          }
        }
      }

      // One last check, we need to properly name our piece and check to make sure we don't
      // have too many pieces
      
      char pieceName = ' ';
      int size = pieces.size();    // improve efficiency by local storing size
      if (size == 0)  // This piece is the first piece, should be the goal piece
        pieceName = 'Z';
      else if (size >= 1 && size <= 9)
        pieceName = (char)(size + 48);    // pieces 2-10 should be numbered "1-9"
      else if (size >= 10 && size <= 35)
        pieceName = (char)(size + 87);  // pieces 11-36 should be lettered "a-z"
      else if (size >= 36 && size <= 60)
        pieceName = (char)(size + 29);  // pieces 37-61 should be lettered "A-Y"
      else {
        cout << "Warning: Too many pieces added to the puzzle" << endl;  // Too many pieces
        cout << endl;
        return;
      }

      // Now that we've checked all possible errors preventing us from adding the piece,
      // we can go ahead and add the piece to the pieces vector and update the grid

      for (auto tup : gridSpacesOccupied) {
        grid[get<0>(tup)][get<1>(tup)] = pieceName;
      }
      
      Piece* newPiece = new Piece(pieceName, row, col, height, width, movable, gridSpacesOccupied);
      pieces.push_back(newPiece);
    }
    
};