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
    string S;
    cin >> S;

    int N = S.size();
    const int MOD = 2019;

    vector<int> cnt(MOD);
    cnt[0]++;

    int val = 0, d = 1;
    for(int i = N - 1; i >= 0; i--){
        val += (S[i] - '0') * d, val %= MOD;
        cnt[val]++;
        d *= 10, d %= MOD;
    }

    ll ans = 0;
    for(int i = 0; i < MOD; i++){
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << ans << endl;
}