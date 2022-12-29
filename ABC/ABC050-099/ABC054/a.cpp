#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B;
    cin >> A >> B;

    if(A == B){
        cout << "Draw" << endl;
        return 0;
    }
    if(A == 1){
        cout << "Alice" << endl;
        return 0;
    }
    if(B == 1){
        cout << "Bob" << endl;
        return 0;
    }
    if(A < B){
        cout << "Bob" << endl;
        return 0;
    }
    if(A > B){
        cout << "Alice" << endl;
        return 0;
    }
    return 0;
}