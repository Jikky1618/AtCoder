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
    string S;
    cin >> N >> S;

    // w := 境目より左側にある W の個数
    // r := 境目より右側にある R の降雨
    int w = 0, r = 0;
    // 最初の境目は左端
    for(auto c: S) if(c == 'R') r++;

    int ans = max(w, r);
    // 境目の全探索
    for(auto c: S){
        // 境目を移動
        if(c == 'W') w++;
        if(c == 'R') r--;
        ans = min(ans, max(w, r));
    }

    cout << ans << endl;
}