#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    k--;
    vector<int> p1(n), p2(n),p3(n);
    for(int i = 0; i < n; i++) cin >> p1[i] >> p2[i] >> p3[i];

    vector<int> s(n);
    for(int i = 0; i < n; i++) s[i] = p1[i] + p2[i] + p3[i];

    vector<int> tmp = s;
    sort(tmp.begin(), tmp.end(),greater<int>());

    for(int i = 0; i < n; i++){
        if(s[i] + 300 >= tmp[k]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}