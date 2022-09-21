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
    vector<int> l(q),r(q);
    for(int i = 0; i < q; i++) cin >> l[i] >> r[i];

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

    // Output
    for(int j = 0; j < q; j++){
        int ans1 = sum1[r[j]] - sum1[l[j] - 1]; 
        int ans2 = sum2[r[j]] - sum2[l[j] - 1];
        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}