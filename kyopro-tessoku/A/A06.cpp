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

    // 累積和
    vector<int> s(n + 1);
    for(int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];

    // クエリ処理
    for(int i = 0; i < q; i++){
        int l,r; cin >> l >> r; 
        l--; // 半開区間にするため調整
        cout << s[r] - s[l] << endl;
    }
    return 0;
}