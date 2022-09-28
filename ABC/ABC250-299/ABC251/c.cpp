#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    for(int i = 0; i < n; i++) cin >> s[i] >> t[i];
    
    set<string> st;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int best = 0;
        // s[i]が集合stになかった場合
        if(st.find(s[i]) == st.end()){
            st.insert(s[i]);
            if(t[i] > best){
                best = t[i];
                ans = i + 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}