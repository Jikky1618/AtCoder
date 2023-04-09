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
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // priority_queue解
    priority_queue<ll, vector<ll>, greater<ll>> que;
    que.emplace(0);
    int cnt = -1; // 操作回数
    ll pre = -1; // 前回の値
    while(true){
        ll x = que.top(); que.pop();
        if(pre == x) continue; // 前回と同じ値(重複)があればcontinue
        pre = x, cnt++;
        // もし回数がK回目ならそれが答え
        if(cnt == K){
            cout << x << endl;
            return 0;
        }
        // 次の値に遷移
        for(int i = 0; i < N; i++){
            que.emplace(x + A[i]);
        }
    }
}