#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_square(ll x) {
    ll r = (ll)floor(sqrt((long double)x));  // 切り捨てした平方根
    return (r * r) == x;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,d;
    cin >> n >> d;
    vector<vector<int>> x(n,vector<int>(d));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < d; j++) cin >> x[i][j];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int dist = 0;
            for(int k = 0; k < d; k++) dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            if(is_square(dist)) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}