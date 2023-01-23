#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
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
    vector<int> X(N);
    for(int i = 0; i < N; i++) cin >> X[i];

    vector<ll> R, L; // R: 0より右にあるろうそく、L: 0より左にあるろうそく
    for(int i = 0; i < N; i++){
        if(0 <= X[i]) R.push_back(X[i]);
        else L.push_back(-X[i]);
    }

    sort(R.begin(), R.end());
    sort(L.begin(), L.end());

    ll ans = INF;
    for(int r = 0; r <= R.size(); r++){
        int l = K - r;
        if(l > L.size()) continue;

        if(r != 0 && l != 0) ans = min({ans, L[l - 1] * 2 + R[r - 1], L[l - 1] + R[r - 1] * 2});
        if(r == 0) ans = min(ans, L[l - 1]);
        if(l == 0) ans = min(ans, R[r - 1]);
    }

    cout << ans << endl;
}