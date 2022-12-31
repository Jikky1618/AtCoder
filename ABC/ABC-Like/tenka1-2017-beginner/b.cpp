#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    int ans = 0, max = 0;
    for(int i = 0; i < N; i++){
        if(max < A[i]){
            max = A[i], ans = A[i] + B[i];
        }
    }

    cout << ans << endl;
    return 0;
}