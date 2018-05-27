// e2 e4 -> To get from e2 to e4 takes 2 knight moves.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <queue>
#include <limits>
#include <assert.h>

using namespace std;

const int SIZE = 8;

array<int, SIZE> column = {1,2,3,4,5,6,7,8};
array<char, SIZE> row = {'A','B','C','D','E','F','G', 'H'};

typedef struct position {
  int column;
  int row;
} Position;

typedef struct square {
  Position position;
  vector<Position> neighborhood;

  // Used for dijkstra
  bool visited;
  int movements;
} Square;

typedef struct board {
  vector< vector <Square> > squares;
} Board;


bool isValidPosition(Position position) {
  bool isValidPosition = false;

  if(position.column < 8 && position.column >= 0 &&
    position.row < 8 && position.row >= 0) {

    isValidPosition = true;
  }

  return isValidPosition;
}

Square setNeighbors(Square square) {
  Position position = square.position;
  Position neighborPosition = square.position;

  // +2 column and +1 row or +1 column and +2 row
  neighborPosition.row = position.row + 1;
  neighborPosition.column = position.column + 2;
  if(isValidPosition(neighborPosition)) {
    square.neighborhood.push_back(neighborPosition);
  }

  neighborPosition.row = position.row - 1;
  neighborPosition.column = position.column + 2;
  if(isValidPosition(neighborPosition)) {
    square.neighborhood.push_back(neighborPosition);
  }

  neighborPosition.row = position.row + 2;
  neighborPosition.column = position.column + 1;
  if(isValidPosition(neighborPosition)) {
    square.neighborhood.push_back(neighborPosition);
  }

  neighborPosition.row = position.row - 2;
  neighborPosition.column = position.column + 1;
  if(isValidPosition(neighborPosition)) {
    square.neighborhood.push_back(neighborPosition);
  }

  neighborPosition.row = position.row + 2;
  neighborPosition.column = position.column - 1;
  if(isValidPosition(neighborPosition)) {
    square.neighborhood.push_back(neighborPosition);
  }

  neighborPosition.row = position.row - 2;
  neighborPosition.column = position.column - 1;
  if(isValidPosition(neighborPosition)) {
    square.neighborhood.push_back(neighborPosition);
  }

  neighborPosition.row = position.row + 1;
  neighborPosition.column = position.column - 2;
  if(isValidPosition(neighborPosition)) {
    square.neighborhood.push_back(neighborPosition);
  }

  neighborPosition.row = position.row - 1;
  neighborPosition.column = position.column - 2;
  if(isValidPosition(neighborPosition)) {
    square.neighborhood.push_back(neighborPosition);
  }

  return square;
}


Board initializeBoard(Board board) {
  board.squares = vector< vector<Square> > (SIZE , vector<Square>(SIZE));

  for(int row = 0; row < SIZE; row++) {
    for(int column = 0; column < SIZE; column++) {
      Square temporary;
      // Check if this is correct set position whithout instantiate
      temporary.position.row = row;
      temporary.position.column = column;
      temporary.neighborhood = vector<Position>();
      temporary.visited = false;
      temporary = setNeighbors(temporary);

      temporary.movements = numeric_limits<int>::max(); // +Infinity

      board.squares[row][column] = temporary;
    }
  }

  return board;
}

Board clearBoard(Board board) {
  for(int row = 0; row < SIZE; row++) {
    for(int column = 0; column < SIZE; column++) {
      // Preferred this way w/o instantiate a temp square cause I don't have enough knowledge over the language C++
      // +Infinity
      board.squares[row][column].movements = numeric_limits<int>::max();

      board.squares[row][column].visited = false;
    }
  }

  return board;
}

int dijkstra(Position source, Position destiny, Board board) {
  queue<Position> queue;
  Square next;
  Square neighbor;
  Position nextPosition;
  Position neighborPosition;

  if(source.column == destiny.column &&
    source.row == destiny.row) {
      return 0;
    }

  queue.push(source);

  while(!queue.empty()) {
    // Get next to visit
    nextPosition = queue.front();
    queue.pop();
    //cout << "Visiting: " << nextPosition.row << " " << nextPosition.column << endl;

    board.squares[nextPosition.row][nextPosition.column].visited = true;
    next = board.squares[nextPosition.row][nextPosition.column];

    if(source.column == next.position.column &&
       source.row == next.position.row) {
      next.movements = 0;
    }

    // visite neighbors
    for(int index = 0; index < next.neighborhood.size(); index++) {
      neighborPosition = next.neighborhood[index];
      neighbor = board.squares[neighborPosition.row][neighborPosition.column];

      if(neighbor.movements > next.movements + 1) {
        neighbor.movements = next.movements + 1;
      }

      if(!neighbor.visited) {
        queue.push(neighborPosition);
      }

      board.squares[neighborPosition.row][neighborPosition.column] = neighbor;
    }

  }

  // When finish all visits
  next = board.squares[destiny.row][destiny.column];
  return next.movements;

}

