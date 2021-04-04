/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <limits.h>

using ariel::Direction;
using namespace std;
using namespace ariel;

int main() {
	Board board;
    char option = '5';
	char dir = '5';
    unsigned int row, col, flag = 1, message_lenght;
    string buffer;
    while(option != '4'){
        buffer = "";
        cout << "\nWelcome to my Message board.\n" << "Please select one option:\n" << endl;
        cout << "Press 1 to post a new message.\n" << "Press 2 to read a message from the board.\n" << 
		"Press 3 to see the entire message board.\n" << "Press 4 to end the program." << endl;
        cin >> option;
        getline(cin, buffer);
        
        if(option == '1'){
            string message;
            while(dir!='1' && dir!='2'){
                cout << "In which direction would you like to post the message?" << endl;
                cout << "Press 1 for Horizontal.\n" << "press 2 for Vertical.\n" << endl;
                cin >> dir;
                if(dir!='1' && dir!='2'){
                    cout << "ERR: Please press 1 or 2..." << endl;
                }
            }
            while(flag==1){
                cout << "In whice line on the board would you like to post the message?" << endl;
                cin >> row;
                cout << "In whice column on the board would you like to post the message?" << endl;
                cin >> col;
                cin.clear();
                fflush(stdin);
                getline (cin, buffer);
                cout << "Please enter your message message:" << endl;
                getline (cin, message);
                if(!((row>=0 && row<UINT_MAX) && (col>=0 && col<UINT_MAX)))
				{
                	cout << "ERR: Wrong location, Please choose again" << endl;
                }   
                else
				{
                    flag = 0;
                }
            }
            if(dir == '1'){
                board.post(row, col, Direction::Horizontal, message);
                dir = '0';
                flag = 1;
                cout << "The message was post successfuly\n" << endl;
            }
            if(dir == '2'){
                board.post(row,col,Direction::Vertical,message);
                dir = '0';
                flag = 1;
				cout << "The message was post successfuly\n" << endl;
            }


        }
        else if(option == '2'){
            while(dir!='1' && dir!='2'){
                cout << "In which direction would you like to post the message?" << endl;
                cout << "Press 1 for Horizontal.\n" << "press 2 for Vertical.\n" << endl;
                cin >> dir;
                if(dir!='1' && dir!='2'){
                    cout << "ERR: Please press 1 or 2..." << endl;
                }
            }
            while(flag==1){
                cout << "From whice line on the board would you like to read the message?" << endl;
                cin >> row;
                cout << "From whice column on the board would you like to read the message?" << endl;
                cin >> col;
                cout << "What is the leangth of the message you would like to read?" << endl;
                cin >> message_lenght;
                if(!((row>=0 && row<UINT_MAX) && (col>=0 && col<UINT_MAX)))
				{
                	cout << "ERR: Wrong location, Please choose again" << endl;
                }   
                else
				{
                    flag = 0;
                }
            }
            if(dir == '1'){
                cout << board.read(row, col, Direction::Horizontal, message_lenght) << "\n" << endl;
                dir = 0;
                flag = 1;
            }
            if(dir == '2'){
                cout << board.read(row, col,Direction::Vertical, message_lenght)<< "\n" << endl;;
                dir = 0;
                flag = 1;
            }
        }
        else if(option == '3'){
            board.show();
        }
        else{
            std::cout << "ERR: Please press a number between 1 and 4.\n" << endl;
        }
    }
}

