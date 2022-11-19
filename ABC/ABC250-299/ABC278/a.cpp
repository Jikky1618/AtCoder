#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            if(j == n - 1) a[j] = 0;
            else a[j] = a[j + 1];
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}