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
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    ll ans = INF;
    // 入口: A[i], 出口: B[j]で全探索
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            ll dist = 0;
            for(int k = 0; k < N; k++){
                dist += abs(A[i] - A[k]) + abs(A[k] - B[k]) + abs(B[k] - B[j]);
            }
            ans = min(ans, dist);
        }
    }

    cout << ans << endl;
}