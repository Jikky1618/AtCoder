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
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    // 準備度の差分を計算
    vector<ll> diff(N);
    for(int i = 0; i < N; i++) diff[i] = A[i] - B[i];

    int ans = 0;

    // 足りない準備度
    ll need = 0;
    for(auto&& v: diff) if(v < 0) need += abs(v), ans++;

    // 降順にソート
    sort(diff.begin(), diff.end(), greater<ll>());

    for(int i = 0; i < N; i++){
        if(need <= 0) break;
        need -= diff[i], ans++;
    }

    cout << (need <= 0 ? ans : -1) << endl;
}