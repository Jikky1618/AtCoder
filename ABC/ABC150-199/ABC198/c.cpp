#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    double r,x,y;
    cin >> r >> x >> y;

    ll ans;
    double dist = sqrt(x * x + y * y);
    if(r == dist){
        ans = 1;
    }else if(dist <= r){
        ans = 2;
    }else{
        ans = ceil(dist / r);
    }

    cout << ans << endl;
    return 0;
}