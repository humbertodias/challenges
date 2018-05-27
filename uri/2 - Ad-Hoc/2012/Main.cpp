#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

void flood(int x, int y, vector<vector<int> > &b, vector<vector<bool> > &v){
  int mx[4] = {1,0,-1,0};
  int my[4] = {0,1,0,-1};

  v[x][y] = true;

  for(int i = 0; i < 4; i++){
    int tx = x + mx[i];
    int ty = y + my[i];
    if(tx >= 0 && tx < v.size() && ty >= 0 && ty < v[0].size() && !v[tx][ty] && b[tx][ty] == b[x][y])
      flood(tx, ty, b, v);
  }
}

int main(){
  int n,m;
  while( cin >> n >> m){
    vector<vector<int> > board(n,vector<int>(m,0));
    vector<vector<bool> > v(n,vector<bool>(m));

    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) cin >> board[i][j];

    int sol = 5;

    //Up faces count
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
        if(v[i][j])continue;
        flood(i, j, board, v);
        sol++;
      }

    //Rows Sweep
    for(int i = 1; i < n; i++){
      int stado = 2;
      for(int j = 0; j < m; j++){
        if(board[i - 1][j] == board[i][j]){stado = 2; continue;}
        if(board[i - 1][j] > board[i][j]){
          if(stado != 0){
            sol++;
            stado = 0;
          }else if(j > 0 && (board[i - 1][j -1] <= board[i][j] || board[i - 1][j] <= board[i][j - 1])){
            sol++;
          }
        }else{
          if(stado != 1){
            sol++;
            stado = 1;
          }else if(j > 0 && (board[i - 1][j -1] >= board[i][j] || board[i - 1][j] >= board[i][j - 1])){
            sol++;
          }
        }
      }
    }

    //Columns Sweep
    for(int j = 1; j < m; j++){
      int stado = 2;
      for(int i = 0; i < n; i++){
        if(board[i][j - 1] == board[i][j]){stado = 2; continue;}
        if(board[i][j - 1] > board[i][j]){
          if(stado != 0){
            sol++;
            stado = 0;
          }else if(i > 0 && (board[i - 1][j - 1] <= board[i][j] || board[i][j - 1] <= board[i - 1][j])){
            sol++;
          }
        }else{
          if(stado != 1){
            sol++;
            stado = 1;
          }else if(i > 0 && (board[i - 1][j - 1] >= board[i][j] || board[i][j - 1] >= board[i - 1][j])){
            sol++;
          }
        }
      }
    }
    cout << sol << endl;
  }
}