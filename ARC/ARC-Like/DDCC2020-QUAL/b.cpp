#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> S(N + 1);
    ll sum = 0;
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i], sum += A[i];

    ll ans = INF;
    for(int i = 0; i < N; i++){
        ll diff = abs(S[i] - (sum - S[i]));
        ans = min(ans, diff);
    }

    cout << ans << endl;
    return 0;
}