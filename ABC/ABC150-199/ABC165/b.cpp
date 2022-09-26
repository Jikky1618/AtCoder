#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll x;
    cin >> x;

    ll money = 100,day = 0;
    while(money < x){
        money += money / 100;
        day++;
    }

    cout << day << endl;

    return 0;
}