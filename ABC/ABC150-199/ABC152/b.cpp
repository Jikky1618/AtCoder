#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    string s_a,s_b;
    for(int i = 0; i < a; i++) s_a.push_back(b + '0');
    for(int i = 0; i < b; i++) s_b.push_back(a + '0');

    if(s_a <= s_b) cout << s_a <<endl;
    else cout << s_b <<endl;

    return 0;
}