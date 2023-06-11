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

    vector<int> Edges;
    auto input = [&]() -> bool {
        string k; cin >> k;
        if(k == "OK") return false;

        int n = stoi(k);
        if(n == -1) return false;

        Edges.clear();
        for(int i = 0; i < n; i++){
            int v; cin >> v, v--;
            Edges.emplace_back(v);
        }
        return true;
    };

    auto output = [](int pos) -> void {
        cout << pos + 1 << endl;
    };

    vector<bool> seen(N);
    stack<int> stk;
    seen[0] = true;
    stk.emplace(0);

    int pos = 0;
    for(int i = 0; i < 2 * N; i++){
        // input
        string k; cin >> k;
        if(k == "OK") break;
        int n = stoi(k);
        vector<int> v;
        for(int j = 0; j < n; j++) cin >> v[j], v[j]--;

        // 次の頂点を探索
        int np = -1;
        for(auto e: v){
            if(seen[e]) continue;
            seen[e] = true;
            np = e;
            break;
        }

        // 次に行く頂点が見つからない場合
        if(np == -1){
            // 親の頂点に移動する
            stk.pop();
            np = stk.top();
        }else{
            // 頂点 np に移動する
            stk.emplace(np);
        }

        // output
        cout << np + 1 << endl;
        pos = np;
    }
}