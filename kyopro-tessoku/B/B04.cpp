#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

ll to_dec(string n){
    ll res = 0;
    for(int i = 0; i < n.size(); i++){
        ll base = (1 << n.size() - 1 - i);
        ll d = n[i] - '0';
        res += base * d;
    }

    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string N;
    cin >> N;

    ll ans = to_dec(N);
    cout << ans << endl;
}