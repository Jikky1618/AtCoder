#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> gcd(1000);
    for(int i = 2; i < 1000; i++){
        for(int j = 0; j < n; j++){
            if(a[j] % i == 0) gcd[i]++;
        }
    }

    int ans = 0,gcd_max = 0;
    for(int i = 2; i < 1000; i++){
        if(gcd[i] > gcd_max){
            gcd_max = gcd[i];
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}