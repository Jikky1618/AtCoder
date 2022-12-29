#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(i < K) ans += X;
        else ans += Y;
    }

    cout << ans << endl;
    return 0;
}