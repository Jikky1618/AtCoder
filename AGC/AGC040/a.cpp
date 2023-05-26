#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<pair<char, ll>> rle(const string& s){
    int n = s.size();
    vector<pair<char, ll>> res;
    ll cnt = 1;
    for(int i = 0; i < n; i++){
        if (i == n - 1 || s[i] != s[i + 1]){
            res.push_back({s[i], cnt});
            cnt = 1;
        }
        else cnt++;
    }
    return res;
}

ll sum(ll n){
    return n * (n + 1) / 2;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    int N = S.size();
    vector<int> val(N + 1);

    for(int i = 0; i < N; i++){
        if(S[i] == '<') val[i + 1] = max(val[i + 1], val[i] + 1);
    }
    for(int i = N - 1; i >= 0; i--){
        if(S[i] == '>') val[i] = max(val[i], val[i + 1] + 1);
    }

    ll ans = 0;
    for(int i = 0; i <= N; i++) ans += val[i];

    cout << ans << endl;
}