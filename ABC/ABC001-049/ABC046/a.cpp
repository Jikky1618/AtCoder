#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<int> A(3);
    for(int i = 0; i < 3; i++) cin >> A[i];
    
    set<int> st;
    for(int i = 0; i < 3; i++) st.insert(A[i]);

    cout << st.size() << endl;
    return 0;
}