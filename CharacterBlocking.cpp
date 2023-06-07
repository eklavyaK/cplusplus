#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
const int N = 2e5+5;
int tree[N*4];
void code(){
    string s[2];
    cin>>s[0]>>s[1];
    int t,q; 
    cin>>t>>q;
    function<void(int,int,int,int,int)> update = [&](int node, int l, int r, int x, int val){
        if(l==r){
            tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if(x<=mid) update(2*node,l,mid,x,val);
        else update(2*node+1,mid+1,r,x,val);
        tree[node]=tree[2*node]+tree[2*node+1];
    };
    function<int(int,int,int,int,int)> query = [&](int node, int l, int r, int st, int en){
        if(en<l || st>r)return 0ll;
        if(st<=l && en>=r) return tree[node];
        int mid = (l+r)/2;
        return query(2*node,l,mid,st,en)+query(2*node+1,mid+1,r,st,en);
    };
    int n = s[0].size();
    for(int i=0;i<n;i++){
        update(1,0,n-1,i,s[0][i]!=s[1][i]);
    }
    set<pair<int,int>> st;
    for(int i=0;i<q;i++){
        int type; cin>>type;
        if(type==1){
            int idx; cin>>idx;
            idx--;
            update(1,0,n-1,idx,0);
            st.insert({i,idx});
        }
        else if(type==2){
            int ida,idsa,idb,idsb;
            cin>>ida>>idsa>>idb>>idsb;
            ida--;idsa--;idb--;idsb--;
            swap(s[ida][idsa],s[idb][idsb]);
            update(1,0,n-1,idsa,s[0][idsa]!=s[1][idsa]);
            update(1,0,n-1,idsb,s[0][idsb]!=s[1][idsb]);
        }
        else{
            query(1,0,n-1,0,n-1)?cout<<"NO"<<endl:cout<<"YES"<<endl;
        }
        while(!st.empty()){
            auto [time,id] = *st.begin();
            if(i-time+1>=t){
                update(1,0,n-1,id,s[0][id]!=s[1][id]);
                st.erase({time,id});
            }
            else break;
        }
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}