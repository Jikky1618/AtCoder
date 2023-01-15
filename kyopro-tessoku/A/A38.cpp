#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int D, N;
    cin >> D >> N;
    vector<int> L(N), R(N), H(N);
    for(int i = 0; i < N; i++) cin >> L[i] >> R[i] >> H[i], L[i]--, R[i]--;
    
    vector<int> Max(D, 24);
    for(int i = 0; i < N; i++){
        for(int j = L[i]; j <= R[i]; j++){
            Max[j] = min(Max[j], H[i]);
        }
    }

    int ans = 0;
    for(auto val: Max) ans += val;

    cout << ans << endl;
}