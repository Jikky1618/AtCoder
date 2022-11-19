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
        for(int i = 0; i < n; i++){
            rotate(a.begin(),a.begin()+1,a.end());
            a.back() = 0;
        }
    }

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}