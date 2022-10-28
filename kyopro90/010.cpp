#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    // Input
    int n;
    cin >> n;
    vector<int> c(n),p(n);
    for(int i = 0; i < n; i++) cin >> c[i] >> p[i];
    int q;
    cin >> q;

    // 累積和
    vector<int> sum1(n + 1),sum2(n + 1);
    for(int i = 0; i < n; i++){
        if(c[i] == 1){
            sum1[i + 1] = sum1[i] + p[i];
            sum2[i + 1] = sum2[i];
        }else{
            sum1[i + 1] = sum1[i];
            sum2[i + 1] = sum2[i] + p[i];
        }
    }

    // クエリ処理
    for(int j = 0; j < q; j++){
        int l,r; cin >> l >> r;
        l--; // 半開区間にするため調整
        int ans1 = sum1[r] - sum1[l]; 
        int ans2 = sum2[r] - sum2[l];
        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}