Position stringToPosition(string coordinate) {
  char coordinateRow = (char) toupper( (int) coordinate.at(0));
  int columnIndex = coordinate.at(1) - '0'; // cast char to int
  int rowIndex;
  Position position;

  for(rowIndex = 0; rowIndex < SIZE; rowIndex++) {
    if(row[rowIndex] == coordinateRow) {
      break;
    }
  }

  position.column = columnIndex - 1; // Cast from 1 - 8 to 0 - 7
  position.row = rowIndex;

  return position;
}

// TEST AREA

void testMethodStringToPosition() {
  Position unit;

  unit = stringToPosition("e2");
  assert(unit.row == 4 && unit.column == 1);

  unit = stringToPosition("h8");
  assert(unit.row == 7 && unit.column == 7);

  unit = stringToPosition("H1");
  assert(unit.row == 7 && unit.column == 0);

  unit = stringToPosition("a1");
  assert(unit.row == 0 && unit.column == 0);
}

void testMethodIsValidPosition() {
  Position unit;

  unit.column = 0;
  unit.row = 0;
  assert(isValidPosition(unit));

  unit.column = 7;
  unit.row = 7;
  assert(isValidPosition(unit));

  unit.column = 7;
  unit.row = 8;
  assert(!isValidPosition(unit));

  unit.column = 8;
  unit.row = 7;
  assert(!isValidPosition(unit));

  unit.column = -1;
  unit.row = 7;
  assert(!isValidPosition(unit));

  unit.column = 2;
  unit.row = -1;
  assert(!isValidPosition(unit));
}

bool searchNeighbor(Square square, Position neighborPosition) {
  Position next;

  for(int index = 0; index < square.neighborhood.size(); index++) {
    next = square.neighborhood[index];

    if(next.column == neighborPosition.column
      && next.row == neighborPosition.row) {

      return true;
    }

  }

  return false;
}

void testMethodSetNeighbors() {
  Square unit;

  unit.position = stringToPosition("a1");
  unit = setNeighbors(unit);

  assert(searchNeighbor(unit, stringToPosition("b3")));
  assert(searchNeighbor(unit, stringToPosition("c2")));
  assert(!searchNeighbor(unit, stringToPosition("a1")));
  assert(unit.neighborhood.size() == 2);

  Square unit2;
  unit2.position = stringToPosition("e4");
  unit2 = setNeighbors(unit2);

  assert(searchNeighbor(unit2, stringToPosition("f6")));
  assert(searchNeighbor(unit2, stringToPosition("g5")));
  assert(searchNeighbor(unit2, stringToPosition("g3")));
  assert(searchNeighbor(unit2, stringToPosition("f2")));
  assert(searchNeighbor(unit2, stringToPosition("d2")));
  assert(searchNeighbor(unit2, stringToPosition("c3")));
  assert(searchNeighbor(unit2, stringToPosition("d6")));
  assert(searchNeighbor(unit2, stringToPosition("c5")));

  assert(unit2.neighborhood.size() == 8);

}

void testMethodInitializeBoard() {

}

void testMethodClearBoard() {

}

void testMethodDijkstra() {
  Board board;
  board = initializeBoard(board);
  assert(dijkstra(stringToPosition("a1"), stringToPosition("b3"), board) == 1);
  board = clearBoard(board);
  assert(dijkstra(stringToPosition("e2"), stringToPosition("e4"), board) == 2);
  board = clearBoard(board);
  assert(dijkstra(stringToPosition("a1"), stringToPosition("b2"), board) == 4);
  board = clearBoard(board);
  assert(dijkstra(stringToPosition("b2"), stringToPosition("c3"), board) == 2);
  board = clearBoard(board);
  assert(dijkstra(stringToPosition("a1"), stringToPosition("h8"), board) == 6);
  board = clearBoard(board);
  assert(dijkstra(stringToPosition("a1"), stringToPosition("h7"), board) == 5);
  board = clearBoard(board);
  assert(dijkstra(stringToPosition("h8"), stringToPosition("a1"), board) == 6);
  board = clearBoard(board);
  assert(dijkstra(stringToPosition("b1"), stringToPosition("c3"), board) == 1);
  board = clearBoard(board);
  assert(dijkstra(stringToPosition("f6"), stringToPosition("f6"), board) == 0);
}

void test() {
  testMethodStringToPosition();
  testMethodIsValidPosition();
  testMethodSetNeighbors();
  testMethodDijkstra();
}

// END OF TEST AREA

int main () {
  Board board;
  board = initializeBoard(board);
  string input = "";
  string source, destiny;
  int movements;
  //To get from e2 to e4 takes 2 knight moves.

  while(getline(cin, input)) {
    source = input.substr(0,2);
    destiny = input.substr(3,2);
    movements = dijkstra(stringToPosition(source), stringToPosition(destiny), board);
    cout << "To get from " << source << " to " << destiny  << " takes " << movements << " knight moves." << endl;
    board = clearBoard(board);
  }

  //test();

  return 0;
}