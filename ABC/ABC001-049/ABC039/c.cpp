#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const string key = "WBWBWWBWBWBW";
const vector<string> val = {"Do", "Re", "Mi", "Fa", "So", "La", "Si"};
const vector<int> pos = {0, 2, 4, 5, 7, 9, 11};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    string ans = "none";
    for(int i = 0; i < 7; i++){
        bool flag = true;
        for(int j = 0; j < 20; j++){
            if(S[j] != key[(pos[i] + j) % 12]) flag = false;
        }
        if(flag) ans = val[i];
    }

    cout << ans << endl;
}