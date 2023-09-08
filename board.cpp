#include <iostream>
#include <vector>
using std::cin, std::cout, std::vector;

class Square {
public:
    bool isWhite;
    // initialization list for isWhite
    Square(bool white) : isWhite(white) {}

    char getChar() const {
        return isWhite ? '-' : '#';
    }
};

class Board {
private:
    static const int SIZE = 8;
    static const int SQUARE_SIZE = 4;
    vector<vector<Square>> squares;

public:
    Board() {
        for (int i = 0; i < SIZE; ++i) {
            vector<Square> row;
            for (int j = 0; j < SIZE; ++j) {
                bool isWhite = (i + j) % 2 == 0;
                row.push_back(Square(isWhite));
            }
            squares.push_back(row);
        }
    }

    void draw() const {
        for (int i = 0; i < SIZE; i++) {
            // for each row (8 rows), draw `height` times
            for (int h = 0; h < SQUARE_SIZE; h++) {
                // draw height of square size
                for (int j = 0; j < SIZE; j++) {
                    // for each width, draw j number of columns
                    for (int w = 0; w < SQUARE_SIZE; w++) {
                        // draw with a width of square size
                        cout << squares[i][j].getChar(); 
                        cout << " ";
                   }
                }
                // after every mini-row is drawn, give it a new line
                cout << '\n';
            }
        }
    }
};

int main() {
    Board board;
    board.draw();

    return 0;
}
