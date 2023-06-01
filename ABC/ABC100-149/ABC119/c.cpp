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
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> l(N);
    for(int i = 0; i < N; i++) cin >> l[i];

    int ans = INF;
    auto dfs = [&](auto&& self, int pos, int a, int b, int c, int val) -> void {
        if(pos == N){
            if(min({a, b, c}) == 0) return;
            ans = min(ans, val + abs(A - a) + abs(B - b) + abs(C - c));
            return;
        }
        
        self(self, pos + 1, a, b, c, val);
        self(self, pos + 1, a + l[pos], b, c, val + (a ? 10 : 0));
        self(self, pos + 1, a, b + l[pos], c, val + (b ? 10 : 0));
        self(self, pos + 1, a, b, c + l[pos], val + (c ? 10 : 0));
    };

    dfs(dfs, 0, 0, 0, 0, 0);
    cout << ans << endl;
}