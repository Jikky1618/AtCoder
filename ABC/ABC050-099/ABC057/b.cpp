#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(N), c(M), d(M);
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < M; i++) cin >> c[i] >> d[i];

    for(int i = 0; i < N; i++){
        int Min = INF, ans = 0;
        for(int j = 0; j < M; j++){
            int dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if(dist < Min) Min = dist, ans = j + 1;
        }
        cout << ans << endl;
    }
    return 0;
}