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
    int K;
    cin >> K;

    // 前から見て, a にできる文字があるかを調べる
    for(unsigned i = 0; i < S.size(); i++){
        // z よりも次にできるなら, a にできる
        // a の cost は 26 ではなく 0 であることに注意！
        int cost = (26 - (S[i] - 'a')) % 26;
        if(cost <= K){
            K -= cost;
            S[i] = 'a';
        }
    }

    debug(S, K);
    // 余った K は後ろの文字に消費する
    if(K > 0) S.back() += K % 26;

    cout << S << endl;
}