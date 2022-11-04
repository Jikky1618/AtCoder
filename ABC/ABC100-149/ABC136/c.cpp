#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    reverse(h.begin(), h.end());
    bool flag = true;
    for(int i = 0; i < n-1; i++){
        if(h[i] < h[i + 1] - 1) flag = false;
        else if(h[i] == h[i + 1] - 1) h[i + 1]--;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}