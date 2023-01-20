#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll Max = 1e18;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    // find 0
    if(find(A.begin(), A.end(),0) != A.end()){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for(int  i = 0; i < N; i++){
        // find overflow
        if(Max / ans < A[i]){
            cout << -1 << endl;
            return 0;
        }
        ans *= A[i];
    }

    cout << ans << endl;
    
    return 0;
}