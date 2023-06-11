#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    set<int> st;
    st.insert(10);
    st.insert(20);
    st.insert(30);
    st.insert(40);
    st.insert(50);
    cout<<*st.rbegin()<<endl;
    cout<<*st.rend()<<endl;
    cout<<*st.end()<<endl;
    cout<<*st.begin()<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}