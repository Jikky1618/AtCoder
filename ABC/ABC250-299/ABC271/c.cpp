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

    int book = n,cnt = 1;
    while(1){
        if(st.count(cnt)){
            book -= 1;
        }else{
            book -= 2;
        }
        if(book <= 0) break;
        cnt++;
    }
    int ans = cnt - 1;
    cout << ans << endl;
    return 0;
}
