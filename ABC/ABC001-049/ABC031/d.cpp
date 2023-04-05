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
    int K, N;
    cin >> K >> N;
    vector<string> v(N), w(N);
    for(int i = 0; i < N; i++) cin >> v[i] >> w[i];

    // s1, s2 ,... の長さを3進数bit全探索で決定させる
    for(ll bit = 0; bit < pow(3, K); bit++){
        vector<int> len(K); // len[i] := s[i]の長さ
        for(int i = 0; i < K; i++) len[i] = ((bit / pow(3, i)) % 3) + 1;
        vector<string> ans(K, "");
        bool flag = false; // 条件を満たすかのflag
        for(int i = 0; i < N; i++){
            // 文字数が等しくなるか確認
            size_t sum = 0;
            for(auto c: v[i]) sum += len[c - '0' - 1];
            if(sum != w[i].size()) break; // 異なればbreak

            // 実際に文字列を分割
            string s = w[i];
            for(auto c: v[i]){
                int l = len[c - '0' - 1];
                string get = s.substr(0, l);
                // 矛盾が生じればbreak
                if(ans[c - '0' - 1] != "" && ans[c - '0' - 1] != get) break;
                ans[c - '0' - 1] = get;
                s = s.substr(l);
            }

            if(i == N - 1) flag = true; // 最後まで行けたら
        }
        if(flag){
            for(int i = 0; i < K; i++) cout << ans[i] << endl;
            return 0;
        }
    }
}