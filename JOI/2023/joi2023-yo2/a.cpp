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

    int Max = *max_element(A.begin(), A.end()), Min = *min_element(A.begin(), A.end());
    for(int i = 0; i < N; i++){
        int ans = max(abs(A[i] - Min), abs(A[i] - Max));
        cout << ans << endl;
    }
    return 0;
}