#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int R;
    cin >> R;

    if(R < 1200){
        cout << "ABC" << endl;
    }else if(R < 2800){
        cout << "ARC" << endl;
    }else{
        cout << "AGC" << endl;
    }
    return 0;
}