#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> d(N);
    for(int i = 0; i < N; i++) cin >> d[i];

    set<int> st;
    for(int i = 0; i < N; i++) st.insert(d[i]);

    cout << st.size() << endl;
    return 0;
}