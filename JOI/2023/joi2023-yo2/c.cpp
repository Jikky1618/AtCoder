// point 32/100

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const vector<int> dx = {0,1,0,-1};
const vector<int> dy = {1,0,-1,0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int H, W;
    cin >> H >> W;
    assert(H <= 30 && W <= 30);
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }

    
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            for(int N = 1; N <= 5; N++){
                vector seen(H, vector<bool>(W, false));
                queue<pair<int, int>> que;

                seen[i][j] = true;
                que.push({i,j});

                // valをNに塗りつぶす
                int val = A[i][j];
                vector tmp = A; tmp[i][j] = N;
                while(!que.empty()){
                    auto pos = que.front(); que.pop();

                    for(int x = 0; x < 4; x++){
                        int nx = pos.first + dx[x];
                        int ny = pos.second + dy[x];
                        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                        if(seen[nx][ny]) continue;
                        if(A[nx][ny] != val) continue;
                        seen[nx][ny] = true;
                        tmp[nx][ny] = N;
                        que.push({nx, ny});
                    }
                }
                // cout << endl;
                // for(auto x: tmp){
                //     for(auto y: x){
                //         cout << y << " ";
                //     }
                //     cout << endl;
                // }
                int cnt = 1;
                for(int h = 0; h < H; h++){
                    for(int w = 0; w < W; w++){
                        seen[h][w] = false;
                    }
                }

                seen[i][j] = true;
                que.push({i,j});

                while(!que.empty()){
                    auto pos = que.front(); que.pop();

                    for(int x = 0; x < 4; x++){
                        int nx = pos.first + dx[x];
                        int ny = pos.second + dy[x];
                        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                        if(seen[nx][ny]) continue;
                        if(tmp[nx][ny] != N) continue;
                        seen[nx][ny] = true;
                        cnt++;
                        que.push({nx, ny});
                    }
                }

                ans = max(ans, cnt);
            }
        }
    }

    cout << ans << endl;
    return 0;
}