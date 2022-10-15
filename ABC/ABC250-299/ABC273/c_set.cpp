#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        st.insert(a[i]);
    }

    vector<int> fix_st;
    for(auto &i: st){
        fix_st.push_back(i);
    }

    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        auto itr = lower_bound(fix_st.begin(), fix_st.end(),a[i]);
        itr++;
        int cnt = distance(itr,fix_st.end());
        ans[cnt]++;
    }

    for(int k = 0; k < n; k++){
        cout << ans[k] << '\n';
    }
    return 0;
}