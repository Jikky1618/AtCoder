#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T>
T pow(T a, T n){
    T res = 1;
    while (n > 0){
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int K;
    cin >> K;
    string S, T;
    cin >> S >> T;

    // cnt[i] := 残りのiのカード枚数
    // cnt1[i] := 高橋くんの持ってるiのカード枚数
    // cnt2[i] := 青木くんの持ってるiのカード枚数
    vector<ll> cnt(10, K), cnt1(10), cnt2(10);
    for(auto c: S){
        if('0' <= c && c <= '9') cnt[c - '0']--, cnt1[c - '0']++;
    }
    for(auto c: T){
        if('0' <= c && c <= '9') cnt[c - '0']--, cnt2[c - '0']++;
    }

    ll sum = 0;
    // 青木くんの全パターンを列挙
    for(int i = 1; i <= 9; i++){
        // 青木くんの全パターンを列挙
        for(int j = 1; j <= 9; j++){
            ll p1 = 0, p2 = 0;
            for(int k = 1; k <= 9; k++){
                p1 += k * pow(10, cnt1[k] + (k == i));
                p2 += k * pow(10, cnt2[k] + (k == j));
            }

            if(p1 > p2){
                sum += cnt[i] * (cnt[j] - (i == j));
            }
        }
    }
    
    ll all = (ll)(9 * K - 8) * (9 * K - 9);

    double ans = (double)sum / all;
    cout << ans << endl;
}