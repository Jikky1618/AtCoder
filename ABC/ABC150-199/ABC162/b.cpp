#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    ll sum = 0;
    for(int i = 1; i <= n; i++){ // 1~n
        if(i % 3 == 0 || i % 5 == 0) continue;
        else sum += i;
    }

    cout << sum << endl;

    return 0;
}