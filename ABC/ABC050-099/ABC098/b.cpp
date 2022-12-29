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

    int ans = 0;
    for(int i = 0; i < N; i++){
        set<char> st1, st2;
        for(int j = 0; j < i; j++) st1.insert(S[j]);
        for(int j = i; j < N; j++) st2.insert(S[j]);

        int cnt = 0;
        for(auto c: st1) if(st2.count(c)) cnt++;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}