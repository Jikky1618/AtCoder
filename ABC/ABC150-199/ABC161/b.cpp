#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int sum = 0;
    for(int i = 0; i < n; i++) sum += a[i];

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if((sum + (4 * m) - 1) / (4 * m) <= a[i]) cnt++;
    }

    if(m <= cnt){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}