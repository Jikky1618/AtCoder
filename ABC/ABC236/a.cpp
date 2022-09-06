#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    int a,b;
    cin >> s >> a >> b;

    swap(s[a-1],s[b-1]);

    cout << s << endl;

    return 0;
}