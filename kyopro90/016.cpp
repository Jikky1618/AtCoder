#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    int MAX = 10000;

    ll ans = MAX;
    // Aの枚数、Bの枚数を全探索
    for(ll x = 0; x < MAX; x++){
        for(ll y = 0; x + y < MAX; y++){
            ll val = x * A + y * B;
            if((N - val) % C == 0 && 0 <= N - val){
                // Cの枚数を計算で求める
                ll z = (N - val) / C;
                ans = min(ans, x + y + z);
            }
        }
    }

    cout << ans << endl;
    return 0;
}