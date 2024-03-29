#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    set<int> st;
    for(int i = 0; i < N; i++){
        if(st.count(A[i])){
            st.erase(A[i]);
        }else{
            st.insert(A[i]);
        }
    }

    cout << st.size() << endl;
}