#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> p(N);
    for(int i = 0; i < N; i++) cin >> p[i];

    int ans = 0;
    vector<int> cnt(201000);
    for(int i = 0; i < N; i++){
        cnt[p[i]]++;

        while(cnt[ans]) ans++;
        cout << ans << endl;
    }
    return 0;
}