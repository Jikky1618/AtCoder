#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int W, a, b;
    cin >> W >> a >> b;
    if((a <= b && b <= a + W) || (b <= a && a <= b + W)){
        cout << 0 << endl;
        return 0;
    }else{
        cout << min(abs(b - a + W), abs(a - b + W)) << endl;
    }
    return 0;
}