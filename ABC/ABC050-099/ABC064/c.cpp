#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    set<int> st;
    int Min = 0;
    for(int i = 0; i < n; i++){
        if(2800 <= a[i]) st.insert(8);
        else st.insert(a[i] / 400);
    }
    Min = st.size();

    st.clear();
    int Max = 0;
    for(int i = 0; i < n; i++){
        if(3200 <= a[i]) Max++;
        else st.insert(a[i] / 400);
    }
    Max += st.size();

    cout << Min << " " << Max << endl;
    return 0;
}