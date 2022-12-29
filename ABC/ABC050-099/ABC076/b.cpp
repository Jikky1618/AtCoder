#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    
    int ans = 1;
    for(int i = 0; i < N; i++){
        if(K <= ans) ans += K;
        else ans *= 2;
    }

    cout << ans << endl;
    return 0;
}