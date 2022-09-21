#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    string str;

    for(int i = 0; i < 120; i++){
        if(n % 2 == 0){
            n /= 2;
            str += "B";
        }else{
            n--;
            str += "A";
        }
    }

    reverse(str.begin(), str.end());
    cout << str << endl;

    return 0;
}