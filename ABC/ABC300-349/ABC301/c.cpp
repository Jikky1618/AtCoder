#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const string x = "atcoder";

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S, T;
    cin >> S >> T;

    map<char, int> mp1, mp2;
    for(auto c: S) mp1[c]++;
    for(auto c: T) mp2[c]++;

    bool flag = true;
    for(char c = 'a'; c <= 'z'; c++){
        if(count(x.begin(), x.end(), c)){
            if(mp1[c] < mp2[c]){
                mp1['@'] -= mp2[c] - mp1[c];
                if(mp1['@'] < 0) flag = false;
            }else{
                mp2['@'] -= mp1[c] - mp2[c];
                if(mp1['@'] < 0) flag = false;
            }
        }else{
            if(mp1[c] != mp2[c]) flag = false;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
}