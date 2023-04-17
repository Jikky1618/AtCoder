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
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<pair<ll, int>> imos;
    for(int i = 0; i < N; i++){
        imos.emplace_back(A[i], 1);
        imos.emplace_back(A[i] + B[i], -1);
    }

    int M = imos.size();
    sort(imos.begin(), imos.end());

    for(int i = 0; i < M - 1; i++){
        imos[i + 1].second += imos[i].second;
    }

    vector<ll> ans(N + 1);
    for(int i = 0; i < M - 1; i++){
        int val = imos[i].second;
        ans[val] += (imos[i + 1].first - imos[i].first);
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << " \n"[i == N];
    }
}