#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> l(q),r(q);
    for(int i = 0; i < q; i++) cin >> l[i] >> r[i];

    // 累積和
    vector<int> S(n + 1);
    S[0] = 0;
    for(int i = 0; i < n; i++) S[i + 1] = S[i] + a[i];

    // クエリ処理
    for(int i = 0; i < q; i++){
        cout << S[r[i]] - S[l[i] - 1] << endl;
    }
    return 0;
}