//  Author Information

//  File Information
#include "Snapshot.h"

class Movement {
private:
public:
  Movement() {}

  ~Movement() {}

  // grid pieces are indexed starting from 1 when reading in but stored in
  // matrix starting from index 0
  Snapshot *move(char direction, char pieceName, Snapshot *current) {
    // find piece
    int index = 0;
    for (auto piece : current->getPieces()) {
      if (piece->getName() == pieceName) {
        // check direction piece is moving in
        vector<vector<char>> grid = current->getGrid();
        vector<Piece *> newPieces = current->getPieces();
        vector<tuple<int, int>> gridSpacesOccupied = piece->getOccupiedSpaces();
        vector<tuple<char, char>> newMoveList = current->getMoveList();
        int col = piece->getCol();
        int height = piece->getHeight();
        int width = piece->getWidth();
        int row = piece->getRow();
        switch (direction) {
        case 'u': {
          // check if piece can move in specified direction
          if (piece->moveableDirection() != 'v' &&
              piece->moveableDirection() != 'b') {
            return NULL;
          }
          // is there another piece in the movement direction / if piece falls
          // off grid
          for (int x = col; x < col + piece->getWidth(); x++) {
            if (row == 1) {
              return NULL;
            } else if (current->getGrid()[row - 2][x - 1] != '.') {
              return NULL;
            }
          }

          // update grid to reflect movement

          for (int x = col; x < col + width; x++) {
            grid[row - 2][x - 1] = pieceName;
            grid[row + (height - 2)][x - 1] = '.';
          }
          // update piece to reflect movement
          for (tuple<int, int> &t : gridSpacesOccupied) {
            get<0>(t)--;
          }
          row--;
          break;
        }
        case 'd': {
          // check if piece can move in specified direction
          if (piece->moveableDirection() != 'v' &&
              piece->moveableDirection() != 'b') {
            return NULL;
          }
          // is there another piece in the movement direction / if piece falls
          // off grid
          for (int x = col; x < col + piece->getWidth(); x++) {

            if (row + (height - 1) == current->getGrid().size()) { // xx
              return NULL;
            } else if (current->getGrid()[row + (height - 1)][x - 1] !=
                       '.') { // xx
              return NULL;
            }
          }
          // update grid to reflect movement

          for (int x = col; x < col + width; x++) {

            // updates bottom edge
            grid[row + (height - 1)][x - 1] = pieceName; // xx
            // updates top edge
            grid[row - 1][x - 1] = '.'; // xx
          }
          // update piece to reflect movement
          for (tuple<int, int> &t : gridSpacesOccupied) {
            get<0>(t)++; // xx
          }
          row++;
          break;
        }
        case 'l': {
          // check if piece can move in specified direction
          if (piece->moveableDirection() != 'h' &&
              piece->moveableDirection() != 'b') {
            return NULL;
          }
          // is there another piece in the movement direction / if piece falls
          // off grid
          for (int x = row; x < row + height; x++) {
            if (col == 1) { // xx
              return NULL;
            } else if (current->getGrid()[x - 1][col - 2] != '.') { // xx
              return NULL;
            }
          }

          // update grid to reflect movement

          for (int x = row; x < row + height; x++) {
            // updates left edge
            grid[x - 1][col - 2] = pieceName; // xx
            // updates right edge
            grid[x - 1][col + (width - 2)] = '.'; // xx
          }
          // update piece to reflect movement
          for (tuple<int, int> &t : gridSpacesOccupied) {
            get<1>(t)--; // xx
          }
          col--;
          break;
        }
        case 'r': {

          // check if piece can move in specified direction
          if (piece->moveableDirection() != 'h' &&
              piece->moveableDirection() != 'b') {
            return NULL;
          }
          // is there another piece in the movement direction / if piece falls
          // off grid
          for (int x = row; x < row + height; x++) {
            if (col + (width - 1) == current->getGrid()[0].size()) { // xx
              return NULL;
            } else if (current->getGrid()[x - 1][col + (width - 1)] !=
                       '.') { // xx
              return NULL;
            }
          }

          // update grid to reflect movement

          for (int x = row; x < row + height; x++) {
            // updates right edge
            grid[x - 1][col + (width - 1)] = pieceName; // xx
            // updates left edge
            grid[x - 1][col - 1] = '.'; // xx
          }
          // update piece to reflect movement
          for (tuple<int, int> &t : gridSpacesOccupied) {
            get<1>(t)++; // xx
          }
          col++;
          break;
        }
        }

        Piece *newPiece =
            new Piece(pieceName, row, col, height, width,
                      piece->moveableDirection(), gridSpacesOccupied);
        newPieces[index] = newPiece;
        // update movelist
        newMoveList.push_back(tuple<char, char>(pieceName, direction));
        Snapshot *newSnapshot = new Snapshot(grid, newPieces, newMoveList);
        return newSnapshot;
      }
      index++;
      // end of  if (piece->getName() == pieceName)
    }
  }
};