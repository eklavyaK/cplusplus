#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long double ld;
using namespace std;
const int N = 2e5+5;
int tree[N*4], arr[N];
void segmenttree(int l, int r, int node){
	if(l==r){
		tree[node] = arr[r];
		return;
	}
	int mid = (l+r)>>1;
	segmenttree(l,mid,2*node);
	segmenttree(mid+1,r,2*node+1);
	tree[node] = min(tree[2*node],tree[2*node+1]);
}
int query(int l, int r, int node, int st, int en){
	if(l>en || r<st)return LLONG_MAX;
	if(st<=l && r<=en) return tree[node];
	int mid = (l+r)>>1;
	return min(query(l,mid,2*node,st,en),query(mid+1,r,2*node+1,st,en));
}
void code(){
	int n,s; cin>>n>>s;
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		arr[i] = arr[i-1]+k;
	}
	segmenttree(1,n,1);
	int mx = 0, st = 0, en = 0;
	for(int i=1;i<=n;i++){
		if(arr[i]-arr[i-1]+s<0)continue;
		int l = i, r = n;
		while(l<=r){
			int mid = (l+r)>>1;
			int q = query(1,n,1,i,mid);
			if(q-arr[i-1]+s>=0)l=mid+1;
			else r = mid-1;
		}
		if(l-i>mx)mx = l-i, st = i, en = l-1;
	}
	if(!st && !en)cout<<-1<<endl;
	else cout<<st<<' '<<en<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}