#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    double A, B, C, D;
    cin >> A >> B >> C >> D;
    if(B / A == D / C){
        cout << "DRAW" << endl;
    }else if(B / A > D / C){
        cout << "TAKAHASHI" << endl;
    }else{
        cout << "AOKI" << endl;
    }
    return 0;
}