#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,m;
    ll t; // tはオーバーフローの可能性有
    cin >> n >> m >> t;
    vector<int> a(n);
    for(int i = 1; i < n; i++) cin >> a[i];
    vector<int> bonus(pow(10,5));
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        bonus[x] = y;
    }

    for(int i = 1; i < n; i++){
        if(t - a[i] <= 0){
            cout << "No" << endl;
            return 0;
        }
        t -= a[i];
        t += bonus[i+1];
    }

    cout << "Yes" << endl;

    return 0;
}