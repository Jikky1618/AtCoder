#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int,int> map;
    ll ans = 0;
    for(int j = 0; j < n; j++){
        ans += j - map[a[j]];
        map[a[j]]++;
    }
    cout << ans << endl;

    return 0;
}