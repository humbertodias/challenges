#include <iostream>

using namespace std;

int main( ){

    const string QUOTE = "LIFE IS NOT A PROBLEM TO BE SOLVED";

    int N; cin >> N;

    for(int i = 0; i < N; i++)
        cout << QUOTE[i];

    cout << endl;

    return 0;

}