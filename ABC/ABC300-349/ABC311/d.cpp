#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    // seen[i][j] := {i, j} に 1 := 通過可能, 2 := 停止可能
    vector seen(N, vector<int>(M));
    queue<pair<int, int>> que;
    seen[1][1] = 2;
    que.emplace(1, 1);

    while(!que.empty()){
        auto [x, y] = que.front();
        que.pop();
        for(int k = 0; k < 4; k++){
            int nx = x, ny = y;
            while(1){
                if(S[nx + dx[k]][ny + dy[k]] == '#') break;
                nx += dx[k], ny += dy[k];
                if(seen[nx][ny] == 0) seen[nx][ny] = 1; // 通過可能
            }
            // もし、過去に停止していたら continue
            if(seen[nx][ny] == 2) continue;
            seen[nx][ny] = 2;
            que.emplace(nx, ny);
        }
    }

    debug(seen);
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(seen[i][j] != 0) ans++;
        }
    }

    cout << ans << endl;
}