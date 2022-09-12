#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    set<int> st;
    unsigned int max = 0;
    for(int i = 0; i < n - k + 1; i++){
        for(int j = 0; j < k; j++){
            st.insert(c[i + j]);
        }
        if(max < st.size()) max = st.size();
    }

    cout << max << endl;

    return 0;
}