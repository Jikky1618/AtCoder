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
    vector<pair<ll, ll>> P(N);
    for(int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
    sort(P.begin(), P.end());

    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll pos = 0, time = 0, ans = 0;
    while(1){
        if(que.empty()){
            // もし, 全ての商品を追加したら終了
            if(pos == N) break;
            // 空なら次の商品の時間まで skip
            time = P[pos].first;
        }
        // 商品を追加する
        if(pos < N && P[pos].first == time){
            que.emplace(P[pos].first + P[pos].second);
            pos++;
            continue;
        }
        // もし, 区間内にあるなら印字する
        if(time <= que.top()) ans++, time++;
        que.pop();
    }

    cout << ans << endl;
}