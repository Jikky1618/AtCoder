#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int d,n;
    cin >> d >> n;
    vector<int> l(n),r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];

    // 前日比を加算
    vector<int> diff(d + 1);
    for(int i = 0; i < n; i++){
        diff[l[i] - 1]++; // l[i]日目の前日比を1増やす
        diff[r[i]]--; // r[i] + 1日目の前日比を1減らす
    }

    // 累積和
    vector<int> s(d + 1);
    s[0] = 0;
    for(int i = 0; i < d; i++) s[i + 1] = s[i] + diff[i];
    for(int i = 0; i < d; i++) cout << s[i + 1] << endl;
    return 0;
}