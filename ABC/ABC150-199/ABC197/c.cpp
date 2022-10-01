#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // 仕切りの配置をbit全探索
    int ans = INF;
    for(int bit = 0; bit < (1 << n); bit++){
        int XORed = 0, ORed = 0;
        for(int i = 0; i < n; i++){
            // 仕切りが来たらxor演算
            if((bit >> i) & 1){
                XORed ^= ORed;
                ORed = 0;
            }
            // 仕切りが来るまでor演算
            ORed |= a[i];
        }
        // 最後にもXOR演算(仕切り0の場合も含む)
        XORed ^= ORed;
        ans = min(ans, XORed);
    }

    cout << ans << endl;
    return 0;
}