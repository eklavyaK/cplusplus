#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

set<int> st;
void code(){
    int n,m; cin>>n>>m;
    if(n>m)cout<<0<<endl;
    else if(st.count(m))cout<<m+1<<endl;
    else{
        int now = 29, ans = 0;
        for(int i=29;i>=0;i--){
            if((1<<i)&m){
                if(!((1<<i)&n))ans+=(1<<i);
            }
            else{
                now=i;
                if((1<<i)&n){
                    cout<<ans<<endl;
                    return;
                }
            }
        }
        ans^=(1<<now);
        while(now--){
            if(ans&(1<<now))ans-=(1<<now);
        }
        cout<<ans<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int now = 0;
    for(int i=0;i<32;i++){
        st.insert(now);
        now += (1<<i);
    }
    int t; cin>>t; while(t--)code();
    return 0;
}