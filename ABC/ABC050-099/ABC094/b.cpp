#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i];

    int cost1 = 0, cost2 = 0;
    for(int i = X; i < N; i++){
        if(find(A.begin(), A.end(), i) != A.end()) cost1++;
    }
    for(int i = X; i >= 0; i--){
        if(find(A.begin(), A.end(), i) != A.end()) cost2++;
    }

    cout << min(cost1, cost2) << endl;
    return 0;
}