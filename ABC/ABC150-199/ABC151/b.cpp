#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k,m;
    cin >> n >> k >> m;
    vector<int> a(n);
    for(int i = 1; i < n; i++) cin >> a[i];

    int sum = 0;
    for(int i = 1; i < n; i++) sum += a[i];

    for(int i = 0; i <= k; i++){
        int ave = (sum + i) / n;
        if(m <= ave){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    
    return 0;
}