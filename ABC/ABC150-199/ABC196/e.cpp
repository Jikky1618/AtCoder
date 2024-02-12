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
    vector<ll> A(N), T(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> T[i];
    int Q;
    cin >> Q;
    vector<int> X(Q);
    for(int i = 0; i < Q; i++) cin >> X[i];

    ll high = INF, low = -INF, sum = 0;
    for(int i = 0; i < N; i++){
        // 1 の場合 low, high を平行移動
        if(T[i] == 1){
            low += A[i];
            high += A[i];
            sum += A[i];
        }
        // 2 の場合 low, high と A[i] との max を取る
        if(T[i] == 2){
            low = max(low, A[i]);
            high = max(high, A[i]);
        }
        // 3 の場合 low, high と A[i] との min を取る
        if(T[i] == 3){
            low = min(low, A[i]);
            high = min(high, A[i]);
        }
    }

    for(int i = 0; i < Q; i++){
        cout << clamp(X[i] + sum, low, high) << '\n';
    }
}