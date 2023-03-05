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
    int N, Q;
    cin >> N >> Q;
    
    vector<int> cnt(N);

    while(Q--){
        int t, x; cin >> t >> x, x--;
        if(t == 1) cnt[x]++;
        if(t == 2) cnt[x] += 2;
        if(t == 3) cout << (2 <= cnt[x] ? "Yes" : "No") << '\n';
    }
}