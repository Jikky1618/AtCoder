#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, K;
    cin >> A >> B >> K;

    set<int> st;
    for(int i = 0; i < K; i++){
        if(A + i <= B) st.insert(A + i);
        if(B - i >= A) st.insert(B - i);
    }

    for(auto i: st) cout << i << endl;
    return 0;
}