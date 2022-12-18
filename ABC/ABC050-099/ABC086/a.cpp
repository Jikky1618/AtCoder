#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a, b;
    cin >> a >> b;

    if((a * b) % 2 == 0){
        cout << "Even" << endl;
    }else{
        cout << "Odd" << endl;
    }
    return 0;
}