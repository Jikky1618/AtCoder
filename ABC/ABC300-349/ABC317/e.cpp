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
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for(int i = 0; i < H; i++) cin >> A[i];

    int sx = -1, sy = -1, gx = -1, gy = -1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == 'S') sx = i, sy = j;
            if(A[i][j] == 'G') gx = i, gy = j;
        }
    }

    vector out(H, vector<int>(W));
    // 視線に入るマスを調べる
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == '>'){
                int pos = j + 1;
                A[i][j] = '#';
                while(pos < W && A[i][pos] == '.'){
                    out[i][pos] = true;
                    pos++;
                }
            }
            if(A[i][j] == '<'){
                int pos = j - 1;
                A[i][j] = '#';
                while(0 <= pos && A[i][pos] == '.'){
                    out[i][pos] = true;
                    pos--;
                }
            }
            if(A[i][j] == 'v'){
                int pos = i + 1;
                A[i][j] = '#';
                while(pos < H && A[pos][j] == '.'){
                    out[pos][j] = true;
                    pos++;
                }
            }
            if(A[i][j] == '^'){
                int pos = i - 1;
                A[i][j] = '#';
                while(0 <= pos && A[pos][j] == '.'){
                    out[pos][j] = true;
                    pos--;
                }
            }
        }
    }

    vector dist(H, vector<int>(W, -1));
    dist[sx][sy] = 0;
    queue<pair<int, int>> que;
    que.emplace(sx, sy);
    while(!que.empty()){
        auto [x, y] = que.front();
        que.pop();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(dist[nx][ny] != -1) continue;
            if(out[nx][ny]) continue;
            if(A[nx][ny] == '#') continue;
            dist[nx][ny] = dist[x][y] + 1;
            que.emplace(nx, ny);
        }
    }
    
    cout << dist[gx][gy] << endl;
}