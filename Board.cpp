#include "Board.hpp"
using namespace std;

namespace ariel {
    /**
     * @brief Posting the message on the board in the given place(row, column)
     * 
     * @param row       The row number where the message will be post
     * @param column    The column number where the message will be post
     * @param direction Message writing direction, horizontal or vertical
     * @param message   A reference of the message as a string
     */
    void Board::post(unsigned int row, unsigned int column, Direction direction, string const &message) 
    {
        //Updates the board boundaries according to the written message
        this->maxRow = max(this->maxRow, row);
        this->minRow = min(this->minRow, row);
        this->maxCol = max(this->maxCol, column);
        this->minCol = min(this->minCol, column);
        
        unsigned int length = 0;

        //Write the message on the board
        for(char c: message)
        {
            this->myBoard[row][column].entry = c;
            if(direction == Direction::Horizontal){
                column++;
            }
            else
            {
                row++;
            }
            length++;
        }
        if(direction == Direction::Horizontal){
                maxCol+=length;
            }
            else
            {
                maxRow+=length;
            }
    }

    /**
     * @brief Reading a message from the board in the given place(row, column)
     * 
     * @param row           The row number from which the message will begin to be read
     * @param column        The column number from which the message will begin to be read
     * @param direction     Message reading direction, horizontal or vertical
     * @param length        The length of the message to be read from the board
     * @return std::string  The read message from the board as a string
     */
    std::string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length) 
    {
        string message;
        for(unsigned int i=0; i<length; i++){
            message += this->myBoard[row][column].entry;
            if(direction == Direction::Horizontal){
                column++;
            }
            else
            {
                row++;
            }        
        }
        return message;
    }

    /**
     * @brief Displays the board to the screen
     */
    void Board::show() 
    {
        for (unsigned int row = this->minRow; row <= this->maxRow; row++) 
        {
            for (unsigned int col = this->minCol; col <= this->maxCol; col++) 
            {
                cout << this->myBoard[row][col].entry;
            }
            cout << endl;
        }
    }
}
