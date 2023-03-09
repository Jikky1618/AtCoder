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
    int N, K;
    cin >> N >> K;
    vector<int> C(N);
    for(int i = 0; i < N; i++) cin >> C[i];

    map<int, int> mp;
    for(int i = 0; i < K; i++) mp[C[i]]++;

    int ans = mp.size();
    for(int i = K; i < N; i++){
        debug(mp.size());
        mp[C[i]]++, mp[C[i - K]]--;
        if(mp[C[i - K]] == 0) mp.erase(C[i - K]);
        ans = max(ans, (int)mp.size());
    }

    cout << ans << endl;
}