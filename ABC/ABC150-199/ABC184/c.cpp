#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(){
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    // 0手
    if(r1 == r2 && c1 == c2) return 0;
    // 1手
    if(r1+c1 == r2+c2 || r1-c1 == r2-c2 || abs(r1-r2)+abs(c1-c2) <= 3) return 1;
    // 2手
    if((r1+c1) % 2 == (r2+c2) % 2) return 2; // A+B
    if(abs((r1+c1)-(r2+c2)) <= 3) return 2; // A+C
    if(abs((r1-c1)-(r2-c2)) <= 3) return 2; // B+C
    if(abs(r1-r2)+abs(c1-c2) <= 6) return 2; // C+C
    // 3手
    return 3;
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cout << solve() << endl;
    return 0;
}