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
    vector<int> S(8);
    for(int i = 0; i < 8; i++) cin >> S[i];

    bool flag = true;
    for(int i = 0; i < 7; i++) if(S[i] > S[i + 1]) flag = false;
    for(int i = 0; i < 8; i++){
        if(100 <= S[i] && S[i] <= 675 && S[i] % 25 == 0) continue;
        flag = false;
    }

    cout << (flag ? "Yes" : "No") << endl;
}