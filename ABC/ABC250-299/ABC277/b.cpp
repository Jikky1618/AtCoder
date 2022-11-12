#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string a = "HDCS";
string b = "A23456789TJQK";
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    set<string> st;
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(!count(a.begin(), a.end(),s[i][0]) || !count(b.begin(),b.end(),s[i][1])) flag = false;
        st.insert(s[i]);
    }
    if(st.size() != n) flag = false;
    
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}