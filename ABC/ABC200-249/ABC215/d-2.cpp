#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MAX = 1e5 + 1;

vector<pair<ll, ll>> prime_factorize(ll n){
    vector<pair<ll, ll>> factor;
    for (ll p = 2; p * p <= n; p++){
        if (n % p != 0) continue;
        ll exp = 0;
        while (n % p == 0){
            exp++;
            n /= p;
        }
        factor.push_back({p, exp});
    }
	if (n != 1) factor.push_back({n, 1});
	return factor;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> flag(MAX, true);
    for(int i = 0; i < N; i++){
        auto pf = prime_factorize(A[i]);
        for(auto [p, e]: pf){
            if(flag[p] == false) continue;
            for(int j = p; j <= M; j += p){
                flag[j] = false;
            }
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= M; i++){
        if(flag[i]) cnt++;
    }

    cout << cnt << endl;
    for(int i = 1; i <= M; i++){
        if(flag[i]) cout << i << endl;
    }
}