#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    int cnt = 0;
    while(n){
        n /= k;
        cnt++;
    }

    cout << cnt << endl;
    
    return 0;
}