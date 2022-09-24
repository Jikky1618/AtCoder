#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;
    for(int i = 0; i  < n; i++){
        ans += a[i] * b[i];
    }
    if(ans == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}