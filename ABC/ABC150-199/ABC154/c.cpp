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

    set<int> st(a.begin(), a.end());

    if(st.size() == a.size()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}