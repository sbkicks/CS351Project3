#include "Piece.h"
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Snapshot {
private:
  vector<vector<char>> grid;
  vector<Piece *> pieces;
  vector<tuple<char, char>> moveList;

public:
  Snapshot(vector<vector<char>> grid, vector<Piece *> pieces,
           vector<tuple<char, char>> moveList) {
    this->grid = grid;
    this->pieces = pieces;
    this->moveList = moveList;
  }

  ~Snapshot() {}

  vector<vector<char>> getGrid() { return grid; }

  vector<Piece *> getPieces() { return pieces; }

  vector<tuple<char, char>> getMoveList() { return moveList; }

  bool isSolved() {
    vector<tuple<int, int>> gridSpacesOccupied = pieces[0]->getOccupiedSpaces();
    for (auto space : gridSpacesOccupied) {
      // check if Z piece is in the rightmost clumn, puzzle is solved
      if (get<1>(space) == grid[0].size() - 1) {
        return true;
      }
    }
    return false;
  }
  void printGrid() {
    for (int x = 0; x < grid[0].size() + 2;
         x++) // Prints the top line border of the grid
      cout << "*";
    cout << endl;

    for (int x = 0; x < grid.size(); x++) {
      cout << "*";             // Left most border
      for (auto c : grid[x]) { // Grid items
        cout << c;
      }
      cout << "*" << endl; // Right most border
    }

    for (int x = 0; x < grid[0].size() + 2;
         x++) // Prints the bottom line border of the grid
      cout << "*";
    cout << endl;
  }

  void printMoves() {
    vector<tuple<char, int, string>> moves;
    string move;
    string lastMove = "first";
    char piece;
    char lastPiece;
    int numMoves = 0;
    int totalMoves = 0;
    for (auto t : moveList) {
      switch (get<1>(t)) {
      case 'u':
        move = "up";
        break;
      case 'd':
        move = "down";
        break;
      case 'l':
        move = "left";
        break;
      case 'r':
        move = "right";
        break;
      }

      if (lastMove == "first") {
        numMoves++;
        piece = get<0>(t);
        lastMove = move;
      } else if (lastMove == move && lastPiece == get<0>(t)) {
        numMoves++;
        lastMove = move;
      } else {
        moves.push_back(make_tuple(piece, numMoves, lastMove));
        numMoves = 1;
        totalMoves++;
        piece = get<0>(t);
        lastMove = move;
      }
      lastPiece = piece;
    }
    totalMoves++;
    moves.push_back(make_tuple(piece, numMoves, move));
    cout << "This puzzle is solvable in " << totalMoves << " steps" << endl
         << endl;
    for (auto t : moves) {
      cout << "Piece " << get<0>(t) << " moves " << get<1>(t) << " space(s) "
           << get<2>(t) << endl;
    }
    cout << endl;
    printGrid();
  }
};