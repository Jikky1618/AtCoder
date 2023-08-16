#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

struct Node {
    int value, parent;
    Node(int v, int p) : value(v), parent(p) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;

    vector<Node> T;
    T.emplace_back(Node(-1, 0));
    int pos = 0;

    map<int, int> mp;
    while(Q--){
        string t; cin >> t;
        if(t == "ADD"){
            int x; cin >> x;
            T.emplace_back(Node(x, pos));
            pos = (int)T.size() - 1;
        }
        if(t == "DELETE"){
            pos = T[pos].parent;
        }
        if(t == "SAVE"){
            int x; cin >> x;
            mp[x] = pos;
        }
        if(t == "LOAD"){
            int x; cin >> x;
            pos = mp[x];
        }
        cout << T[pos].value << " \n"[Q == 0];
    }
}