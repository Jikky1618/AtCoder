#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int> num(3);
    cin >> num[0] >> num[1] >> num[2];
    sort(num.begin(), num.end());
    if((num[0] + num[2]) / 2 == num[1]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}