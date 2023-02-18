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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    map<char, int> mp;
    for(char c = 'a'; c <= 'z'; c++) mp[c] = INF;
    for(auto s: S){
        map<char, int> cnt;
        for(auto c: s) cnt[c]++;
        for(char c = 'a'; c <= 'z'; c++) mp[c] = min(mp[c], cnt[c]);
    }

    string ans = "";
    for(auto [c, cnt]: mp){
        for(int i = 0; i < cnt; i++) ans += c;
    }

    cout << ans << endl;
}