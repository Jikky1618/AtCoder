#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    // 累積和
    vector<ll> S(N+1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += i * A[i] - S[i];
    }

    cout << ans << endl;
}