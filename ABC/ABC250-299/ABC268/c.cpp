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
    int N;
    cin >> N;
    vector<int> p(N);
    for(int i = 0; i < N; i++) cin >> p[i];

    // 何回回したら何人喜ぶかのカウント用配列
    vector<int> cnt(N);
    for(int i = 0; i < N; i++){
        for(int j = -1; j <= 1; j++){
            // cnt回回すと、料理P[i]がiを喜ばせる配置になる
            cnt[(p[i] - i + j + N) % N]++;
        }
    }

    cout << *max_element(cnt.begin(), cnt.end()) << endl;

    return 0;
}