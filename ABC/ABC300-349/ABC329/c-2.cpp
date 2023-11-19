#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<pair<char, int>> run_length_encodeing(const string& S) {
    vector<pair<char, int>> res;
    for (auto c : S) {
        if (!res.empty() && c == res.back().first) {
            res.back().second++;
        } else {
            res.emplace_back(c, 1);
        }
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    cin >> N >> S;
    auto R = run_length_encodeing(S);

    vector<int> cnt(26);
    for(auto [c, n] : R) cnt[c - 'a'] = max(cnt[c - 'a'], n);

    int ans = reduce(cnt.begin(), cnt.end(), 0);
    cout << ans << endl;
}