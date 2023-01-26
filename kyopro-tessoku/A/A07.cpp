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
    int D, N;
    cin >> D >> N;

    // imos法
    vector<int> imos(D + 1);
    for(int i = 0; i < N; i++){
        int L, R; cin >> L >> R, R++;
        imos[L]++, imos[R]--;
    }
    for(int i = 0; i < D; i++) imos[i + 1] += imos[i];

    for(int i = 1; i <= D; i++){
        cout << imos[i] << '\n';
    }
}