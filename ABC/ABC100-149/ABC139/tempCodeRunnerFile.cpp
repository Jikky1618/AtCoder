#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    int ans = 0, cnt = 0;
    for(int i = 0; i < n - 1; i++){
        if(h[i] >= h[i + 1]) cnt++;
        else{
            ans = max(ans, cnt);
            cnt = 0;
        }
    }

    cout << ans << endl;
    return 0;
}