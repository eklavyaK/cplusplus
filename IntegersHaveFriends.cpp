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
    int arr[n], tree[n*4+5], a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n==1){
        cout<<1<<endl; return;
    }
    function<void(int,int,int)> segmenttree = [&](int l, int r, int node){
        if(l==r){
            tree[node] = arr[r];
            return;
        }
        int mid = (l+r)>>1;
        segmenttree(l,mid,2*node);
        segmenttree(mid+1,r,2*node+1);
        tree[node] = gcd(tree[2*node],tree[2*node+1]);
    };
    function<int(int,int,int,int,int)> query = [&](int l, int r, int node, int st, int en){
        if(st>r || en<l)return 0ll;
        else if(st<=l && en>=r)return tree[node];
        int mid = (l+r)>>1;
        return gcd(query(l,mid,2*node,st,en),query(mid+1,r,2*node+1,st,en));
    };
    for(int i=2;i<=n;i++){
        arr[i-1] = abs(a[i]-a[i-1]);
    }
    segmenttree(1,n-1,1);
    int ans = 1;
    for(int i=1;i<n;i++){
        if(arr[i]==1)continue;
        int l = 1, r = i;
        while(l<=r){
            int mid = (l+r)>>1;
            if(query(1,n-1,1,mid,i)!=1) r = mid-1;
            else l = mid+1;
        }
        ans = max(ans,i-r+1);
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}