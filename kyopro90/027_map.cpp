#include <bits/stdc++.h>
using namespace std;

int main(void){

    // Input
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    // Use map & Output
    map<string, int> map;
    for(int i = 0; i < n; i++){
        if(map[s[i]] == 0){
            map[s[i]] = 1;
            cout << (i + 1) << endl;
        }
    }

    return 0;
}