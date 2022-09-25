#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> flag(n);
    for(int i = 0; i < k; i++){
        int d; cin >> d;
        for(int j = 0; j < d; j++){
            int a; cin >> a;
            flag[a - 1]++;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!flag[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}