#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    vector<queue<int>> A(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++){
            int a; cin >> a, a--;
            A[i].emplace(a);
        }
    }
    debug(A);
    // 各選手の対戦相手を前から見ていく
    vector<int> day(N, INF);
    queue<tuple<int, int, int>> que;
    for(int i = 0; i < N; i++){
        int j = A[i].front();
        // j の対戦相手が i なら que に入れる(j, i の重複を避ける為 i < j)
        if(i < j && A[j].front() == i) que.emplace(i, j, 1);
    }

    while(!que.empty()){
        auto [a, b, d] = que.front(); que.pop();
        debug(a, b, d);
        // a, b について新しく対戦相手を見つける
        for(auto i: {a, b}){
            A[i].pop();
            if(!A[i].empty()){
                int j = A[i].front();
                if(A[j].front() == i) que.emplace(i, j, d + 1);
            }else{
                // i の対戦相手がいなくなったら day[i] を更新
                day[i] = d;
            }
        }
    }
    debug(day);
    int ans = *max_element(day.begin(), day.end());
    cout << (ans == INF ? -1 : ans) << '\n';
}