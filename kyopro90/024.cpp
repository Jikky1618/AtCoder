#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    int diff = 0;
    for(int i = 0; i < N; i++){
        diff += abs(A[i] - B[i]);
    }

    if(diff <= K && diff % 2 == K % 2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}