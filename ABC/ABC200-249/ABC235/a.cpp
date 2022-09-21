#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string str;
    cin >> str;

    int a = str[0] - '0';
    int b = str[1] - '0';
    int c = str[2] - '0';
    int ans = 111 * a + 111 * b + 111 * c;

    cout << ans << endl;

    return 0;
}