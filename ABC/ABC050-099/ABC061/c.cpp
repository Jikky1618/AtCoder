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
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> P(N);
    for(int i = 0; i < N; i++){
        cin >> P[i].first >> P[i].second;
    }

    sort(P.begin(), P.end());
    
    ll cnt = 0;
    for(int i = 0; i < N; i++){
        if(cnt + P[i].second < K){
            cnt += P[i].second;
        }else{
            cout << P[i].first << endl;
            return 0;
        }
    }
}