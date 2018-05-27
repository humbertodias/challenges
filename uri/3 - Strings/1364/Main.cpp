#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <utility>
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, n) FOR(i, 0, n)
#define sz(A) (int((A).size()))
#define pb push_back
#define all(A) A.begin(),A.end()
using namespace std;


const int INF = 1000000000;
typedef pair<int, int> ii;

bool compare(ii a, ii b) {
    return (a.first < b.first || (a.first == b.first && a.second < b.second));
}

vector<ii> match(string s, string t) {
    vector<ii> res;
    bool ok = true;
    FORR(i, sz(s)-sz(t)+1) {
        ok = true;
        FORR(j, sz(t)) {
            if(s[i+j] != t[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            res.pb(ii(i, i+sz(t)-1));
        }
    }
    return res;
}

string vetor[105], vetor2[105];

void print(int n) {
    FORR(i, n) {
        cout << vetor[i] << endl;
    }
}

int main() {
    int n, m, ans;
    scanf("%d %d", &n, &m);
    vector<ii> res;
    string text, aux;
    while(n != 0 || m != 0) {
        ans = 0;
        res.clear();
        FORR(i, n) {
            cin >> vetor[i];
        }
        text.clear();
        getline(cin, aux);
        FORR(i, m) {
            getline(cin, aux);
            text += ' ';
            text += aux;
        }

        FORR(k, n) {
            bool ok = true;
            FORR(i, sz(text)-sz(vetor[k])+1) {
                ok = true;
                FORR(j, sz(vetor[k])) {
                    if(text[i+j] != vetor[k][j]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    res.pb(ii(i, i+sz(vetor[k])-1));
                }
            }   
        }

        sort(all(res), compare);
        int menor, maior;
        menor = -1, maior = INF;
        FORR(i, sz(res)) {
            if(res[i].first <= maior) {
                menor = max(menor, res[i].first);
                maior = min(maior, res[i].second);
            }
            else {
                ans++;
                menor = res[i].first;
                maior = res[i].second;
            }
        }
        printf("%d\n", sz(res) == 0 ? 0 : ans+1);
        scanf("%d %d", &n, &m);
    }
    return 0;
}