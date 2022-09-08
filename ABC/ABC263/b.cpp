#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 1; i < n; i++) cin >> p[i];

    int count = 0,Parent = -1,Child = n;
    while(Parent != 1){
        Parent = p[Child - 1];
        Child = Parent;
        count++;
    }

    cout << count << endl;

    return 0;
}