#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MOD = 100000;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, K;
    cin >> N >> K;

    auto f = [&](ll n) -> ll { 
        ll res = 0;
        while(n){
            res += n % 10;
            n /= 10;
        }
        return res;
    };

    vector<int> flag(MOD + 1, -1); // 既に通った整数かどうかのフラグ
    vector<int> A; // 通ってきた整数
    ll cnt = 0, val = N;
    while(flag[val] == -1){
        A.push_back(val);
        flag[val] = cnt;
        cnt++;
        val += f(val), val %= MOD;
    }

    if(K < cnt){
        cout << A[K] << endl;
    }else{
        int cycle_cnt = cnt - flag[val]; // ループする周期の回数
        int start = flag[val]; // ループ開始時の回数
        int idx = start + (K - start) % cycle_cnt; // ループ開始時の回数 + ループする際の位置
        cout << A[idx] << endl;
    }
}