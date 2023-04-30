#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<int> make_is_prime(ll x){
    vector<bool> prime(x + 1, true);
    prime[0] = prime[1] = false;
    vector<int> res;
    for(int i = 2; i <= x; i++){
        if(!prime[i]) continue;
        res.emplace_back(i);
        for(int j = i * 2; j <= x; j += i){
            prime[j] = false;
        }
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    auto p = make_is_prime(3e5);
    int M = p.size();

    int ans = 0;
    for(int i = 0; i < M; i++){
        ll a = p[i];
        if(a * a * a * a * a >= N) break;
        for(int j = i + 1; j < M; j++){
            ll b = p[j];
            if(a * a * b * b * b >= N) break;
            for(int k = j + 1; k < M; k++){
                ll c = p[k];
                if(a * a * b * c * c > N) break;
                ans++;
            }
        }
    }

    cout << ans << endl;
}