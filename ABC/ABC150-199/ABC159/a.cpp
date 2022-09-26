#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;

    int ans = n * (n - 1) / 2 + m * (m - 1) / 2;

    cout <<ans << endl;
    
    return 0;
}