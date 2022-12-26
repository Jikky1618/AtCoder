#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    cin >> N >> S;

    int ans = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'I') cnt++;
        if(S[i] == 'D') cnt--;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}