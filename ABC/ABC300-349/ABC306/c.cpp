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
    vector<int> A(3 * N);
    for(int i = 0; i < 3 * N; i++) cin >> A[i], A[i]--;

    vector<int> cnt(N);
    vector<int> f(N);
    for(int i = 0; i < 3 * N; i++){
        cnt[A[i]]++;
        if(cnt[A[i]] == 2) f[A[i]] = i + 1;
    }

    debug(f);
    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++){
        P[i].first = f[i];
        P[i].second = i + 1;
    }

    sort(P.begin(), P.end());
    for(int i = 0; i < N; i++){
        cout << P[i].second << " \n"[i == N - 1];
    }
}