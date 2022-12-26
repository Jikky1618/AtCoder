#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int i, ll val, vector<ll> &ans){
    if(i == 11) return;

    ans.push_back(val);
    for(int j = -1; j <= 1; j++){
        int add = val % 10 + j;
        if(0 <= add && add <= 9) dfs(i + 1, val * 10 + add, ans);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll K;
    cin >> K;

    vector<ll> ans;
    for(int i = 1; i < 10; i++){
        dfs(1, i, ans);
    }

    sort(ans.begin(), ans.end());
    cout << ans[K - 1] << endl;
    return 0;
}