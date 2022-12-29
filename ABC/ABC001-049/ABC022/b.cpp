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

    int ans = 0;
    map<int, int> mp;
    for(int i = 0; i < N; i++){
        if(mp.count(A[i])) ans++;
        mp[A[i]]++;
    }

    cout << ans << endl;
    return 0;
}