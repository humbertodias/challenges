#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

const int NOT_VISITED = 0;
const int VISITED = 1;
const int FINISHED = 2;

typedef struct graph {
  vector<int> status;
  vector< vector<int> > adjacentsTable; // Composed by only adjacents. Not a nxn table.

  // Methods
  void Graph(int quantity) {
    // +1 is just to make the rest of the process easy to read.
    status = vector<int>(quantity+1);
    adjacentsTable = vector< vector<int> > (quantity+1 , vector<int>());
  }

  void addAdjacent(int vertex, int adjacent) {
    adjacentsTable[vertex].push_back(adjacent);
  }

  // source: http://crbonilha.com/pt/3-exercicios-aleatorios/
  // Return true it means it's everything okay(no loops)
  bool depthFirstBreadth(int vertex) {
      status[vertex] = VISITED;

      // cout << "Vertex: " << vertex << endl;
      // cout << "Adjacents Size: " << adjacentsTable[vertex].size() << endl;

      for(int index=0; index<adjacentsTable[vertex].size(); index++) {
          int adjacentVertex = adjacentsTable[vertex][index];

          // cout << "Adjacents Vertex: " << adjacentsTable[vertex][index] << endl;
          // cout << "Adjacents Vertex Status: " << status[adjacentVertex] << endl << endl;

          if(status[adjacentVertex] == NOT_VISITED) {
              if(!depthFirstBreadth(adjacentVertex)) {
                  return false;
              }
          } else if(status[adjacentVertex] == VISITED) {
              return false;
          }
      }

      status[vertex] = FINISHED;
      return true;
  }

  void searchCycles() {
    for(int index = 1; index < status.size(); index++) {
      // cout << "DFS ON: " << index << endl << endl;
      if(!depthFirstBreadth(index)) {
        cout << "SIM" << endl;
        return;
      }
    }

    cout << "NAO" << endl;
  }


} Graph;

// From C++ Documentation
int stringToInt (string input) {
  int number = 0;

  stringstream myStream(input);

  if (myStream >> number) {
    return number;
  } else {
    return -1;
  }
};

int main () {
  int testsQuantity, dependencies, verticesQuantity, vertex, adjacent;
  string input = "";

  cin >> input;

  testsQuantity = stringToInt(input);

  for(int index = 0; index < testsQuantity; index++) {
    Graph graph;

    cin >> input;
    verticesQuantity = stringToInt(input);

    cin >> input;
    dependencies = stringToInt(input);

    graph.Graph(verticesQuantity);

    for(int indexDependencies = 0; indexDependencies < dependencies; indexDependencies++) {
      cin >> input;
      vertex = stringToInt(input);

      cin >> input;
      adjacent = stringToInt(input);

      graph.addAdjacent(vertex, adjacent);
    }

    // Resolve hear
    graph.searchCycles();

  }
}