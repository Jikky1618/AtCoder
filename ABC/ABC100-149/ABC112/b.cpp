#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAX 10000

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,T;
    cin >> N >> T;
    vector<int> c(N), t(N);
    for(int i = 0; i < N; i++) cin >> c[i] >> t[i];

    int ans = MAX;
    for(int i = 0; i < N; i++){
        if(t[i] <= T){
            ans = min(ans, c[i]);
        }
    }
    
    if(ans == MAX) cout << "TLE" << endl;
    else cout << ans << endl;
    return 0;
}