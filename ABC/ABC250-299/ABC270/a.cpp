#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    vector<bool> prob(3);
    if(a == 1 || b == 1){prob[0] = true;}
    if(a == 2 || b == 2){prob[1] = true;}
    if(a == 3 || b == 3){prob[0] = true; prob[1] = true;}
    if(a == 4 || b == 4){prob[2] = true;}
    if(a == 5 || b == 5){prob[0] = true; prob[2] = true;}
    if(a == 6 || b == 6){prob[1] = true; prob[2] = true;}
    if(a == 7 || b == 7){prob[0] = true; prob[1] = true; prob[2] = true;}

    int point = 0;
    if(prob[0]) point += 1;
    if(prob[1]) point += 2;
    if(prob[2]) point += 4;

    cout << point << endl;

    return 0;
}