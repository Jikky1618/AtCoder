#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;
    int bad;
    for(int i = 0; i < n; i++){
        if(str[i] == '1'){
            bad = i;
            break;
        }
    }

    if(bad % 2 == 0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0; 
}