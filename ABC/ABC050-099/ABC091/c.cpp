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
    vector<pair<int, int>> R(N), B(N);
    for(int i = 0; i < N; i++) cin >> R[i].first >> R[i].second;
    for(int i = 0; i < N; i++) cin >> B[i].first >> B[i].second;

    sort(B.begin(), B.end()); // 青をxの昇順にソート
    sort(R.begin(), R.end(),[&](auto &a, auto &b){
        return a.second > b.second;
    }); // 赤をyの降順にソート

    int ans = 0;
    vector<int> usedR(N); // 赤い点が既にペアかを管理
    // 青の点を全探索
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(usedR[j]) continue;
            if(R[j].first < B[i].first && R[j].second < B[i].second){
                usedR[j] = true, ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}