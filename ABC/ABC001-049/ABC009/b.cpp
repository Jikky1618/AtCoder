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

    sort(A.begin(), A.end(), greater<int>());
    A.erase(unique(A.begin(), A.end()), A.end());

    cout << A[1] << endl;
    return 0;
}