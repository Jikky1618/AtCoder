#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll all = 1, bad = 1;
    for(int i = 0; i < N; i++){
        if(A[i] % 2 == 0) bad *= 2;
        all *= 3;
    }
    cout << all - bad << endl;
    return 0;
}