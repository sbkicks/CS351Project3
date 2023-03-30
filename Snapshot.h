#include <vector>
#include <iostream>
#include <sstream>
#include <tuple>
#include <string>
#include "Piece.h"

using namespace std;

class Snapshot {
    private:
        vector<vector<char>> grid;
        vector<Piece*> pieces;
        vector<tuple<char, char>> moveList;
    public:

    Snapshot(vector<vector<char>> grid, vector<Piece*> pieces, vector<tuple<char, char>> moveList) {
        this->grid = grid;
        this->pieces = pieces;
        this->moveList = moveList;
    }

    ~Snapshot() {

    }

    vector<vector<char>> getGrid() {
        return grid;
    }

    vector<Piece*> getPieces() {
        return pieces;
    }

    vector<tuple<char, char>> getMoveList() {
        return moveList;
    }

    bool isSolved() {
        vector<tuple<int, int>> gridSpacesOccupied = pieces[0]->getOccupiedSpaces();

        for (auto space : gridSpacesOccupied) {
            // check if Z piece is in the rightmost clumn, puzzle is solved
            if(get<1>(space) == grid[0].size()) {
                return true;
            }
        }
        return false;
    }


    void printGrid() {
      cout << endl << "Snapshot grid" << endl << endl;
      //cout << grid.size();
      for (int x = 0; x < grid[0].size() + 2; x++) // Prints the top line border of the grid
        cout << "";
      cout << endl;
  
      for (int x = 0; x < grid.size(); x++) {
        cout << "";             // Left most border
        for (auto c : grid[x]) { // Grid items
          cout << c;
        }
        cout << "" << endl; // Right most border
      }
  
      for (int x = 0; x < grid[0].size() + 2; x++) // Prints the bottom line border of the grid
        cout << "";
      cout << endl;
  }
};