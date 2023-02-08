#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    int done[n+1]{};
    vector<int> u;
    for(int i=1;i<=n/2;i++){
        int k; cin>>k;
        u.push_back(k);
        done[k] = i;
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(!done[i]) v.push_back(i);
    }
    if(v.size()!=n/2){
        cout<<-1<<endl;
        return;
    }
    vector<int> temp = u;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n/2;i++){
        if(v[i]>temp[i]){
            cout<<-1<<endl;
            return;
        }
    }
    int tree[2*n+5];
    function<void(int,int,int)> sgtree = [&](int node, int l, int r){
        if(l==r){
            tree[node] = u[l];
            return;
        }
        int mid = (l+r)>>1;
        sgtree(2*node,l,mid);
        sgtree(2*node+1,mid+1,r);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    };
    function<void(int,int,int,int,int)> update = [&](int node, int l, int r, int idx, int val){
        if(l==r){
            tree[node] = val;
            return;
        }
        int mid = (l+r)>>1;
        if(idx<=mid) update(2*node,l,mid,idx,val);
        else update(2*node+1,mid+1,r,idx,val);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    };
    function<int(int,int,int,int,int)> query = [&](int node, int l, int r, int st, int en){
        if(st>r || l>en) return 0ll;
        if(st<=l && en>=r) return tree[node];
        int mid = (l+r)>>1;
        return max(query(2*node,l,mid,st,en),query(2*node+1,mid+1,r,st,en));
    };
    sgtree(1,0,n/2-1);
    vector<int> ans(n/2);
    vector<bool> vis(n/2);
    for(int i=n/2-1;i>=0;i--){
        int l = 0, r = n/2-1;
        while(l<=r){
            int mid = (l+r)>>1;
            if(query(1,0,n/2-1,mid,n/2-1)>v[i])l = mid+1;
            else r = mid-1;
        }
        ans[l-1] = v[i];
        update(1,0,n/2-1,l-1,0);
    }
    for(int i=0;i<n/2;i++)cout<<ans[i]<<' '<<u[i]<<' ';cout<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}