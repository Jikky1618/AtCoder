#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<int> dx = {0, 0, 1, -1, 0, 0};
const vector<int> dy = {1, -1, 0, 0, 0, 0};
const vector<int> dz = {0, 0, 0, 0, 1, -1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> x1(N), y1(N), z1(N), x2(N), y2(N), z2(N);
    for(int i = 0; i < N; i++) cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i];

    const int M = 101;
    // 1x1x1 のブロックで考える
    vector B(M, vector(M, vector<int>(M, -1)));
    // 各ブロックはどの直方体に含まれているかを調べる
    for(int i = 0; i < N; i++){
        for(int x = x1[i]; x < x2[i]; x++){
            for(int y = y1[i]; y < y2[i]; y++){
                for(int z = z1[i]; z < z2[i]; z++){
                    B[x][y][z] = i;
                }
            }
        }
    }

    // 各ブロックについて, 上下左右前後に違う番号のブロックがあるかどうかを調べる
    vector<set<int>> cnt(N);
    for(int x = 0; x < M; x++){
        for(int y = 0; y < M; y++){
            for(int z = 0; z < M; z++){
                if(B[x][y][z] == -1) continue;
                for(int i = 0; i < 6; i++){
                    int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
                    if(nx < 0 || nx >= M || ny < 0 || ny >= M || nz < 0 || nz >= M) continue;
                    if(B[nx][ny][nz] == -1) continue;
                    if(B[x][y][z] != B[nx][ny][nz]) cnt[B[x][y][z]].insert(B[nx][ny][nz]);
                }
            }
        }
    }
    debug(cnt);
    for(int i = 0; i < N; i++){
        cout << cnt[i].size() << '\n';
    }
}