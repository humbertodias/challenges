#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;
typedef long long ll;
#define endl '\n'

struct event{
    int x,y,i,l;
    char type;
    event(){}
    event(int _x, int _y, int _i, char _t, int _l):
        x(_x),y(_y),i(_i),l(_l), type(_t){}

    bool operator < (const event &b) const{
        if( x < b.x )  return true;
        if( x == b.x ) return y > b.y;
        return false;
    }
};

class FenwickTree{
    vector<ll> v;
    int s;

    public:
        FenwickTree(int _s){
            s = _s;
            v = vector<ll>(s, 0LL);
        }

        void add(int where, int what){
            for(where++; where <= s; where += where & -where){
                v[where] += what;
            }
        }

        int query(int where){
            int sum = v[0];
            for(where++; where > 0; where -= where & -where)
                sum += v[where];
            return sum;
        }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int p,v;
    while ( cin >> p >> v ){
        set<int> num;
        vector<pair<int,int> > points(p), vertices(v);
        map<int,int> compressed;
        int ind = 1;
        ll  sol = 0;

        for(int i = 0; i < p; i++){
            cin >> points[i].first >> points[i].second;
            num.insert(points[i].first);
            num.insert(points[i].second);
        }


        for(int i = 0; i < v; i++){
            cin >> vertices[i].first >> vertices[i].second;
            num.insert(vertices[i].first);
            num.insert(vertices[i].second);
        }

        for(set<int>::iterator it = num.begin(); it != num.end(); it++)
            compressed[*it] = ind++;
        vector<event> events;

        FenwickTree tree = FenwickTree(ind + 10);

        ind = 0;
        for(int i = 0; i < p; i++, ind++)
            events.push_back(event(compressed[points[i].first],compressed[points[i].second],ind + 1, 'P', 0));

        for(int i = 0; i < v ; i++){
            if(vertices[i].second == vertices[(i + 1) % v].second){
                int xmin = min(compressed[vertices[i].first], compressed[vertices[(i + 1) % v].first]);
                int xmax = max(compressed[vertices[i].first], compressed[vertices[(i + 1) % v].first]);
                int l = abs(xmax - xmin);
                int y = compressed[vertices[i].second];

                events.push_back(event(xmin, y, 0, 'O', l));
                events.push_back(event(xmax, y, 0, 'C', l));
            }
        }

        sort(events.begin(), events.end());

        for(int i = 0; i < events.size(); i++){
            if(events[i].type == 'O'){
                tree.add(events[i].y, 1);
            }else if(events[i].type == 'P'){
                int sum = tree.query(events[i].y);
                if( !(sum & 1) )
                    sol += events[i].i;
            }else{
                tree.add(events[i].y, -1);
            }
        }
        cout << sol << endl;
    }
}