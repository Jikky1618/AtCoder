#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, a, b, K;
    cin >> N >> a >> b >> K;
    vector<int> P(K);
    for(int i = 0; i < K; i++) cin >> P[i];

    set<int> st;
    st.insert(a), st.insert(b);
    for(int i = 0; i < K; i++) st.insert(P[i]);

    cout << (st.size() == K + 2 ? "YES" : "NO") << endl;
    return 0;
}