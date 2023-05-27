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
    vector<pair<int, int>> P(3);
    for(int i = 0; i < 3; i++){
        cin >> P[i].first >> P[i].second, P[i].first--, P[i].second--;
    }

    vector<int> cnt(4);
    for(int i = 0; i < 4; i++){
        auto [a, b] = P[i];
        cnt[a]++, cnt[b]++;
    }

    cout << (*max_element(cnt.begin(), cnt.end()) <= 2 ? "YES" : "NO") << endl;
}