#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(q);
    for(int i = 0; i < q; i++) cin >> a[i];

    vector<int> p(n);
    for(int i = 0; i < q; i++){
        p[a[i] - 1]++;
    }

    for(int i = 0; i < n; i++){
        if(k - q + p[i] > 0) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

    return 0;
}