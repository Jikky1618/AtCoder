#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    int ans = 0;

    for(int i = 0; i < 2; i++){
        if(a > b){
            ans += a;
            a--;
        }else{
            ans += b;
            b--;
        }
    }

    cout << ans << endl;
    return 0;
}