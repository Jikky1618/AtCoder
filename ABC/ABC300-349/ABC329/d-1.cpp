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
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i], A[i]--;
    // 票数, 番号
    vector<int> cnt(N);
    int ans = -1;
    for(int i = 0; i < M; i++){
        cnt[A[i]]++;
        if(cnt[ans] < cnt[A[i]]) ans = A[i]; 
        if(cnt[ans] == cnt[A[i]] && ans > A[i]) ans = A[i];
        cout << ans + 1 << '\n';
    }
}