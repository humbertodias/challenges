#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000000
#define min(a, b) (((a)<(b))?(a):(b))

using namespace std;

int solve(int height, int boards_to_complete, vector <int>& boards);

int main(){
    int m, n, l, k, aux;
    int aws1, aws2;
    vector <int> boards;

    while (true) {
        cin >> m >> n;

        if (m == 0 and n == 0) break;
        boards.clear();

        cin >> l;
        cin >> k;
        for (int i = 0 ; i < k ; i++) {
            cin >> aux;
            boards.push_back(aux);
        }
        sort(boards.begin(), boards.end(), greater<int>());

        aws1 = MAX;
        aws2 = MAX;
        if ((n * 100) % l == 0)
            aws1 = solve(m, n * 100 / l, boards);
        if ((m * 100) % l == 0)
            aws2 = solve(n, m * 100 / l, boards);

        if ((aws1 == 0 and aws2 == 0) or (aws1 == MAX and aws2 == MAX))
            cout << "impossivel" << endl;
        else
            cout << min(aws1, aws2) << endl;
    }
 
    return 0;
}

int solve(int height, int boards_to_complete, vector <int>& boards) {
    int begin, end, vertical_boards, boards_used;
    begin = 0;
    end = boards.size() - 1;
    vertical_boards = 0;
    boards_used = 0;

    while (true) {
        if (vertical_boards == boards_to_complete) break;
        if (begin > end) return MAX;
        
        if (boards[begin] > height) {
            begin++;
        } else if (boards[begin] == height) {
            begin++;
            vertical_boards++;
            boards_used++;
        } else {
            if (begin != end) {        
                while (true) {
                    if (boards[begin] + boards[end] == height) {
                        end--;
                        vertical_boards++;
                        boards_used += 2;
                        break;
                    }
                    if (boards[begin] + boards[end] > height) {
                        break;
                    }
                    end--;
                }
            }
            begin++;
        }
    }

    return boards_used;
}
