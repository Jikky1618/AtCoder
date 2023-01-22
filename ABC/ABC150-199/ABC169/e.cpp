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

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    if(N % 2 == 1){
        int Min = A[N / 2];
        int Max = B[N / 2];
        cout << Max - Min + 1 << endl;
    }else{
        int Min = A[N / 2 - 1] + A[N / 2];
        int Max = B[N / 2 - 1] + B[N / 2];
        cout << Max - Min + 1 << endl;
    }
}