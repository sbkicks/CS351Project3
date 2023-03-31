//  Author Information

//  File Information
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Piece {
private:
  char pieceName;
  int row;
  int col;
  int height;
  int width;
  char directionMovable;
  // This is a vector that stores the places in the grid that the piece
  // occupies. It stores tuples where the first num in the tuple is the row, the
  // second, the column
  vector<tuple<int, int>> gridSpacesOccupied;

public:
  Piece(char pieceName, int row, int col, int height, int width,
        char directionMovable, vector<tuple<int, int>> &gridSpacesOccupied) {
    this->pieceName = pieceName;
    this->row = row;
    this->col = col;
    this->height = height;
    this->width = width;
    this->directionMovable = directionMovable;
    this->gridSpacesOccupied = gridSpacesOccupied;
  }

  char moveableDirection() { return directionMovable; }

  int getCol() { return col; }

  int getWidth() { return width; }

  int getHeight() { return height; }

  int getRow() { return row; }

  char getName() { return pieceName; }

  bool isMovable() {
    if (directionMovable == 'n') {
      return false;
    } else {
      return true;
    }
  }
  vector<tuple<int, int>> getOccupiedSpaces() { return gridSpacesOccupied; }
};