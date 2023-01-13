#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll X, Y, A, B;
    cin >> X >> Y >> A >> B;

    ll power = X, ans = 0;

    // power * A < Y && power * A < B
    while(power < Y / A && power < B / A){
        power *= A;
        ans++;
    }

    ans += (Y - power - 1) / B;

    cout << ans << endl;
}