#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string A, B;
    cin >> A >> B;

    if(A.size() != B.size()){
        cout << ((A.size() > B.size()) ? "GREATER" : "LESS") << endl;
        return 0;
    }

    int N = A.size();
    for(int i = 0; i < N; i++){
        if(A[i] != B[i]){
            if(A[i] - '0' > B[i] - '0'){
                cout << "GREATER" << endl;
            }else{
                cout << "LESS" << endl;
            }
            return 0;
        }
    }

    cout << "EQUAL" << endl;
    return 0;
}