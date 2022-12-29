#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string A;
    cin >> A;

    if(A == "a"){
        cout << -1 << endl;
    }else if(A.size() != 1){
        A.pop_back();
        cout << A << endl;
    }else if(A.size() == 1){
        cout << (char)(A.front() - 1) << endl;
    }
    return 0;
}