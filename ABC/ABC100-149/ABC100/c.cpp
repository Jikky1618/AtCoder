#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        while(a[i] % 2 == 0){
            a[i] /= 2;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}