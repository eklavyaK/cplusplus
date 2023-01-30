#include<bits/stdc++.h>
#define endl "\n"
#define int long long
typedef long double ld;
typedef long long ll;
using namespace std;

int query(int a,int b,int c){
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl<<flush;
	int k; cin>>k; return k;
}

void code(){
	int n,cnt=0; cin>>n;
	vector<bool> ans(n+1);
	int k = query(1,2,3);
	int l = 1, c = 0, r = 4;
	for(int i=2;i<=n-2;i++){
		c = query(i,i+1,i+2);
		if(k!=c){
			ans[i-1] = k;
			ans[i+2] = c;
			r = i+2; break;
		}
		else l = i;
	}
	for(int i=1;i<=n;i++){
		if(i==r||i==l)continue;
		query(l,r,i)==c?ans[i]=c:ans[i]=k;
	}
	cout<<"! "<<count(ans.begin()+1,ans.end(),0)<<" ";
	for(int i=1;i<=n;i++)if(!ans[i])cout<<i<<" ";
	cout<<endl<<flush;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}