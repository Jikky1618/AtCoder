#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,k,a;
    cin >> n >> k >> a;

    int ans = a;
    for(int i = 0; i < k - 1; i++){
        if(ans >= n){
            ans = 1;
        }else{
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}