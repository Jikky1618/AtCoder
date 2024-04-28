#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    string S;
    cin >> S;

    stack<char> st;
    for(int i = 0; i < N; i++){
        st.emplace(S[i]);
        while(st.size() >= 3){
            char c1 = st.top(); st.pop();
            char c2 = st.top(); st.pop();
            char c3 = st.top(); st.pop();
            if(c1 == 'x' && c2 == 'o' && c3 == 'f'){
                continue;
            }
            st.emplace(c3);
            st.emplace(c2);
            st.emplace(c1);
            break;
        }
    }
    cout << st.size() << endl;
}