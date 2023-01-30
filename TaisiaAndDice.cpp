#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
	int n,s,r; cin>>n>>s>>r;
	cout<<s-r<<" ";
	int l = r/(n-1), k = r%(n-1);
	for(int i=1;i<n;i++){
		if(k){
			cout<<l+1<<' ';
			k--;
		}
		else cout<<l<<' ';
	}
	cout<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}