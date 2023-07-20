#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    int N = S.size();

    auto p = rle(S);
    vector<int> ans;
    int M = p.size();

    for(int i = 0; i < M; i += 2){
        int R = p[i].second, L = p[i + 1].second, val = R + L;

        for(int j = 0; j < R - 1; j++) ans.emplace_back(0);
        ans.emplace_back((R + 1) / 2 + L / 2);
        ans.emplace_back((L + 1) / 2 + R / 2);
        for(int j = 0; j < L - 1; j++) ans.emplace_back(0);
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N - 1];
    }
}