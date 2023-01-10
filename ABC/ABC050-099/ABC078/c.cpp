#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;

    int t = 1900 * M + 100 * (N - M);
    int p = 1;
    for(int i = 0; i < M; i++) p *= 2;

    int ans = t * p;
    cout << ans << endl;
}