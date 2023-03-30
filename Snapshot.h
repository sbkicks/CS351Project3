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
};