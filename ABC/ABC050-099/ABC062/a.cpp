#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int x, y;
    cin >> x >> y;

    if(x == 2 || y == 2){
        cout << "No" << endl;
        return 0;
    }

    vector<int> A = {1,3,5,7,8,10,12}, B = {4,6,9,11};
    if((count(A.begin(), A.end(), x) && count(A.begin(), A.end(), y)) || (count(B.begin(), B.end(), x) && count(B.begin(), B.end(), y))){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}