#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> p(N);
    for(int i = 0; i < N; i++) cin >> p[i];

    set<int> st;
    for(int i = 0; i <= 200000; i++) st.insert(i);

    for(int i = 0; i < N; i++){
        st.erase(p[i]);
        cout << *st.begin() << endl;
    }
    return 0;
}