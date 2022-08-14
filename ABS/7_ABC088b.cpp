#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    // sort(a.begin(), a.end(), greater< int >());
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    
    int Alice = 0, Bob = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            Alice += a[i];
        }else{
            Bob += a[i];
        }
    }
    cout << (Alice - Bob) << endl;
    
    return 0;
}