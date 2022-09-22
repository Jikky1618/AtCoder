#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    vector<int> one;
    // 60桁全探索
    for(int i = 0; i < 60; i++){
        // i桁目が1ならiを要素に追加
        if((n >> i) & 1) one.push_back(i);
    }

    vector<ll> ans;
    // bit全探索
    for(int bit = 0; bit < (1 << (int)one.size()); bit++){
        ll now = 0;
        for(int j = 0; j < (int)one.size(); j++){
            // bitのj桁目が1なら1をone[j]桁目にshift
            if((bit >> j) & 1) now += 1LL << one[j];
        }
        ans.push_back(now);
    }

    for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << endl;

    return 0;
}