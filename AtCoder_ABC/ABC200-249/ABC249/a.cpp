#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b,c,d,e,f,x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    
    int Takahashi = 0,Aoki = 0;
    for(int i = 0; i < x; i++){
        if(i % (a + c) < a) Takahashi += b;
        if(i % (d + f) < d) Aoki += e;
    }
    
    if(Takahashi > Aoki) cout << "Takahashi" << endl;
    else if(Takahashi < Aoki) cout << "Aoki" << endl;
    else cout << "Draw" << endl;

    return 0;
}