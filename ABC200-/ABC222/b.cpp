#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,p;
    cin >> n >> p;

    int point,count = 0;
    for(int i = 0; i < n; i++){
        cin >> point;
        if(point < p) count++;
    }

    cout << count << endl;

    return 0;
}