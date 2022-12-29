#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, C, K, S, T;
    cin >> A >> B >> C >> K >> S >> T;

    int ans = A * S + B * T;
    if(K <= S + T) ans -= C * (S + T);

    cout << ans << endl;
    return 0;
}