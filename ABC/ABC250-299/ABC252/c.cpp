#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    int ans = INF;
    for(int i = 0; i <= 9; i++){
        vector<int> bucket(10);
        for(int j = 0; j < n; j++){
            for(int k = 0; k <= 9; k++){
                if(s[j][k] == i + '0') bucket[k]++;
            }
        }

        int cnt = 0;
        for(int j = 0; j < 10; j++){
            cnt = max(cnt, (bucket[j] - 1) * 10 + j);
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}