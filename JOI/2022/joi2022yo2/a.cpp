#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;
    
    stack<string> S;
    for(int i = 0; i < Q; i++){
        string s; cin >> s;
        if(s == "READ"){
            cout << S.top() << endl;
            S.pop();
        }else{
            S.push(s);
        }
    }
    return 0;
}