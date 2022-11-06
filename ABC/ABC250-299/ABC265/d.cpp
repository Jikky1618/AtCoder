#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    // p,q,r
    vector<ll> b(3);
    for(int i = 0; i < 3; i++) cin >> b[i];
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // 累積和
    vector<ll> s(n+1);
    for(int i = 0; i < n; i++) s[i+1] = s[i] + a[i];

    set<ll> st;
    for(int i = 0; i < n + 1; i++) st.insert(s[i]);

    for(int i = 0; i < n + 1; i++){
        ll sum = s[i];
        for(int j = 0; j < 3; j++){
            sum += b[j];
            if(!st.count(sum)) break;
            if(j == 2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}