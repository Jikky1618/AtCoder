#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        auto itr = lower_bound(a.begin(), a.end(), x); 
        cout << a.end() - itr << endl;
    }

    return 0;
}