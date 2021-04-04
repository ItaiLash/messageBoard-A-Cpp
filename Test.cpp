#include "doctest.h"
#include "Board.hpp"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace ariel;
using namespace std;


ariel::Board board;

TEST_CASE("Read empty board")
{
    CHECK(board.read(/*row*/ 0, /*column*/0, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Vertical, 2) == string("__"));
    CHECK(board.read(12, 50, Direction::Vertical, 3) == string("___"));
    CHECK(board.read(32, 74, Direction::Horizontal, 4) == string("____"));
}

TEST_CASE("Read word where length=0")
{
    //Within the boundaries of the board
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 0, Direction::Vertical, 0) == "");
    CHECK(board.read(3, 3, Direction::Horizontal, 0) == "");
    CHECK(board.read(3, 3, Direction::Vertical, 0) == "");
    //Outside the boundaries of the board(resize is needed)
    CHECK(board.read(150, 150, Direction::Horizontal, 0) == "");
    CHECK(board.read(200, 200, Direction::Vertical, 0) == "");
}

TEST_CASE("Horizontal post")
{
    Board board1;
    board1.post(2, 2, Direction::Horizontal, "Message Box");

    CHECK(board1.read(2, 12, Direction::Horizontal, 1) == string("x"));
    CHECK(board1.read(1, 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board1.read(2, 0, Direction::Horizontal, 3) == string("__M"));
    CHECK(board1.read(3, 0, Direction::Horizontal, 4) == string("____"));
    CHECK(board1.read(2, 3, Direction::Horizontal, 5) == string("essag"));

    CHECK(board1.read(2, 12, Direction::Vertical, 1) == string("x"));
    CHECK(board1.read(2, 5, Direction::Vertical, 2) == string("s_"));
    CHECK(board1.read(1, 6, Direction::Vertical, 3) == string("_a_"));
    CHECK(board1.read(0, 9, Direction::Vertical, 4) == string("__ _"));
    CHECK(board1.read(0, 11, Direction::Vertical, 5) == string("__o__"));
}

TEST_CASE("Vertical post")
{
    Board board2;
    board2.post(2, 2, Direction::Vertical, "Board");

    CHECK(board2.read(2, 12, Direction::Horizontal, 1) == string("_"));
    CHECK(board2.read(1, 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board2.read(2, 0, Direction::Horizontal, 3) == string("__B"));
    CHECK(board2.read(3, 0, Direction::Horizontal, 4) == string("__o_"));
    CHECK(board2.read(6, 1, Direction::Horizontal, 5) == string("_d___"));

    CHECK(board2.read(2, 2, Direction::Vertical, 1) == string("B"));
    CHECK(board2.read(2, 5, Direction::Vertical, 2) == string("__"));
    CHECK(board2.read(0, 2, Direction::Vertical, 3) == string("__B"));
    CHECK(board2.read(1, 2, Direction::Vertical, 4) == string("_Boa"));
    CHECK(board2.read(3, 2, Direction::Vertical, 5) == string("oard_"));
}

TEST_CASE("Mix posts")
{
    board.post(0, 0, Direction::Horizontal, "Itai");
    board.post(2, 1, Direction::Vertical, "Lashover");
    board.post(5, 3, Direction::Horizontal, "Ariel");
    board.post(4, 6, Direction::Vertical, "Test");
    board.post(8, 3, Direction::Horizontal, "Computer");
    board.post(8, 3, Direction::Vertical, "Cpp");
    board.post(1, 3, Direction::Horizontal, "Horizontal");
    board.post(3, 11, Direction::Vertical, "Vertical");


    CHECK(board.read(9, 1, Direction::Horizontal, 1) == string("r"));
    CHECK(board.read(8, 6, Direction::Horizontal, 2) == string("pu"));
    CHECK(board.read(2, 0, Direction::Horizontal, 3) == string("_L_"));
    CHECK(board.read(5, 1, Direction::Horizontal, 4) == string("h_Ar"));
    CHECK(board.read(8, 0, Direction::Horizontal, 5) == string("_e_Co"));

    CHECK(board.read(2, 2, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(0, 3, Direction::Vertical, 2) == string("iH"));
    CHECK(board.read(6, 6, Direction::Vertical, 3) == string("stp"));
    CHECK(board.read(0, 11, Direction::Vertical, 4) == string("_a_V"));
    CHECK(board.read(7, 3, Direction::Vertical, 5) == string("_Cpp_"));

    board.show();
}


