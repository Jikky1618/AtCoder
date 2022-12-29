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
    
    int sum = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        sum += A[i];
        if(A[i] != 0) cnt++;
    }
    
    cout << (sum + cnt - 1) / cnt << endl;
    return 0;
}