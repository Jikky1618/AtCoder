#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, K;
    cin >> A >> B >> K;
    
    for(int i = 0; i < K; i++){
        if(i % 2 == 0){
            if(A % 2 == 1) A--;
            int a = A / 2;
            A -= a, B += a;
        }else{
            if(B % 2 == 1) B--;
            int b = B / 2;
            B -= b, A += b;
        }
    }

    cout << A << " " << B << endl;
    return 0;
}