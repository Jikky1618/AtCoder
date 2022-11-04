#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int h,w,n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    // ソート -> 隣同士での重複要素を削除
    vector<int> an = a, bn = b;
    sort(an.begin(), an.end());
    an.erase(unique(an.begin(),an.end()),an.end());
    sort(bn.begin(), bn.end());
    bn.erase(unique(bn.begin(),bn.end()),bn.end());

    // 座標圧縮
    // a[i],b[i] := a[i],b[i]の要素がan,bnの何番目にあるか
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(an.begin(), an.end(),a[i]) - an.begin() + 1;
        b[i] = lower_bound(bn.begin(), bn.end(),b[i]) - bn.begin() + 1;
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}