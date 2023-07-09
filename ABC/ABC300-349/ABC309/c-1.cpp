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
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i];

    // 初日に飲まないと行けない薬
    ll sum = 0;
    for(int i = 0; i < N; i++) sum += b[i];

    if(sum <= K){
        cout << 1 << endl;
        return 0;
    }

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) P[i] = {a[i], b[i]};
    sort(P.begin(), P.end());

    for(int i = 0; i < N; i++){
        sum -= P[i].second;
        if(sum <= K){
            cout << P[i].first + 1 << endl;
            return 0;
        }
    }
}