#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;
    vector<int> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];

    vector<set<int>> dat(N);
    for (int i = 0; i < N; i++) dat[i].insert(C[i]);
    while (Q--) {
        int a, b;
        cin >> a >> b, a--, b--;
        // b に a の要素を併合
        if (dat[a].size() > dat[b].size()) swap(dat[a], dat[b]);  // merge technique
        dat[b].merge(dat[a]);
        dat[a].clear();
        cout << dat[b].size() << '\n';
    }
}