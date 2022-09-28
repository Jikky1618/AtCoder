#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int ans = -1;
    for(int bit = 0; bit < (1 << n); bit++){
        int sum_yen = 0;
        vector<int> sum(n);
        for(int i = 0; i < n; i++){
            if((bit >> i) & 1){
                for(int j = 0; j < m; j++){
                    sum[j] += a[i][j];
                }
                sum_yen += c[i];
            }
        }
        bool can = true;
        for(int i = 0; i < m; i++){
            if(sum[i] < x) can = false;
        }
        if(can){
            if(ans == -1) ans = sum_yen;
            else ans = min(ans,sum_yen);
        }
    }

    cout << ans << endl;
    return 0;
}