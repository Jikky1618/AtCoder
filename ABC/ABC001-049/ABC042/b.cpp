#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, L;
    cin >> N >> L;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    sort(S.begin(), S.end());
    
    for(auto s: S) cout << s;
    cout << endl;
    return 0;
}