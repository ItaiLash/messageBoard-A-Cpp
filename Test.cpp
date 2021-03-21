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
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Vertical, 2) == string("__"));
    CHECK(board.read(34, 100, Direction::Vertical, 5) == string("_____"));
    CHECK(board.read(23, 54, Direction::Horizontal, 4) == string("____"));
}

TEST_CASE("Read word where length=0")
{
    //at the start of the board
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 0, Direction::Vertical, 0) == "");
    //somewhere at the board
    CHECK(board.read(9, 2, Direction::Horizontal, 0) == "");
    CHECK(board.read(2, 9, Direction::Vertical, 0) == "");
    //corners check
    CHECK(board.read(7, 1, Direction::Horizontal, 0) == "");
    CHECK(board.read(7, 1, Direction::Vertical, 0) == "");
    //out of the board check
    CHECK(board.read(11, 44, Direction::Horizontal, 0) == "");
    CHECK(board.read(45, 12, Direction::Vertical, 0) == "");
}

TEST_CASE("Horizontal post")
{
    Board board1;
    board.post(2, 2, Direction::Horizontal, "Message Box");

    CHECK(board1.read(/*row*/ 2, /*column*/ 12, Direction::Horizontal, 1) == string("x"));
    CHECK(board1.read(/*row*/ 1, /*column*/ 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board1.read(/*row*/ 2, /*column*/ 0, Direction::Horizontal, 3) == string("__M"));
    CHECK(board1.read(/*row*/ 3, /*column*/ 0, Direction::Horizontal, 4) == string("____"));
    CHECK(board1.read(/*row*/ 2, /*column*/ 3, Direction::Horizontal, 5) == string("essag"));

    CHECK(board1.read(/*row*/ 2, /*column*/ 12, Direction::Vertical, 1) == string("x"));
    CHECK(board1.read(/*row*/ 2, /*column*/ 5, Direction::Vertical, 2) == string("s_"));
    CHECK(board1.read(/*row*/ 1, /*column*/ 6, Direction::Vertical, 3) == string("_a_"));
    CHECK(board1.read(/*row*/ 0, /*column*/ 9, Direction::Vertical, 4) == string("__ _"));
    CHECK(board1.read(/*row*/ 0, /*column*/ 11, Direction::Vertical, 5) == string("__o__"));
}

TEST_CASE("Vertical post")
{
    Board board2;
    board.post(2, 2, Direction::Vertical, "Board");

    CHECK(board2.read(/*row*/ 2, /*column*/ 12, Direction::Horizontal, 1) == string("_"));
    CHECK(board2.read(/*row*/ 1, /*column*/ 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board2.read(/*row*/ 2, /*column*/ 0, Direction::Horizontal, 3) == string("__B"));
    CHECK(board2.read(/*row*/ 3, /*column*/ 0, Direction::Horizontal, 4) == string("__o_"));
    CHECK(board2.read(/*row*/ 6, /*column*/ 1, Direction::Horizontal, 5) == string("_d___"));

    CHECK(board2.read(/*row*/ 2, /*column*/ 2, Direction::Vertical, 1) == string("B"));
    CHECK(board2.read(/*row*/ 2, /*column*/ 5, Direction::Vertical, 2) == string("__"));
    CHECK(board2.read(/*row*/ 0, /*column*/ 2, Direction::Vertical, 3) == string("__B"));
    CHECK(board2.read(/*row*/ 1, /*column*/ 2, Direction::Vertical, 4) == string("_Boa"));
    CHECK(board2.read(/*row*/ 3, /*column*/ 2, Direction::Vertical, 5) == string("oard_"));
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


    CHECK(board.read(/*row*/ 9, /*column*/ 1, Direction::Horizontal, 1) == string("r"));
    CHECK(board.read(/*row*/ 8, /*column*/ 6, Direction::Horizontal, 2) == string("pu"));
    CHECK(board.read(/*row*/ 2, /*column*/ 0, Direction::Horizontal, 3) == string("_L_"));
    CHECK(board.read(/*row*/ 5, /*column*/ 1, Direction::Horizontal, 4) == string("h_Ar"));
    CHECK(board.read(/*row*/ 8, /*column*/ 0, Direction::Horizontal, 5) == string("_e_Co"));

    CHECK(board.read(/*row*/ 2, /*column*/ 2, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(/*row*/ 0, /*column*/ 3, Direction::Vertical, 2) == string("iH"));
    CHECK(board.read(/*row*/ 6, /*column*/ 6, Direction::Vertical, 3) == string("stp"));
    CHECK(board.read(/*row*/ 0, /*column*/ 11, Direction::Vertical, 4) == string("_a_V"));
    CHECK(board.read(/*row*/ 7, /*column*/ 3, Direction::Vertical, 5) == string("_Cpp_"));
}


