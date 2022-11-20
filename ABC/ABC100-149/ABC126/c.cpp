#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,k;
    cin >> n >> k;

    // 1 回目の出た目を全探索(1 ~ N の整数)
    double ans = 0;
    for(int i = 1; i <= n; i++){
        double prob = 1.0 / n;
        int point = i;
        while(point < k){
            point *= 2;
            prob *= 1.0 / 2;
        }
        ans += prob;
    }

    cout << ans << endl;
    return 0;
}