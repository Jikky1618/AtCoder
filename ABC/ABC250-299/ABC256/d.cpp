#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAX 200005

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(MAX + 1);
    for(int i = 0; i < n; i++){
        int l,r; cin >> l >> r;
        a[l]++, a[r]--;
    }
    for(int i = 0; i < MAX; i++) a[i + 1] += a[i];

    for(int i = 1; i < MAX; i++){
        if(a[i - 1] == 0 && a[i] != 0) cout << i << " ";
        if(a[i - 1] != 0 && a[i] == 0) cout << i << endl;
    } 

    return 0;
}