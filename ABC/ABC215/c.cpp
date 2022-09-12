#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    int k;
    cin >> s >> k;

    sort(s.begin(), s.end());
    while(k > 1){
        next_permutation(s.begin(), s.end());
        k--;
    }

    cout << s << endl;

    return 0;
}