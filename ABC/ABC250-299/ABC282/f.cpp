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
    int N;
    cin >> N;

    vector<pair<int, int>> P;
    map<pair<int, int>, int> mp; // 区間 -> 区間番号
    int len = 1;
    while(len <= N){
        for(int i = 1; i + len - 1 <= N; i++){
            P.emplace_back(i, i + len - 1);
            mp[{i, i + len - 1}] = P.size();
        }
        len *= 2;
    }

    int M = P.size();
    cout << M << endl;
    for(auto [l, r]: P) cout << l << " " << r << endl;

    int Q;
    cin >> Q;
    while(Q--){
        int L, R; cin >> L >> R;
        len = 1;
        while(len * 2 <= R - L + 1) len = len * 2;
        int a = mp[{L, L + len - 1}], b = mp[{R - len + 1, R}];
        cout << a << " " << b << endl;
        debug(P[a - 1], P[b - 1]);
    }
}