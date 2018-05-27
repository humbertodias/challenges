#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Request {
    Request(string n, string c, string s) : name(n), color(c), t_size(s) {}
    string name;
    string color;
    string t_size;
};

bool request_sorter(Request const& req1, Request const& req2) {
    if (req1.color != req2.color)
        return req1.color < req2.color;
    
    if (req1.t_size != req2.t_size)
        return req1.t_size > req2.t_size;

    return req1.name < req2.name;
}

int main() {
    int num_students;
    string name, color, t_size;
    vector < Request > requests;
    bool printBlack = false;


    while (true) {
        cin >> num_students;
        
        if (num_students == 0) break;
    
        if (printBlack)
            cout << endl;
        printBlack = true;

        requests.clear();
        for (int i = 0 ; i < num_students ; i++) {
            while (getchar() != '\n');
            getline(cin, name);
            cin >> color >> t_size;
            requests.push_back(Request(name, color, t_size));
        }

        sort(requests.begin(), requests.end(), request_sorter);

        for (int i = 0 ; i < num_students ; i++) {
            cout << requests[i].color << ' ' << requests[i].t_size << ' ' << requests[i].name << endl;
        }
    }

    return 0;
}