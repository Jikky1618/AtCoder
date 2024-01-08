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
    int N, Q;
    cin >> N >> Q;
    
    // deque で管理
    deque<pair<ll, ll>> que;
    for(int i = 1; i <= N; i++) que.emplace_back(i, 0);

    while(Q--){
        int t; cin >> t;
        if(t == 1){
            char C; cin >> C;
            auto [x, y] = que.front();
            if(C == 'L') que.emplace_front(x - 1, y);
            if(C == 'R') que.emplace_front(x + 1, y);
            if(C == 'D') que.emplace_front(x, y - 1);
            if(C == 'U') que.emplace_front(x, y + 1);
            que.pop_back();
        }
        if(t == 2){
            int p; cin >> p, p--;
            auto [x, y] = que[p];
            cout << x << " " << y << '\n';
        }
    }
}