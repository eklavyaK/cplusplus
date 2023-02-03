#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k; cin>>n>>k;
    vector<int> p(2*n+1);
    for(int i=0;i<k;i++){
        int u,v; cin>>u>>v;
        p[u] = v; p[v] = u;
    }
    vector<int> v;
    for(int i=1;i<=2*n;i++){
        if(!p[i])v.push_back(i);
    }
    int m = v.size();
    for(int i=0;i<m/2;i++){
        p[v[i]] = v[m/2+i];
        p[v[m/2+i]] = v[i];
    }
    int ans = 0;
    for(int i=1;i<=2*n;i++){
        set<int> st;
        int k = i+1;
        if(k==2*n+1)k=1;
        while(k!=p[i]){
            if(st.count(k))ans--;
            else if(p[k]!=0)ans++,st.insert(p[k]);
            k++; if(k==2*n+1)k=1;
        }
    }
    cout<<ans/4<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}