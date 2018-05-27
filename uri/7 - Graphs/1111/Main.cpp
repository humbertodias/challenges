#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

/*
The big catch of this problem is the coordinate y(it's inverse)
 X = cities
 
 For Example
 
  0 1 2 3
3 X-X
2
1     X-X
0 X
*/

#define INFINITY 0x3f3f3f3f // Infinity

using namespace std;

int matrixSize;

typedef struct position {
  int column;
  int row;
} Position;

typedef struct node {
  vector<Position> neighborhood;

  // Used for dijkstra
  bool visited;
  int movements;
} Node;

typedef struct Map {
  vector< vector <Node> > nodes;
} Map;

Map initializeMap(Map map, int size) {
  map.nodes = vector< vector<Node> > (size , vector<Node>(size));

  for(int row = 0; row < size; row++) {
    for(int column = 0; column < size; column++) {
      Node temporary;

      temporary.neighborhood = vector<Position>();
      temporary.visited = false;

      temporary.movements = INFINITY; // +Infinity

      map.nodes[row][column] = temporary;
    }
  }

  return map;
}

int dijkstra(Position source, Position destiny, Map map) {
  queue<Position> queue;
  Node next;
  Node neighbor;
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

    map.nodes[nextPosition.row][nextPosition.column].visited = true;
    next = map.nodes[nextPosition.row][nextPosition.column];

    if(source.column == nextPosition.column &&
       source.row == nextPosition.row) {
      next.movements = 0;
    }

    // visite neighbors
    for(int index = 0; index < next.neighborhood.size(); index++) {
      neighborPosition = next.neighborhood[index];
      neighbor = map.nodes[neighborPosition.row][neighborPosition.column];

      if(neighbor.movements > next.movements + 1) {
        neighbor.movements = next.movements + 1;
      }

      if(!neighbor.visited) {
        queue.push(neighborPosition);
      }

      map.nodes[neighborPosition.row][neighborPosition.column] = neighbor;
    }

  }

  // When finish all visits
  next = map.nodes[destiny.row][destiny.column];
  return next.movements;

}

int main( ) {

    int i,j,n,teste,numEle;
    int norte,sul,oeste,leste;
    int xi,yi,xf,yf,origem,destino;
    bool loop = true;

    while (loop) {

        // map size
        scanf ("%d",&n);

        // end application
        if (n == 0)
            break;

        Map map;
        map = initializeMap(map, n);

        // build map of the city
        for (j = n - 1; j >= 0; j--) {
            for (i = 0; i < n; i++) {

                scanf ("%d %d %d %d",&norte,&sul,&oeste,&leste);

                Position position;
                if(norte) {
                  position.row = i;
                  position.column = j+1;

                  map.nodes[i][j].neighborhood.push_back(position);
                }
                if(sul) {
                  position.row = i;
                  position.column = j-1;

                  map.nodes[i][j].neighborhood.push_back(position);
                }
                if(oeste) {
                  position.row = i-1;
                  position.column = j;

                  map.nodes[i][j].neighborhood.push_back(position);
                }
                if(leste) {
                  position.row = i+1;
                  position.column = j;

                  map.nodes[i][j].neighborhood.push_back(position);
                }
            }
        }

        scanf ("%d",&teste); // test quantity

        for (i = 0; i < teste; i++) {

            scanf ("%d %d %d %d",&xi,&yi,&xf,&yf);

            Position source;
            source.row = xi;
            source.column = yi;

            Position destiny;
            destiny.row = xf;
            destiny.column = yf;

            int result = dijkstra(source, destiny, map);

            if (result != INFINITY)
                printf("%d\n", result);
            else
                printf("Impossible\n");
            }

        printf("\n");
    }
    return (0);
}