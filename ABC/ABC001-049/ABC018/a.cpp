#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<int> A(3);
    for(int i = 0; i < 3; i++) cin >> A[i];

    vector<int> B = A;
    sort(B.begin(), B.end(), greater<int>());
    for(int i = 0; i < 3; i++){
        cout << find(B.begin(), B.end(), A[i]) - B.begin() + 1 << endl;
    }
    return 0;
}