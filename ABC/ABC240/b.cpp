#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(a[i]);
    }

    cout << st.size() << endl;

    return 0;
}