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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> a(Q), b(Q), c(Q), d(Q);
    for(int i = 0; i < Q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i], a[i]--, b[i]--;
    }

    int ans = 0;
    vector<int> A;
    auto dfs = [&](auto&& self, int pos, int last) -> void {
        if(pos == N){
            int point = 0;
            for(int i = 0; i < Q; i++){
                if(A[b[i]] - A[a[i]] == c[i]) point += d[i];
            }

            ans = max(ans, point);
            return;
        }

        for(int i = last; i <= M; i++){
            A.emplace_back(i);
            self(self, pos + 1, i);
            A.pop_back();
        }
    };

    dfs(dfs, 0, 1);
    cout << ans << endl;
}