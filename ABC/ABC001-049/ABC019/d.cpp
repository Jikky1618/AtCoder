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

    auto input = [&]() -> int {
        int dist;
        cin >> dist;
        return dist;
    };
    auto output = [&](int a, int b) -> void {
        assert(a != b);
        cout << "? " << a + 1 << " " << b + 1 << endl;
    };

    // 頂点 0 から最遠になる頂点は直径の端点
    pair<int, int> M = {0, 0}; // 頂点, 距離
    for(int i = 1; i < N; i++){
        output(0, i);
        int dist = input();
        if(M.second < dist){
            M.first = i, M.second = dist;
        }
    }
    // 端点から最も遠い点が答え
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(M.first == i) continue;
        output(M.first, i);
        int dist = input();
        ans = max(ans, dist);
    }

    cout << "! " << ans << endl;
}