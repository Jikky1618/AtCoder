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

    vector<int> deg(N); // 次数
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b, a--, b--;
        deg[a]++, deg[b]++;
    }

    // 実験の結果, クエリを辺としたグラフで各頂点が全てサイクル or 次数が 0 なら YES
    // つまり, 次数が全て偶数なら YES
    bool flag = true;
    for(int i = 0; i < N; i++){
        if(deg[i] % 2 != 0) flag = false;
    }

    debug(deg);
    cout << (flag ? "YES" : "NO") << endl;
}