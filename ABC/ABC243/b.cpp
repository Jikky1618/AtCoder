#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    int count_1 = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) count_1++;
    }
    int count_2 = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i] == b[j]) count_2++;
        }
    }
    count_2 -= count_1;

    cout << count_1 << endl << count_2 << endl; 

    return 0;
}