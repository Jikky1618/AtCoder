#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// n進数の文字列xを10進数に変換
ll n_to_dec(string& x, ll n){
    assert(2 <= n && n <= 10);
    ll res = 0, base = 1, size = (ll)x.size();
    for(int i = size - 1; i >= 0; i--){
        res += 1LL * (x[i] - '0') * base;
        base *= n;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    ll N;
    cin >> S >> N;

    string T = S;
    for(auto&& c: T){
        if(c == '?') c = '0'; 
    }
    // できるかぎり ? を 0 にしたものが N より大きいなら -1
    if(n_to_dec(T, 2) > N){
        cout << -1 << endl;
        return 0;
    }

    // そうでなければ上から貪欲にできるだけ 1 にする
    for(int i = 0; i < (int)S.size(); i++){
        if(S[i] == '?'){
            T[i] = '1';
            if(n_to_dec(T, 2) > N) T[i] = '0';
        }
    }

    cout << n_to_dec(T, 2) << endl;
}