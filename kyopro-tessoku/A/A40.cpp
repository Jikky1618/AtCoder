#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 2e6 + 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> cnt(MAX);
    for(int i = 0; i < N; i++) cnt[A[i]]++;

    ll ans = 0;
    for(int i = 0; i < MAX; i++){
        ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
    }

    cout << ans << endl;
}