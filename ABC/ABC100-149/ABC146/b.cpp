#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i < s.size(); i++){
        int num = s[i] - 'A';
        s[i] = ((num + n) % 26) + 'A';
    }

    cout << s << endl;
    return 0;
}