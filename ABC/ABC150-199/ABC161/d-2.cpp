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
    int K;
    cin >> K;

    // 時系列にそって単調増加なので、queueで可
    queue<ll> que;
    for(int i = 1; i < 10; i++) que.emplace(i);

    for(int i = 0; i < K - 1; i++){
        ll val = que.front(); que.pop();

        for(int j = -1; j <= 1; j++){
            int add = (val % 10) + j;
            if(0 <= add && add <= 9){
                que.emplace(val * 10 + add);
            }
        }
    }

    // K回目にfrontにくる値が答え
    cout << que.front() << endl;
}