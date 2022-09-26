#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,n;
    cin >> h >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];

    if(h <= sum) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}