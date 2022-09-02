#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    string res = s[0];
    int max = 0;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(s[i] == s[j]) count++;
        }
        if(max < count){
            max = count;
            res = s[i];
        }
    }
    cout << res << endl;

    return 0;
}