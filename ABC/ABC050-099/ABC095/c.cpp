#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    ll ans = LINF;
    for(int AB = 0; AB < 200005; AB++){
        int A = x - AB / 2; if(A < 0) A = 0;
        int B = y - AB / 2; if(B < 0) B = 0;
        ll sum = A * a + B * b + AB * c;
        ans = min(ans, sum);
    }

    cout << ans << endl;
    return 0;
}