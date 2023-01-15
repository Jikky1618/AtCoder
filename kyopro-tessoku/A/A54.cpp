#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;

    map<string, int> mp;
    while(Q--){
        int q; cin >> q;
        if(q == 1){
            string x; int y; cin >> x >> y;
            mp[x] = y;
        }
        if(q == 2){
            string x; cin >> x;
            cout << mp[x] << "\n";
        }
    }
}