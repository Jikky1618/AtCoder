#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= min(9,n); i++) ans++;
    for(int i = 100; i <= min(999,n); i++) ans++;
    for(int i = 10000; i <= min(99999,n); i++) ans++;

    cout << ans << endl;
    return 0;
}