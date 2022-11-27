#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    int ans = 0;
    while(1){
        // 終了条件
        if(*max_element(h.begin(), h.end()) == 0) break;
        // 区間を走査
        for(int i = 0; i < n; i++){
            // 0 ならなにもしない
            if(h[i] == 0) continue;
            // 区間分割開始
            ans++;
            // 区間の最後に到達 or 0 まで分割
            while(i < n && h[i] != 0){
                h[i]--;
                i++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}