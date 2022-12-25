#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    int N = S.size();
    int ans = 0;
    for(int i = 0; i < N; i++){
        // 00
        if(S[i] == '0' && S[i + 1] == '0') i++;
        ans++;
    }

    cout << ans << endl;
    return 0;
}