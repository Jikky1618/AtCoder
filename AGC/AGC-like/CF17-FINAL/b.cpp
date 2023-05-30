#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    map<char, int> mp;
    for(auto c: S) mp[c]++;

    int m = min({mp['a'], mp['b'], mp['c']});
    for(char c = 'a'; c <= 'c'; c++) mp[c] -= m;

    int cnt = 0;
    for(char c = 'a'; c <= 'c'; c++) if(mp[c]) cnt++;

    if(cnt == 0){
        cout << "YES" << endl;
    }else if(cnt == 1){
        int x = 0;
        for(char c = 'a'; c <= 'c'; c++) x = max(x, mp[c]);
        cout << (x <= 1 ? "YES" : "NO") << endl;
    }else if(cnt == 2){
        int x = 0, y = INF;
        for(char c = 'a'; c <= 'c'; c++) if(mp[c]) x = max(x, mp[c]), y = min(y, mp[c]);
        cout << (x <= 1 && y <= 1 ? "YES" : "NO") << endl;
    }
}