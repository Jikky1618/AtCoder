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
    vector b(2, vector<int>(3)), c(3, vector<int>(2));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++) cin >> b[i][j];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++) cin >> c[i][j];
    }

    vector a(3, vector<int>(3, -1)); // 盤面を表す配列
    auto dfs = [&](auto&& self, int turn) -> int {
        // 9手目のとき, 直大くんの盤面の点数を返す
        if(turn == 9){
            int res = 0;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 3; j++){
                    if(a[i][j] == a[i + 1][j]){
                        res += b[i][j];
                    }
                }
            }
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 2; j++){
                    if(a[i][j] == a[i][j + 1]){
                        res += c[i][j];
                    }
                }
            }
            return res;
        }

        vector<int> next; // 次の盤面でありえる直大くんの点数
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(a[i][j] == -1){
                    a[i][j] = turn % 2; // 0なら直大くん、1なら直子さんのマス
                    next.push_back(self(self, turn + 1));
                    a[i][j] = -1; // バックトラック
                }
            }
        }
        if(turn % 2 == 0){
            // 直大くんのターンなら直大くんの点数を最大化したい
            return *max_element(next.begin(), next.end());
        }else{
            // 直子さんのターンなら直大くんの点数を最小化したい
            return *min_element(next.begin(), next.end());
        }
    };

    int ans = dfs(dfs, 0);
    int sum = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++) sum += b[i][j];
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++) sum += c[i][j];
    }

    cout << ans << endl;
    cout << sum - ans << endl;
}