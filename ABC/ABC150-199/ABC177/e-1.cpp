#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // setwise coprimeではないかどうかを判定
    int g = 0;
    for(int i = 0; i < N; i++) g = gcd(g, A[i]);

    if(g != 1){
        cout << "not coprime" << endl;
        return 0;
    }

    // pairwise coprimeかどうかを判定
    int cnt = 0;
    set<int> st;
    for(int i = 0; i < N; i++){
        auto pf = prime_factorize(A[i]);
        cnt += pf.size();
        for(auto [p, e]: pf){
            st.insert(p);
        }
    }

    if(cnt == st.size()){
        cout << "pairwise coprime" << endl;
    }else{
        cout << "setwise coprime" << endl;
    }
}