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
    int a, N;
    cin >> a >> N;

    int MAX = 1e6;

    vector<int> dist(MAX, -1);
    queue<int> que;
    dist[1] = 0;
    que.push(1);
    while(!que.empty()){
        ll x = que.front(); que.pop();

        // ax
        if(a * x < MAX){
            if(dist[a * x] != -1) continue;
            dist[a * x] = dist[x] + 1;
            que.push(a * x);
        }
        // 末尾を先頭に移動
        if(x % 10 != 0){
            string S = to_string(x);
            rotate(S.rbegin(), S.rbegin() + 1, S.rend());
            int nx = stoi(S);
            if(dist[nx] != -1) continue;
            dist[nx] = dist[x] + 1;
            que.push(nx);
        }
    }

    cout << dist[N] << endl;
}