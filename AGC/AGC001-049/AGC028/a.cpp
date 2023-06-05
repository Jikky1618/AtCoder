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
    ll N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    ll L = lcm(N, M);
    map<ll, char> mp;
    for(int i = 0; i < N; i++) mp[(L / N) * i + 1] = S[i];
    debug(mp);
    bool flag = true;
    for(int i = 0; i < M; i++){
        if(mp.find((L / M) * i + 1) == mp.end()) continue;
        if(mp[(L / M) * i + 1] != T[i]) flag = false;
    }

    cout << (flag ? L : -1) << endl;
}