#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int day = 1,sum = 0;
    while(1){
        sum += day;
        if(sum >= n) break;
        day++;
    }
    cout << day << endl;

    return 0;
}