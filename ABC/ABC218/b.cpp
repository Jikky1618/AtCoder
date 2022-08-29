#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<int> order(26);
    for(int i = 0; i < 26; i++) cin >> order[i];

    string a = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < 26; i++){
        cout << a[order[i] - 1];
    }
    cout << endl;

    return 0;
}