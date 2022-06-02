#define rapid_iostream ios_base::sync_with_stdio(0);cin.tie(0)
#define binary(n,k) bitset<k>(n).to_string()
#include<bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define mod2 998244353ll
#define mod1 1000000007ll
#define print(n) cout<<n<<endl
typedef long long ll;
typedef long double ld;
using namespace std;
const int N=2e5;
ll tree[N*4], sum[N+5];
void segmentTree(int node, int l, int r){
    if(l==r){
        tree[node]=sum[l];
        return;
    }
    int mid = (l+r)/2;
    segmentTree(2*node,l,mid);
    segmentTree(2*node+1,mid+1,r);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
ll query(int node, int l, int r, int st, int en){
    if(en<l || st>r)return 1e15;
    if(st<=l && en>=r) return tree[node];
    int mid = (l+r)/2;
    return min(query(2*node,l,mid,st,en), query(2*node+1,mid+1,r,st,en));
}
int main(){
    rapid_iostream;

    int n; cin>>n;
    int arr[n];
    int a,b; cin>>a>>b;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sum[0]=arr[0];
    for(int i=1;i<n;i++){
        sum[i]=arr[i]+sum[i-1];
    }
    ll ans = sum[a-1];
    for(int i=a;i<b;i++){
        ans = max(sum[i],ans);
    }
    segmentTree(1,0,n-1);
    for(int i=a;i<n;i++){
        ll p = query(1,0,n-1,max(0,i-b),i-a);
        ans = max(ans,sum[i]-p);
    }
    cout<<ans;
    return 0;
}