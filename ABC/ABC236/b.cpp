#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(4 * n);
    for(int i = 0; i < 4 * n - 1; i++) cin >> a[i];

    vector<int> flag(n + 1);
    for(int i = 0; i < 4 * n; i++){
        flag[a[i]]++;
    }

    for(int i = 0; i <= n; i++){
        if(flag[i] == 3) cout << i << endl; 
    }


    return 0;
}