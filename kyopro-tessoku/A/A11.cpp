#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int l = 1, r = n,ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(x < a[mid]) r = mid - 1;
        if(x == a[mid]){ans = mid; break;}
        if(x > a[mid]) l = mid + 1;
    }

    cout << ans + 1 << endl;
    return 0;
}