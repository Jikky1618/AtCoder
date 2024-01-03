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
    int N, M, L;
    cin >> N >> M >> L;
    vector<ll> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    vector<set<int>> G(N);
    for(int i = 0; i < L; i++){
        int a, b; cin >> a >> b, a--, b--;
        G[a].insert(b);
    }

    // B を id で降順ソート
    vector<pair<ll, int>> B2(M);
    for(int i = 0; i < M; i++) B2[i] = {B[i], i};
    sort(B2.begin(), B2.end(), greater<pair<ll, int>>());

    ll ans = 0;
    for(int i = 0; i < N; i++){
        // B を降順で見ていく
        for(int j = 0; j < M; j++){
            auto [b, id] = B2[j];
            if(!G[i].count(id)){
                ans = max(ans, A[i] + b);
                break;
            }
        }
    }
    cout << ans << endl;
}