#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    multiset<ll> L, R;

    ll ans = 0;
    auto push = [&](ll x) -> void {
        ans += x;
        L.insert(x);

        if(L.size() > K){
            ll val = *L.rbegin();
            ans -= val;
            R.insert(val);
            L.erase(L.find(val));
        }
    };

    auto pop = [&](ll x) -> void {
        if(L.count(x)){
            L.erase(L.find(x));
            ans -= x;
        }else{
            R.erase(R.find(x));
        }

        if(L.size() < K){
            ll val = *R.begin();
            ans += val;
            L.insert(val);
            R.erase(R.find(val));
        }
    };

    for(int i = 0; i < M; i++) push(A[i]);
    for(int i = 0; i < N - M + 1; i++){
        cout << ans << " \n"[i == N - M];
        if(i + M < N) push(A[i + M]), pop(A[i]);
    }
}