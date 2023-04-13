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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> W(N), V(N), X(M);
    for(int i = 0; i < N; i++) cin >> W[i] >> V[i];
    for(int i = 0; i < M; i++) cin >> X[i];

    vector<pair<int, int>> A(N); // 荷物i := {V[i], W[i]}
    for(int i = 0; i < N; i++) A[i] = {V[i], W[i]};
    sort(A.begin(), A.end(), greater<pair<int, int>>());

    vector<pair<int, int>> B(M); // 箱i := {大きさ, id}
    for(int i = 0; i < M; i++) B[i] = {X[i], i};
    sort(B.begin(), B.end());

    while(Q--){
        int L, R; cin >> L >> R, L--, R--;
        ll ans = 0;
        vector<int> used(M);
        // L, ..., R は使えない
        for(int i = L; i <= R; i++) used[i] = true;
        // 価値が高い順から埋めていく
        for(auto [v, w]: A){
            for(auto [x, id]: B){
                if(used[id]) continue;
                if(w <= x){
                    ans += v;
                    used[id] = true;
                    break;
                }
            }
        }

        cout << ans << "\n";
    }
}