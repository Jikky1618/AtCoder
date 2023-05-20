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
    for(int i = 0; i < N; i++) cin >> A[i], A[i]--;

    // A のソート済(広義単調増加)数列 B を用意
    vector<int> B = A;
    sort(B.begin(), B.end());

    // i 番目の A[i], B[i] のcnt配列を用意
    vector cnt(4, vector<int>(4));
    for(int i = 0; i < N; i++){
        cnt[A[i]][B[i]]++;
    }

    int ans = 0;
    // 2つの相異なる数字をswap
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            // 2つが相異なる場合が条件
            if(i == j) continue;
            // x := swapする2組の個数
            int x = min(cnt[i][j], cnt[j][i]);
            ans += x;
            // それぞれ x 個ずつなくなる
            cnt[i][j] -= x;
            cnt[j][i] -= x;
        }
    }

    // 3つの相異なる数字をrotateしてswap
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                // 3つが相異なる場合が条件
                if(i == j || j == k || k == i) continue;
                // x := swapする3つの組の個数
                int x = min({cnt[i][j], cnt[j][k], cnt[k][i]});
                ans += x * 2; // swap回数は組数の2倍
                // それぞれ x 個ずつなくなる
                cnt[i][j] -= x;
                cnt[j][k] -= x;
                cnt[k][i] -= x;
            }
        }
    }

    // 4つの相異なる数字をrotateしてswap
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    // 4つが相異なることが条件
                    if(i == j || j == k || k == l || l == i || i == k || j == l) continue;
                    // x := swapする4つの組の個数
                    int x = min({cnt[i][j], cnt[j][k], cnt[k][l], cnt[l][i]});
                    ans += x * 3; // swap回数はそれの3倍
                    // それぞれ x 個ずつなくなる
                    cnt[i][j] -= x;
                    cnt[j][k] -= x;
                    cnt[k][l] -= x;
                    cnt[l][i] -= x;
                }
            }
        }
    }

    cout << ans << endl;
}