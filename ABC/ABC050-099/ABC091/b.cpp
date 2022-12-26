#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<string> s(N);
    for(int i = 0; i < N; i++) cin >> s[i];
    int M;
    cin >> M;
    vector<string> t(M);
    for(int i = 0; i < M; i++) cin >> t[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        string S = s[i];
        int cnt = count(s.begin(), s.end(), S) - count(t.begin(), t.end(), S);
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}