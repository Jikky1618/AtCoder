#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    // +ごとにグループ分け
    vector<string> X;
    string x = "";
    for(auto c: S){
        if(c == '+') X.push_back(x), x = "";
        else x += c;
    }
    X.push_back(x);

    int ans = 0;
    for(auto e: X){
        if(!count(e.begin(), e.end(), '0')) ans++;
    }

    cout << ans << endl;
}