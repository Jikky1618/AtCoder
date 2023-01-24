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
    vector<pair<int, int>> X(N);
    for(int i = 0; i < N; i++){
        cin >> X[i].first;
        X[i].second = i;
    }

    sort(X.begin(), X.end());
    vector<int> ans(N); // i番目のときの答えの値
    for(int i = 0; i < N; i++){
        if(i < N / 2) ans[X[i].second] = X[N / 2].first;
        else ans[X[i].second] = X[N / 2 - 1].first;
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
}