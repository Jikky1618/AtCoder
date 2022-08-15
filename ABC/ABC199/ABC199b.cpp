#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end(), greater<int>()); // a[0] is maximum value
    sort(b.begin(), b.end()); // b[0] is minimum value

    cout << max(0,b[0] - a[0] + 1) << endl;

    return 0;
}