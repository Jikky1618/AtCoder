#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k; i++) cin >> b[i];

    int max = 0;
    for(int i = 0; i < n; i++){
        if(max < a[i]) max = a[i];
    }

    bool eat = false;
    for(int i = 0; i < k; i++){
        int bad = b[i] - 1;
        if(a[bad] == max){
            eat = true;
        }
    }

    if(eat) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}