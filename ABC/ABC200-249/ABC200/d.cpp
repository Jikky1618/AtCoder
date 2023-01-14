#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1e6;

vector<bool> make_is_prime(ll x){
    vector<bool> prime(x + 1, true);
    prime[0] = prime[1] = false;
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
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    auto is_prime = make_is_prime(MAX);

    // MAXまでの素数のみを格納
    vector<ll> primes;
    for(int i = 0; i < MAX; i++) if(is_prime[i]) primes.push_back(i);

    // 累積和
    vector<ll> s(MAX+1);
    for(auto&& p: primes) s[p] = 1;
    for(int i = 0; i < MAX; i++) s[i + 1] += s[i];

    ll ans = 0;
    for(auto&& q: primes){
        ll pmax = min(N / q / q / q, q - 1);
        ans += s[pmax]; 
    }

    cout << ans << endl;
}