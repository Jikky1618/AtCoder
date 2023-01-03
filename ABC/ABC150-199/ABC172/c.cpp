#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    // 累積和
    vector<ll> SA(N + 1), SB(M + 1);
    for(int i = 0; i < N; i++) SA[i + 1] = SA[i] + A[i];
    for(int i = 0; i < M; i++) SB[i + 1] = SB[i] + B[i];

    // BをM→0にしゃくとり法
    ll b = M, ans = 0;
    // Aを何冊読むか固定して、全探索
    for(ll a = 0; a <= N; a++){
        while(0 <= b && K < SA[a] + SB[b]) b--;
        if(0 <= b) ans = max(ans, a + b);
    }
    
    cout << ans << endl;
    return 0;
}