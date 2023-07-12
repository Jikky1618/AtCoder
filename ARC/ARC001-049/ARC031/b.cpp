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
    vector<string> A(10);
    for(int i = 0; i < 10; i++) cin >> A[i];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // 陸地なら continue
            if(A[i][j] == 'o') continue;

            // BFS
            vector seen(10, vector<int>(10));
            queue<pair<int, int>> que;
            seen[i][j] = true;
            que.emplace(i, j);
            while(!que.empty()){
                auto [x, y] = que.front();
                que.pop();
                for(int k = 0; k < 4; k++){
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
                    if(A[nx][ny] == 'x') continue;
                    if(seen[nx][ny]) continue;
                    seen[nx][ny] = true;
                    que.emplace(nx, ny);
                }
            }

            if(i == 4 && j == 5) debug(seen);
            bool flag = true;
            for(int x = 0; x < 10; x++){
                for(int y = 0; y < 10; y++){
                    if(A[x][y] == 'o' && seen[x][y] == false) flag = false;
                }
            }

            if(flag){
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
}