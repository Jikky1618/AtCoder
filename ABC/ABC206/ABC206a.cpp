#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int ans = floor(1.08 * n);
    if(ans < 206) cout << "Yay!" << endl;
    else if(ans == 206) cout << "so-so" << endl;
    else cout << ":(" << endl;

    return 0;
}