#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    sort(S.begin(), S.end());
    int ans = 0;
    for(auto&& s: S) ans += s;

    if(ans % 10 != 0){
        cout << ans << endl;
        return 0;
    }
    
    for(int i = 0; i < N; i++){
        if(S[i] % 10 != 0){
            ans -= S[i];
            cout << ans << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}