#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    vector<int> l(q);
    for(int i = 0; i < q; i++) cin >> l[i];

    for(int i = 0; i < q; i++){
        if(a[l[i]-1] == n) continue;
        if(a[l[i]-1] + 1 == a[l[i]]) continue;
        a[l[i]-1]++;
    }
    
    for(int i = 0; i < k; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}