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

    int l = -1, r = -1;
    for(int i = 0; i < MAX; i++){
        if(a[i] == 0 && a[i + 1] != 0) l = i + 1;
        if(a[i + 1] == 0 && a[i] != 0) r = i + 1;
        if(l != -1 && r != -1){
            cout << l << " " << r << endl;
            l = -1, r = -1;
        } 
    }

    return 0;
}