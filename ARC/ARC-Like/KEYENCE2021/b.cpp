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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<int> cnt(N);
    for(int i = 0; i < N; i++) cnt[A[i]]++;

    vector<int> box(K, -1);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < min(cnt[i], K); j++){
            if(box[j] == i - 1) box[j]++;
        }
    }
    debug(box);

    int ans = 0;
    for(int i = 0; i < K; i++){
        ans += box[i] + 1;
    }

    cout << ans << endl;
}