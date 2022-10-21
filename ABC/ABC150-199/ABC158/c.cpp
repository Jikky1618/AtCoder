#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    int ans = -1;
    for(int i = 1; i <= 1000; i++){
        if(i * 8 / 100 == a && i / 10 == b){
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}