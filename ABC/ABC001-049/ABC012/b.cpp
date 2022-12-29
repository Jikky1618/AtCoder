#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    
    int H = N / 3600;
    int M = N % 3600 / 60;
    int S = N % 60;
    
    printf("%02d:%02d:%02d\n", H, M, S);
    return 0;
}