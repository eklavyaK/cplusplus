#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
const int inf = 1000000000000000000;
const int N = 3e5+10;
int tree[N*4], additional[N*4];

void code(){
    int n,k; cin>>n>>k;
    int arr[n],cold[k+1],hot[k+1], done[k+1]{};
    for(int i=1;i<=k*4+5;i++) tree[i] = additional[i] = 0;
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=1;i<=k;i++)cin>>cold[i];
    for(int i=1;i<=k;i++)cin>>hot[i];
    function<void(int,int,int,int,int,int)> update = [&](int node, int l, int r, int st, int en, int value){
        if(st>r || en<l || st>en) return;
        else if(st<=l && r<=en){
            tree[node]+=value;
            additional[node]+=value;
            return;
        }
        int mid = (l+r)>>1;
        update(2*node, l, mid, st, en, value);
        update(2*node+1, mid+1, r, st, en, value);
        tree[node] = min(tree[2*node],tree[2*node+1]);
    };
    function<int(int,int,int,int,int)> query = [&](int node, int l, int r, int st, int en){
        if(st>r || en<l || st>en) return inf;
        else if(st<=l && r<=en) return tree[node];
        int mid = (l+r)>>1;
        additional[2*node]+=additional[node];
        additional[2*node+1]+=additional[node];
        tree[2*node]+=additional[node];
        tree[2*node+1]+=additional[node];
        additional[node] = 0;
        //cout<<node<<endl;
        //for(int i=1;i<=5;i++)cout<<tree[i]<<' ';cout<<endl;
        int ansn = min(query(2*node, l, mid, st, en),query(2*node+1, mid+1, r, st, en));
        tree[node] = ansn;
        return tree[node];
    };
    update(1,0,k,0,k,cold[arr[0]]);
    update(1,0,k,arr[0],arr[0],inf-cold[arr[0]]);
    for(int i=0;i<=k;i++)cout<<query(1,0,k,i,i)<<' ';cout<<endl;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]) update(1,0,k,0,k,hot[arr[i]]);
        else{
            int mn = min({query(1,0,k,0,min(arr[i],arr[i-1])-1),query(1,0,k,min(arr[i],arr[i-1])+1,max(arr[i],arr[i-1])-1),query(1,0,k,max(arr[i],arr[i-1])+1,k)});
            for(int i=0;i<=k;i++)query(1,0,k,i,i);
            int u = query(1,0,k,arr[i],arr[i]);
            int v = query(1,0,k,arr[i-1],arr[i-1]);
            update(1,0,k,0,k,cold[arr[i]]);
            update(1,0,k,arr[i-1],arr[i-1],-v-cold[arr[i]]);
            update(1,0,k,arr[i-1],arr[i-1],min(mn+cold[arr[i]],u+hot[arr[i]]));
        }
        int v = query(1,0,k,arr[i],arr[i]);
        update(1,0,k,arr[i],arr[i],1e18-v);
        for(int i=0;i<=k;i++)cout<<query(1,0,k,i,i)<<' ';cout<<endl;
    }
    int ans = inf;
    for(int i=0;i<=k;i++){
        ans = min(ans,query(1,0,k,i,i));
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}