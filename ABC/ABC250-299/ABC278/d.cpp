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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int Q;
    cin >> Q;

    ll base = 0;
    map<int, ll> mp;
    for(int i = 0; i < N; i++) mp[i] = A[i];

    while(Q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            base = x;
            mp.clear();
        }
        if(t == 2){
            int i, x; cin >> i >> x, i--;
            mp[i] += x;
        }
        if(t == 3){
            int i; cin >> i, i--;
            cout << mp[i] + base << '\n';
        }
    }
}