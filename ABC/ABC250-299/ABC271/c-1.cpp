#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    set<int> st;
    for(int i = 0; i < n; i++) st.insert(a[i]);

    int ans = 0;
    for(int i = 1;; i++){
        if(st.count(i)) n -= 1; else n -= 2;
        if(n < 0) break;
        ans = i;
    }

    cout << ans << endl;
    return 0;
}
