#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

vector<bool> makeIsPrime(ll x){
    vector<bool> prime(x + 1, true);
    if(0 <= x) prime[0] = false;
    if(1 <= x) prime[1] = false;
    for(int i = 2; i * i <= x; i++){
        if(!prime[i]) continue;
        for(int j = i * 2; j <= x; j += i){
            prime[j] = false; // iの倍数を削除
        }
    }
    return prime;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<bool> ans = makeIsPrime(n);
    for(int i = 0; i <= n; i++){
        if(ans[i]) cout << i << endl;
    }
    return 0;
}