#include <iostream>
#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;

namespace ariel {
    class Board {
        unsigned int rows;
        unsigned int cols;
        vector<vector<char>> board; 
    public:
        Board() {
            board = vector<vector<char>>(3 , vector<char> (3, '_'));
            rows = 3;
            cols = 3;
        }
        ~Board() { }
        void post(unsigned int row, unsigned int column, Direction direction, std::string message);
        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
        void resizeBoard(unsigned int r, unsigned int c);
    };
}
