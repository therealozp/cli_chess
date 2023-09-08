#include <iostream>
#include <vector>
#include <sstream>
using std::cin, std::cout, std::vector, std::stringstream;

class Piece {
public:
    char code;
    std::string position;
    Piece(char p) : code(p) {}
};
class Square {
public:
    bool isWhite;
    bool isOccupied;
    Piece piece;
    // initialization list for isWhite
    Square(bool white, bool occupied, Piece p) : isWhite(white), isOccupied(occupied), piece(p) {}

    char getChar() const {
        return isWhite ? '-' : '#';
    }

    std::string getPiece() const {
        if (isOccupied) {
            char piececode = piece.code;
            switch (piececode) {
                case 'P': 
                    return "♙"; 
                case 'N':
                    return "♘";
                case 'B':
                    return "♗";
                case 'R': 
                    return "♖";
                case 'Q': 
                    return "♕";
                case 'K': 
                    return "♔";
                case 'p':
                    return "♟︎";
                case 'n':
                    return "♞";
                case 'b':
                    return "♝";
                case 'r':
                    return "♜";
                case 'q':
                    return "♛";
                case 'k':
                    return "♚";
                default: 
                    return isWhite ? "-" : "#";
            }
        } else {
            return isWhite ? "-" : "#";
            
        }
    }
};

class Board {
private:
    static const int SIZE = 8;
    static const int SQUARE_SIZE = 1;
    vector<vector<Square>> squares;

    
public:
    Board() {
        for (int i = 0; i < SIZE; ++i) {
            vector<Square> row;
            for (int j = 0; j < SIZE; ++j) {
                bool isWhite = (i + j) % 2 == 0;
                row.push_back(Square(isWhite, false, Piece(' ')));
            }
            squares.push_back(row);
        }
    }

    // takes in a reference to a string 
    void parse_fen(std::string& fen) {
        stringstream ss(fen);

        std::string placement;
        ss >> placement;

        int row = 7; 
        int col = 0;
        for (char ch : placement) {
            Square &square = squares[row][col];
            if (ch == '/') {
                row--; 
                col = 0;
            } else if (isdigit(ch)) {
                int spaces = ch - '0';
                col += spaces;
            }  else {
                square.isOccupied = true;
                square.piece = Piece(ch);
                col++;
            }
        }   
    }


    void draw(std::string& fenstring) {
        parse_fen(fenstring);
        for (int i = 0; i < SIZE; i++) {
            // for each row (8 rows), draw `height` times
            for (int h = 0; h < SQUARE_SIZE; h++) {
                // draw height of square size
                for (int j = 0; j < SIZE; j++) {
                    // for each width, draw j number of columns
                    for (int w = 0; w < SQUARE_SIZE; w++) {
                        // draw with a width of square size
                        if (h == SQUARE_SIZE / 2 && w == SQUARE_SIZE /2) {
                            cout << squares[i][j].getPiece();
                        } else {
                            cout << squares[i][j].getChar(); 
                        }
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
    std::string fenstring = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    board.draw(fenstring);

    return 0;
}
