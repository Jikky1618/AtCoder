#include <bits/stdc++.h>
using namespace std;

int main(void){

    // Input
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    // Use set & Output
    set<string> set;
    for(int i = 0; i < n; i++){
        if(!set.count(s[i])) cout << (i + 1) << endl;
        set.insert(s[i]);
    }

    return 0;
}