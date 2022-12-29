#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> x(N), y(N), a(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> a[i];

    int x1 = 0, x2 = W, y1 = 0, y2 = H;
    for(int i = 0; i < N; i++){
        if(a[i] == 1) x1 = max(x1, x[i]);
        if(a[i] == 2) x2 = min(x2, x[i]);
        if(a[i] == 3) y1 = max(y1, y[i]);
        if(a[i] == 4) y2 = min(y2, y[i]);
    }
    cout << max(x2 - x1, 0) * max(y2 - y1, 0) << endl;
    return 0;
}