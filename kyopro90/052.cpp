#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector A(N, vector<int>(6));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 6; j++) cin >> A[i][j];
    }

    vector<ll> S(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 6; j++) S[i] += A[i][j];
    }

    ll ans = 1;
    for(int i = 0; i < N; i++){
        ans *= S[i];
        ans %= MOD;
    }

    cout << ans << endl;
}