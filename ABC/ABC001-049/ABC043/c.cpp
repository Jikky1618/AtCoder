#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    int Min = *min_element(a.begin(), a.end()), Max = *max_element(a.begin(), a.end());
    int ans = INF;
    for(int i = Min; i <= Max; i++){ // 同じにする整数を全探索
        int cost = 0;
        for(int j = 0; j < N; j++){
            cost += pow(a[j] - i, 2);
        }
        ans = min(ans, cost);
    }

    cout << ans << endl;
    return 0;
}