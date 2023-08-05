#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int K;
    cin >> K;

    int val = 7 % K, ans = -1;
    set<int> st;
    while(st.count(val) == 0){
        if(val == 0){
            cout << ans << endl;
            return 0;
        }
        st.insert(val);
        val = (val * 10 + 7) % K;
        ans++;
    }

    cout << -1 << endl;
    return 0;
}