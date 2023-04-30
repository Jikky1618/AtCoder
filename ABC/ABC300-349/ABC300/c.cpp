#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<int> dx = {1, -1, 1, -1};
const vector<int> dy = {1, -1, -1, 1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int N = min(H, W);
    vector<int> ans(N + 1);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '.') continue; // 中心が.ならcontinue

            int cnt = 0;
            for(int k = 1; k < N; k++){
                bool flag = true;
                for(int d = 0; d < 4; d++){
                    int nx = i + dx[d] * k, ny = j + dy[d] * k;
                    if(nx < 0 || nx >= H || ny < 0 || ny >= W || S[nx][ny] == '.'){
                        flag = false;
                        break;
                    }
                }
                if(flag == false){
                    break;
                }
                cnt++;
            }

            ans[cnt]++;
        }
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << " \n"[i == N];
    }
}