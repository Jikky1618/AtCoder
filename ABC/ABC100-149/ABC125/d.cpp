#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0; // 要素内の負の数をカウント
    for(int i = 0; i < n; i++){
        if(a[i] < 0) cnt++;
    }
    // cnt偶数 := すべて正
    // cnt奇数 := 絶対値最小以外は正
    ll Min = INF;
    for(int i = 0; i < n; i++) Min = min(Min, abs(a[i]));

    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(cnt % 2 == 1 && abs(a[i]) == Min) ans -= Min;
        else ans += abs(a[i]);
    }

    cout << ans << endl;
    return 0;
}