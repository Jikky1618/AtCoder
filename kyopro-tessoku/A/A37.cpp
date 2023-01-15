#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, M, B;
    cin >> N >> M >> B;
    vector<ll> A(N), C(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> C[i];

    ll ans = 0;
    for(int i = 0; i < N; i++) ans += A[i] * M;
    for(int i = 0; i < M; i++) ans += C[i] * N;
    ans += B * M * N;

    cout << ans << endl;
}