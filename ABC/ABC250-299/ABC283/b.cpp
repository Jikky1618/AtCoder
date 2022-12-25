#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    cin >> Q;
    
    while(Q--){
        int q; cin >> q;
        if(q == 1){
            int k, x; cin >> k >> x;
            A[k - 1] = x;
        }else{
            int k; cin >> k;
            cout << A[k - 1] << endl;
        }
    }
    return 0;
}