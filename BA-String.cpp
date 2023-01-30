#include<bits/stdc++.h>
#define endl "\n"
#define int long long
typedef long double ld;
using namespace std;


void code(){
	int n,k; int x; 
	cin>>n>>k>>x;
	string s; cin>>s;
	if(s.find("*")==-1){
		cout<<s<<endl;
		return;
	}
	vector<int> c;
	for(int i=0;i<n;i++){
		if(s[i]=='a')continue;
		int cnt = 1;
		while(i+1<n && s[i+1]=='*')i++,cnt++;
		c.push_back(cnt*k+1);
	}
	int sz = c.size(),l=0;
	vector<int> prod(sz);
	prod[sz-1] = c[sz-1];
	for(int i=sz-2;i>=0;i--){
		if(ceil((ld)x/prod[i+1])<=c[i]){
			l = i; break;
		}
		else prod[i] = c[i]*prod[i+1];
	}
	//for(auto i : prod) cout<<i<<' ';cout<<endl;
	vector<int> ans(sz);
	for(int i=l;i<sz-1;i++){
		ans[i] = ceil((ld)x/prod[i+1])-1;
		x-=ans[i]*prod[i+1];
	}
	ans[sz-1] = x-1;
	l = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='a'){
			cout<<'a';
			continue;
		}
		cout<<string(max((int)0,ans[l++]),'b');
		while(i+1<n && s[i+1]=='*')i++;
	}
	cout<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int t; cin>>t; while(t--)code();
	return 0;
}