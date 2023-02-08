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
    int N, M;
    cin >> N >> M;
    set<pair<int, int>> st;
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b, a--, b--;
        st.insert({a, b});
    }

    auto check = [&]() -> bool {
        cout << "check" << endl;
        for(int i = 0; i < N; i++){
            if(st.count({0, i}) && st.count({i, N - 1})) return true;
        }
        return false;
    };

    cout << (check() ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}