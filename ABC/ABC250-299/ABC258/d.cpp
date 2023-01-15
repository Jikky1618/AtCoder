#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    ll ans = INF, time = 0;
    // 最後に2回以上クリアするステージを全探索
    for(int i = 0; i < N; i++){
        // i番目までクリアさせる
        time += A[i] + B[i];
        if(X - i - 1 > 0) ans = min(ans, time + B[i] * (X - i - 1));
    }

    cout << ans << endl;
}