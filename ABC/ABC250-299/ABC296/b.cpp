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
    vector<string> S(8);
    for(int i = 0; i < 8; i++) cin >> S[i];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(S[i][j] == '*'){
                cout << (char)('a' + j) << 8 - i << endl;
                return 0;
            }
        }
    }
}