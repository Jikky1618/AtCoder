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
    string X;
    cin >> X;

    int N = X.size();
    vector<int> val(N);
    ll sum = 0;
    for(int i = 0; i < N; i++){
        sum += X[i] - '0';
        val[i] = sum;
    }

    vector<int> dig(N);
    vector<int> up(N);
    dig[N - 1] = val[N - 1] % 10;
    up[N - 1] = val[N - 1] / 10;
    for(int i = N - 2; i >= 1; i--){
        dig[i] = (val[i] + up[i + 1]) % 10;
        up[i] = (val[i] + up[i + 1]) / 10;
        debug(dig[i], val[i], up[i + 1]);
    }
    dig[0] = val[0] + up[1];

    string ans = "";
    for(auto d: dig) ans += to_string(d);

    cout << ans << endl;
}