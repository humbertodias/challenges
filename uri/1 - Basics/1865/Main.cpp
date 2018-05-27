#include <iostream>
#include <string>

using namespace std;

int main( ){

    const string THOR = "Thor";
    string person;

    int N;
    int force_applied;

    cin >> N;

    while(N--){

        cin >> person;
        cin >> force_applied;
        cout << (( person == THOR ) ? 'Y' : 'N') << endl;

    }

    return 0;
}