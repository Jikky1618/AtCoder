#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    bool can = true;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(b[i] == a[j]){
                a[j] = -1; // eaten
                b[i] = -1; // flag
            }
        }
        if(b[i] != -1) can = false;
    }

    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}