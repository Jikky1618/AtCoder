#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    //input
    int n,p,q;
    cin >> n >> p >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // 全探索 nC5
    ll count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            for(int k = 0; k < j; k++){
                for(int l = 0; l < k; l++){
                    for(int m = 0; m < l; m++){
                        if(1LL * a[i] * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q) count++;
                    }
                }
            }
        }
    }

    //Output
    cout << count << endl;

    return 0;
}