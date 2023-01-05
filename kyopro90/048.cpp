#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    // 1分で獲得できる点数を格納
    vector<ll> P;
    for(int i = 0; i < N; i++) P.push_back(B[i]); // 部分点
    for(int i = 0; i < N; i++) P.push_back(A[i] - B[i]); // 満点 - 部分点

    // 満点でも得られる点数は部分点より小さい -> 貪欲法
    sort(P.begin(), P.end(), greater<int>());

    ll ans = 0;
    for(int i = 0; i < K; i++) ans += P[i];

    cout << ans << endl;
    return 0;
}