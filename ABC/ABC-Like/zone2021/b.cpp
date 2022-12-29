#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, D, H;
    cin >> N >> D >> H;
    vector<double> d(N), h(N);
    for(int i = 0; i < N; i++) cin >> d[i] >> h[i];

    double ans = 0;
    for(int i = 0; i < N; i++){
        // 遮蔽物とUFOの2点の直線のx切片の最大
        ans = max(ans, H - (H - h[i]) / (D - d[i]) * D);
    }

    cout << ans << endl;
    return 0;
}