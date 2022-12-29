#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    if(N <= 59){
        cout << "Bad" << endl;
    }else if(N <= 89){
        cout << "Good" << endl;
    }else if(N <= 99){
        cout << "Great" << endl;
    }else{
        cout << "Perfect" << endl;
    }
    return 0;
}