#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

constexpr int MAX = 1e6 + 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> cnt(MAX);
    for(int i = 0; i < N; i++) cnt[A[i]]++;

    vector<int> flag(MAX, true);
    for(int i = 0; i < MAX; i++){
        if(1 <= cnt[i]){
            if(2 <= cnt[i]) flag[i] = false; // 約数 = A[i]のとき
            for(int j = i * 2; j < MAX; j += i) flag[j] = false;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) if(flag[A[i]]) ans++;

    cout << ans << endl;
}