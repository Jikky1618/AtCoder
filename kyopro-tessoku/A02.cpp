#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    bool found = false;
    for(int i = 0; i < n; i++){
        if(a[i] == x){
            found = true;
        }
    }

    if(found) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}