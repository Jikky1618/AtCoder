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

    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) mp[a[i]].push_back(i + 1);
    
    for(int i = 0; i < q; i++){
        int x, k; cin >> x >> k;
        if(mp[x].size() >= k){
            cout << mp[x][k - 1] << endl;
        }else{
            cout << -1 << endl;
        }
    }

    return 0;
}