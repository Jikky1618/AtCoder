#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

void solve(int N, vector<int> P){
    // 転倒数 mod 2 (不変量)が 1 なら, ソート不可能
    int inv = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(P[i] > P[j]) inv++;
        }
    }

    if(inv % 2 == 1){
        cout << "No" << endl;
        return;
    }

    // 前から貪欲に P を順列 Q にする
    vector<int> Q(N);
    iota(Q.begin(), Q.end(), 1);
    vector<pair<int, int>> ans;

    while(true){
        // 前から P[i] != Q[i] となる i を探す
        int pos = -1;
        for(int i = 0; i < N; i++){
            if(P[i] != Q[i]){
                pos = i;
                break;
            }
        }

        // pos == -1 なら P = Q となる
        if(pos == -1) break;

        // P[i] != Q[i] のとき, P[i] = Q[i] となる i を探す
        int pos2 = 0;
        for(int i = pos; i < N; i++){
            if(P[i] == Q[pos]){
                pos2 = i;
                break;
            }
        }

        // pos2 = N - 1 のときに注意
        /* 
            e.g. {1, 3, 4, 2}
            {1, 3, 4, 2}
            {1, 4, 2, 3}
            と {4, 2} を選んでソートする
        */
        if(pos2 == N - 1){
            P.insert(P.begin() + pos, P[pos2 - 1]);
            P.erase(P.begin() + pos2);
            P.insert(P.begin() + pos + 1, P[pos2]);
            P.erase(P.begin() + pos2 + 1);
            ans.emplace_back(pos2, pos);
            debug(P);
        }else{
            P.insert(P.begin() + pos, P[pos2]);
            P.erase(P.begin() + pos2 + 1);
            P.insert(P.begin() + pos + 1, P[pos2 + 1]);
            P.erase(P.begin() + pos2 + 2);
            ans.emplace_back(pos2 + 1, pos);
            debug(P);
        }
    }

    debug(ans);
    int M = ans.size();
    cout << "Yes" << "\n" << M << "\n";
    for(int i = 0; i < M; i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    solve(N, P);
}