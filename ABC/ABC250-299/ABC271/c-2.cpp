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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    map<int, int> mp;
    for(int i = 0; i < N; i++) mp[A[i]]++;

    // どこまで読めるかを二分探索
    auto check = [&](int mid) -> bool {
        int cnt = 0; // 余計な本の数
        for(auto [key, val]: mp){
            // mid 以下の番号は最低1冊は必要
            if(key <= mid){
                if(2 <= val) cnt += (val - 1);
            // mid より大きい番号は読まない
            }else{
                if(1 <= val) cnt += val;
            }
        }

        cnt /= 2; // 余計な本2冊でない本1の代わり
        debug(mid, cnt);

        // mid まで読めるか判定
        for(int i = 1; i <= mid; i++){
            if(mp[i] == 0) cnt--;
        }

        return 0 <= cnt;
    };

    int ok = -1, ng = 3e5 + 1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    debug(ok, ng);
    cout << ok << endl;
}