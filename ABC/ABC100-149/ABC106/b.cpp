#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    int ans = 0;
    for(int i = 1; i <= n; i += 2){
        int divisor = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0) divisor++;
        }
        if(divisor == 8) ans++;
    }

    cout << ans << endl;
    return 0;
}