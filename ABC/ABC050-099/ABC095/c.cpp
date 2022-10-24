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
    // aピザとabピザを全探索
    for(int A = 0; A <= 5000; A++){
        for(int AB = 0; AB <= 5000; AB++){
            int B = max((int)y - AB / 2, 0);
            if(x <= A + AB / 2 && y <= B + AB / 2){
                ll sum = A * a + B * b + AB * c;
                ans = min(ans, sum);
            }
        }
    }

    cout << ans << endl;
    return 0;
}