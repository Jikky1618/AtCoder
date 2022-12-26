#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int sum = 0;
    for(int i = 0; i < N; i++) sum += A[i];

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(sum <= A[i] * 4 * M) cnt++; 
    }

    if(M <= cnt) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}