#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // cnt[i] := iの個数
    vector<ll> cnt(N + 1);
    for(auto&& a: A) cnt[a]++;

    // 全ての組み合わせを足す
    ll sum = 0;
    for(int i = 1; i <= N; i++){
        sum += cnt[i] * (cnt[i] - 1) / 2;
    }

    for(int i = 0; i < N; i++){
        ll ans = sum;
        // sumからの差分を計算
        ans -= cnt[A[i]] * (cnt[A[i]] - 1) / 2;
        ans += (cnt[A[i]] - 1) * (cnt[A[i]] - 2) / 2;

        cout << ans << endl;
    }
}