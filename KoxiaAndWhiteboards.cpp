#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,m; cin>>n>>m;
    map<int,int> st;
    int ans = 0;
    for(int i=0;i<n;i++){
        int k; cin>>k; st[k]++;
    }
    for(int i=0;i<m;i++){
        int k; cin>>k;
        auto [a,b] = *st.begin();
        st[a]--; st[k]++;
        if(!st[a])st.erase(a);
    }
    for(auto [a,b] : st){
        ans+=(a*b);
    }
    cout<<ans<<endl;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--)solve();
}