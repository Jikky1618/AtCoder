#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;

    if(c == 0){
        if(a > b) cout << "Takahashi" << endl;
        else cout << "Aoki" << endl;
    }else if(c == 1){
        if(b > a) cout << "Aoki" << endl;
        else cout << "Takahashi" << endl;
    }
    
    return 0;
}