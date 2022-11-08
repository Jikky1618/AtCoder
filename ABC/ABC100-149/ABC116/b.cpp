#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int s;
    cin >> s;
    vector<int> a(1000010);
    a[0] = s;

    for(int i = 1; i < 1000010; i++){
        if(a[i - 1] % 2 == 0) a[i] = a[i - 1] / 2;
        if(a[i - 1] % 2 == 1) a[i] = a[i - 1] * 3 + 1;
    }

    set<int> st;
    for(int i = 0; i < 1000010; i++){
        if(st.count(a[i])){
            cout << i + 1 << endl;
            return 0;
        }
        st.insert(a[i]);
    }

    return 0;
}