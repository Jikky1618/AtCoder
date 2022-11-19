#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    string s;
    cin >> n >> s;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    vector<pair<int, char>> a(n);
    for(int i = 0; i < n; i++){
        a[i].first = w[i], a[i].second = s[i];
    }

    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++) if(a[i].second == '1') ans++;

    int cnt = ans;
    for(int i = 0; i < n; i++){
        if(a[i].second == '1') cnt--;
        else cnt++;
        // 重さが隣同士で変化がなければcontinue
        if(i < n - 1 && a[i].first == a[i + 1].first) continue;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}