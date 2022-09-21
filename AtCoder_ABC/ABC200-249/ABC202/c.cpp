#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    
    long long int ans = 0;
    vector<int> count(n);
    for(int j = 0; j < n; j++){
        count[b[c[j] - 1]]++;
    }
    for(int i = 0; i < n; i++){
        ans += count[a[i]];
    }
    cout << ans << endl;

    return 0;
}