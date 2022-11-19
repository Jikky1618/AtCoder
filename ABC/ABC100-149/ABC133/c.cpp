#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll l,r;
    cin >> l >> r;

    int ans = INF;
    for(int i = l; i <= r; i++){
        for(int j = i + 1; j <= r; j++){
            int num = (i % 2019) * (j % 2019) % 2019;
            ans = min(ans, num);
            if(ans == 0){
                cout << ans << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}