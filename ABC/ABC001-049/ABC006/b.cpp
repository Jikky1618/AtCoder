#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 10007;

vector<ll> memo(pow(10, 6) + 1, -1);
ll f(ll N){
    if(memo[N] != -1) return memo[N];

    if(N == 1 || N == 2) return memo[N] = 0;
    if(N == 3) return memo[N] = 1;
    return memo[N] = (f(N - 1) + f(N - 2) + f(N - 3)) % MOD;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}