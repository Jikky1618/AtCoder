#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<vector<int>> t(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> t[i][j];
    }

    vector<int> p;
    for(int i = 1; i < n; i++) p.push_back(i);
    int ans = 0;
    do{
        int time = t[0][p[0]]; // 都市1 →都市p[0]
        for(int i = 0; i < n - 2; i++) time += t[p[i]][p[i + 1]];
        time += t[p.back()][0];
        if(time == k) ans++;
    }while(next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    return 0;
}