#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<int> flag(n);
    for(int i = 0; i < n; i++){
        for(int a = 1; a < 150; a++){
            for(int b = 1; b < 150; b++){
                if(4*a*b + 3*a + 3*b == s[i]){
                    flag[i] = 1;
                }
            }
        }
    }
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if(flag[i] == 0) count++;
    }

    cout << count << endl;

    return 0;
}