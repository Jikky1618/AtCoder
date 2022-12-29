#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N, 0);
    while(Q--){
        int L, R, T; cin >> L >> R >> T;
        for(int i = L - 1; i < R; i++) A[i] = T;
    }

    for(int i = 0; i < N; i++) cout << A[i] << endl;
    return 0;
}