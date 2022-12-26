#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int X;
    cin >> X;

    int ans = 0;
    for(int b = 1; b <= X; b++){
        for(int p = 2; p <= 1000; p++){
            if(X < pow(b, p)) continue;
            ans = max(ans, (int)pow(b, p));
        }
    }

    cout << ans << endl;
    return 0;
}