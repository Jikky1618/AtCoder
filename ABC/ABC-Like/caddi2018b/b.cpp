#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, H, W;
    cin >> N >> H >> W;

    int ans = 0;
    for(int i = 0; i < N; i++){
        int A, B; cin >> A >> B;
        if(H <= A && W <= B) ans++;
    }

    cout << ans << endl;
    return 0;
}