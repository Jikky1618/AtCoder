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
    int N;
    cin >> N;
    vector A(N, vector<int>(5));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j++){
            cin >> A[i][j];
        }
    }

    auto check = [&](int mid) -> bool {
        // 各ステータスがmid以上かを0, 1の集合で管理する
        set<int> st;
        for(int i = 0; i < N; i++){
            int bit = 0;
            for(int j = 0; j < 5; j++){
                // A[i]のjのパラメータがmid以上なら
                if(A[i][j] >= mid){
                    // bitのj桁目を1にする
                    bit |= 1 << j;
                }
            }
            // 5つの判定を管理しているbitをstに入れる
            st.insert(bit);
        }
        // bitを全探索
        for(auto &&i: st){
            for(auto &&j: st){
                for(auto &&k: st){
                    // i, j, kの5つのステータスでmid以上のものが1つでもあるならtrue
                    if((i | j | k) == (1 << 5) - 1) return true;
                }
            }
        }
        return false;
    };

    // 二分探索
    int ok = -1, ng = 1e9 + 1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}