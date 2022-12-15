#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int S, T, X;
    cin >> S >> T >> X;
    
    if(S < T){
        if(S <= X && X < T) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if(S <= X || X < T) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}