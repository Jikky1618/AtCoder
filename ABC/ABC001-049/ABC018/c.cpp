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
    int R, C, K;
    cin >> R >> C >> K;
    vector<string> S(R);
    for(int i = 0; i < R; i++) cin >> S[i];

    vector A(R, vector<int>(C));

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(S[i][j] == 'o') A[i][j] = 1;
        }
    }

    auto update = [&](vector<vector<int>> &a) -> void {
        vector res(R, vector<int>(C));
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                int val = a[i][j];
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx >= R || nx < 0 || ny >= C || ny < 0){
                        val = 0;
                        continue;
                    }
                    val &= a[nx][ny];
                }
                res[i][j] = val;
            }
        }
        a = res;
    };

    for(int i = 0; i < K - 1; i++){
        update(A);
    }

    int ans = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(A[i][j] == 1) ans++;
        }
    }

    cout << ans << endl;
}